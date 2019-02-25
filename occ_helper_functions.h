#ifndef OCC_HELPER_FUNCTIONS_H
#define OCC_HELPER_FUNCTIONS_H


#include <V3d_View.hxx>
#include <ProjLib.hxx>
#include <ElSLib.hxx>
#include <V3d_Coordinate.hxx>
#include <GC_MakeLine.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <TopoDS.hxx>
#include <GeomAPI_IntCS.hxx>
#include <BRepClass_FaceClassifier.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <QPoint>
#include <math.h>



gp_Pnt ConvertClickToPoint(Standard_Real x, Standard_Real y, Handle(V3d_View) aView)
{
    Standard_Real XEye,YEye,ZEye,XAt,YAt,ZAt;
    aView->Eye(XEye,YEye,ZEye);
    aView->At(XAt,YAt,ZAt);
    gp_Pnt EyePoint(XEye,YEye,ZEye);
    gp_Pnt AtPoint(XAt,YAt,ZAt);

    gp_Vec EyeVector(EyePoint,AtPoint);
    gp_Dir EyeDir(EyeVector);

    gp_Pln PlaneOfTheView = gp_Pln(AtPoint,EyeDir);
    Standard_Real X,Y,Z;
    aView->Convert(int(x),int(y),X,Y,Z);
    gp_Pnt ConvertedPoint(X,Y,Z);
    gp_Pnt2d ConvertedPointOnPlane = ProjLib::Project(PlaneOfTheView,ConvertedPoint);

    gp_Pnt ResultPoint = ElSLib::Value(ConvertedPointOnPlane.X(),
                                    ConvertedPointOnPlane.Y(),
                                    PlaneOfTheView);
    return ResultPoint;
}

gp_Pnt to_3d_point (Standard_Integer x, Standard_Integer y,const Handle_V3d_View& view)
{
assert (!view.IsNull ());//view_not_null

// Make a plane perpendicular to the projection orientation.
Standard_Real x_ori, y_ori, z_ori;
view->Proj (x_ori, y_ori, z_ori);
gp_Dir proj_orientation (x_ori, y_ori, z_ori);
gp_Pln view_plane = gp_Pln (gp_Pnt (0, 0, 0), proj_orientation);
// Convert the 2d point into a 3d point.
Standard_Real xp, yp, zp;
view->Convert (x, y, xp, yp, zp);
gp_Pnt converted_pnt (xp, yp, zp);
// Project the converted point in the plane.
gp_Pnt2d projected_pnt = ProjLib::Project (view_plane, converted_pnt);
// Get a 3d point from this 2d point.
return ElSLib::Value (projected_pnt.X (), projected_pnt.Y (), view_plane);
}

gp_Pnt PickPoint(Handle_V3d_View aView, TopoDS_Shape myShape, long x, long y)
{
    V3d_Coordinate xEye, yEye, zEye, xAt, yAt, zAt;
    gp_Pnt resultPoint;

    aView->Eye(xEye, yEye, zEye);
    aView->At(xAt, yAt, zAt);
    gp_Pnt EyePoint(xEye, yEye, zEye);
    gp_Pnt AtPoint(xAt, yAt, zAt);

    gp_Vec EyeVector(EyePoint, AtPoint);
    gp_Dir EyeDir(EyeVector);

    gp_Pln PlaneOfView = gp_Pln(AtPoint, EyeDir);

    Standard_Real theX, theY, theZ;
    aView->Convert(x, y, theX, theY, theZ);
    gp_Pnt ConvertedPoint(theX, theY, theZ);

    gp_Pnt2d ConvertedPointOnPlane = ProjLib::Project(PlaneOfView, ConvertedPoint);

    gp_Pnt shapePoint = ElSLib::Value(ConvertedPointOnPlane.X(), ConvertedPointOnPlane.Y(), PlaneOfView);
    resultPoint = shapePoint;

    GC_MakeLine line(EyePoint, shapePoint);
    TopExp_Explorer exp;
    TopAbs_State aState;


    int iii = 0;
    for (exp.Init(myShape, TopAbs_FACE); exp.More(); exp.Next())
    {
        TopoDS_Face face = TopoDS::Face(exp.Current());
        BRepAdaptor_Surface surface(face);
        const GeomAdaptor_Surface& geomAdapSurf = surface.Surface();
        const Handle(Geom_Surface)& geomSurf = geomAdapSurf.Surface();

        GeomAPI_IntCS inCS;
        inCS.Perform(line.Value(), geomSurf);
        if (inCS.IsDone())
        {
            if (inCS.NbPoints() != 0)
            {
                shapePoint = gp_Pnt(inCS.Point(1).XYZ());

                ShapeAnalysis_Surface shapeAnalysis(geomSurf);
                gp_Pnt2d shapePoint2D = shapeAnalysis.ValueOfUV(shapePoint, Precision::Confusion());
                BRepClass_FaceClassifier aClassifier(face, shapePoint2D, Precision::Confusion());
                aState = aClassifier.State();
                if ((aState == TopAbs_ON) || (aState == TopAbs_IN))
                {
                    if (resultPoint.Distance(EyePoint) > shapePoint.Distance(shapePoint))
                    {
                        resultPoint = shapePoint;
                    }
                }
            }
        }
    }
    return resultPoint;
}

bool is_point_near(gp_Pnt p1,gp_Pnt p2,int tolerance)
{
    double distt = (static_cast<void>(pow((p2.X()-p1.X()),2)+pow((p2.Y()-p1.Y()),2)),pow((p2.Z()-p1.Z()),2));
    double dist = sqrt(distt);
    if (dist <= tolerance) return true; else return false;

}












#endif // OCC_HELPER_FUNCTIONS_H
