
#include <GeomAPI_IntCS.hxx>
#include <GC_MakeLine.hxx>
#include <ElSLib.hxx>
#include <ProjLib.hxx>
#include <BRepOffsetAPI_MakePipe.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_Plane.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_ConicalSurface.hxx>
#include <Geom_SphericalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_OffsetSurface.hxx>
#include <GeomToIGES_GeomSurface.hxx>
#include <BRepTools.hxx>
#include <Standard_DefineHandle.hxx>
#include <DsgPrs_LengthPresentation.hxx>
#include <GCPnts_TangentialDeflection.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Geom_CartesianPoint.hxx>
#include <Geom_Line.hxx>
#include <Geom_Surface.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <GeomAbs_CurveType.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomTools_Curve2dSet.hxx>
#include <gp_Vec.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <MMgt_TShared.hxx>
#include <OSD_Environment.hxx>
#include <Precision.hxx>
#include <Prs3d_IsoAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_Projector.hxx>
#include <Prs3d_Text.hxx>
#include <Quantity_Factor.hxx>
#include <Quantity_Length.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Quantity_PhysicalQuantity.hxx>
#include <Quantity_PlaneAngle.hxx>
#include <Quantity_TypeOfColor.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <SelectMgr_Filter.hxx>
#include <StdSelect_EdgeFilter.hxx>
#include <StdSelect_ShapeTypeFilter.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_CString.hxx>
#include <Standard_ErrorHandler.hxx>
#include <Standard_Integer.hxx>
#include <Standard_IStream.hxx>
#include <Standard_Macro.hxx>
#include <Standard_NotImplemented.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Real.hxx>
#include <StdPrs_Curve.hxx>
#include <StdPrs_Point.hxx>
#include <StdPrs_PoleCurve.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TColStd_MapIteratorOfMapOfTransient.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopExp.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <UnitsAPI.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>
#include <WNT_Window.hxx>
#include <Prs3d_PointAspect.hxx>
#include <AIS_Point.hxx>
#include <BRep_Tool.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepBuilderAPI_Copy.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepLib.hxx>
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepFeat_SplitShape.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeSegment.hxx>
#include <GC_MakeCircle.hxx>
#include <GCE2d_MakeSegment.hxx>
#include <gp.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Surface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>
#include <GCPnts_AbscissaPoint.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GeomLib.hxx>
#include <GeomConvert_CompCurveToBSplineCurve.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <TopTools_IndexedDataMapOfShapeAddress.hxx>
#include <V3d_PositionalLight.hxx>
#include <V3d_DirectionalLight.hxx>
#include <V3d_AmbientLight.hxx>
#include <IGESControl_Controller.hxx>
#include <IGESControl_Writer.hxx>
#include <Interface_Static.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Xw_Window.hxx>
#include <V3d_View.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <WNT_Window.hxx>
#include <AIS_InteractiveContext.hxx>
#include <TopoDS_Shape.hxx>
#include <AIS_Shape.hxx>
#include <BRepAlgo.hxx>
#include <BRepAlgo_Common.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Algo.hxx>
#include <BRep_Tool.hxx>

#include <BRepAlgoAPI_Fuse.hxx>

#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_Transform.hxx>

#include <BRepFilletAPI_MakeFillet.hxx>

#include <BRepLib.hxx>

#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>

#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakePrism.hxx>

#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeSegment.hxx>

#include <GCE2d_MakeSegment.hxx>

#include <gp.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

#include <Geom_CylindricalSurface.hxx>
#include <Geom_Plane.hxx>
#include <Geom_Surface.hxx>
#include <Geom_TrimmedCurve.hxx>

#include <Geom2d_Ellipse.hxx>
#include <Geom2d_TrimmedCurve.hxx>

#include <TopExp_Explorer.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Compound.hxx>

#include <TopTools_ListOfShape.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <BRepClass_FaceClassifier.hxx>
#include <V3d_Coordinate.hxx>
#include <BRepOffsetAPI_MakePipeShell.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <StdSelect_FaceFilter.hxx>
#include <Standard_PrimitiveTypes.hxx>
#include <GProp_GProps.hxx>
#include <BRepGProp.hxx>
#include <Law_Linear.hxx>
 #include <GeomToStep_MakeCartesianPoint.hxx>
 #include <GeomToStep_MakePolyline.hxx>
 #include <gp_Pnt.hxx>
 #include <gp_Pnt2d.hxx>
 #include <StdFail_NotDone.hxx>
 #include <StepGeom_HArray1OfCartesianPoint.hxx>
 #include <StepGeom_Polyline.hxx>
 #include <TColgp_Array1OfPnt.hxx>
 #include <TColgp_Array1OfPnt2d.hxx>
 #include <TCollection_HAsciiString.hxx>
 #include <Geom_BezierCurve.hxx>
 #include <TColgp_Array1OfPnt.hxx>
 #include <GeomFill_Pipe.hxx>
 #include <Geom_Surface.hxx>
 #include <TColgp_Array1OfPnt2d.hxx>
 #include <Geom2d_BezierCurve.hxx>
 #include <TColgp_Array2OfPnt.hxx>
 #include <Geom_BezierSurface.hxx>
 #include <Geom2dAdaptor_HCurve.hxx>
 #include <GeomAdaptor_HSurface.hxx>
 #include <Approx_CurveOnSurface.hxx>
 #include <TopoDS_Wire.hxx>
 #include <TopoDS_Edge.hxx>
 #include <BRepBuilderAPI_MakeEdge.hxx>
 #include <BRepBuilderAPI_MakeWire.hxx>
 #include <BRepOffsetAPI_MakePipe.hxx>
 #include <BRepOffsetAPI_MakePipeShell.hxx>
 #include <Law_Interpol.hxx>
 #include <BRepBuilderAPI_TransitionMode.hxx>
 #include <TColStd_Array1OfReal.hxx>
 #include <TColStd_Array1OfInteger.hxx>
 #include <Geom_BSplineCurve.hxx>
 #include <BRepBuilderAPI_MakePolygon.hxx>
#include <math.hxx>
#include <vector>
#include <BRepTools_WireExplorer.hxx>
#include <IntAna_IntConicQuad.hxx>
#include <ProjLib_ProjectOnPlane.hxx>
#include <Geom_Line.hxx>


using namespace std;

 void DrawPoint(const Handle(AIS_InteractiveContext) &Context,gp_Pnt aPoint )
{
    TopoDS_Vertex V1 = BRepBuilderAPI_MakeVertex( aPoint );

    // Create the AIS_Shape
    Handle(AIS_Shape) aShape = new AIS_Shape(V1);

    // Set the vertex shape, color, and size
    Quantity_Color color(Quantity_NOC_YELLOW);
    Handle_Prs3d_PointAspect myPointAspect=new Prs3d_PointAspect(Aspect_TOM_O,color,1);
    aShape->Attributes()->SetPointAspect(myPointAspect);
    Context->Display(aShape,true);
}

 void DivideToPointsOnLine(const Handle(AIS_InteractiveContext) &Context ,gp_Pnt sPt,gp_Pnt ePt,int Quantity)
{
  Standard_Real distance = sPt.Distance(ePt);
  Standard_Real newLength = distance / Quantity;
  gp_Dir dir = gp_Dir(gp_Vec(sPt,ePt));
  gp_Pnt P = sPt;
  for (int i=1 ; i<Quantity;i++)
  {
  P.Translate(dir.XYZ()*newLength*i);
  DrawPoint(Context,P);
  P = sPt;
  }

}

 void ExtractLinesCoordinates(const Handle(AIS_InteractiveContext) &Context ,gp_Pnt& sPt,gp_Pnt& ePt)
{

    Context->InitSelected();
    while(Context->MoreSelected())
    {
    if(Context->HasSelectedShape() && Context->SelectedShape().ShapeType() == TopAbs_EDGE)
    {

    TopoDS_Shape myLine = Context->SelectedShape();
    //
    TopoDS_Shape aShape = myLine; // Your initial shape.
    for (TopExp_Explorer anExp(aShape, TopAbs_EDGE); anExp.More(); anExp.Next())
    {
      // Iterate over edges in input shape.
      const TopoDS_Edge& anEdge = TopoDS::Edge(anExp.Current());

      // Take the first and the last vertices from edge
      TopoDS_Vertex aVFirst = TopExp::FirstVertex(anEdge);
      TopoDS_Vertex aVLast  = TopExp::LastVertex(anEdge);

      // Take geometrical information from vertices.
       sPt = BRep_Tool::Pnt(aVFirst);
       ePt = BRep_Tool::Pnt(aVLast);
    }
    //

    }
    else
    {

    }

    Context->NextSelected();
    }

    Context->ClearSelected(true);

}

 gp_Pln PlaneOfTheView(Handle(V3d_View) aView)
    {
/*    Standard_Real x_ori, y_ori, z_ori;
    aView->Proj(x_ori, y_ori, z_ori);
    gp_Dir proj_orientation(x_ori, y_ori, z_ori);
    gp_Pln view_plane = gp_Pln(gp_Pnt (0, 0, 0), proj_orientation);
    */
    Standard_Real XEye,YEye,ZEye,XAt,YAt,ZAt;
    aView->Eye(XEye,YEye,ZEye);
    aView->At(XAt,YAt,ZAt);
    gp_Pnt EyePoint(XEye,YEye,ZEye);
    gp_Pnt AtPoint(XAt,YAt,ZAt);

    gp_Vec EyeVector(EyePoint,AtPoint);
    gp_Dir EyeDir(EyeVector);

    gp_Pln PlaneOfTheView1 = gp_Pln(AtPoint,EyeDir);

    return PlaneOfTheView1;

//    return view_plane;
    }

 gp_Pnt convertToPlane(const Standard_Integer Xs, const Standard_Integer Ys, Handle(V3d_View) myView)
{

    gp_Pnt p;
    Standard_Real Xv, Yv, Zv;
    Standard_Real Vx, Vy, Vz;
//    gp_Pln aPlane(myView->Viewer()->PrivilegedPlane());
    gp_Pln aPlane = PlaneOfTheView(myView);

#ifdef OCC_PATCHED
    myView->Convert( Xs, Ys, Xv, Yv, Zv );
#else
    // The + 1 overcomes a fault in OCC, in "OpenGl_togl_unproject_raster.c",
    // which transforms the Y axis ordinate. The function uses the height of the
    // window, not the Y maximum which is (height - 1).
    myView->Convert( Xs, Ys + 1, Xv, Yv, Zv );
#endif

    myView->Proj( Vx, Vy, Vz );
    gp_Lin aLine(gp_Pnt(Xv, Yv, Zv), gp_Dir(Vx, Vy, Vz));
    IntAna_IntConicQuad theIntersection( aLine, aPlane, Precision::Angular() );
    if (theIntersection.IsDone())
    {
        if (!theIntersection.IsParallel())
        {
            if (theIntersection.NbPoints() > 0)
            {
                gp_Pnt theSolution(theIntersection.Point(1));

                return theSolution;
            }
        }
    }
}

 gp_Pnt CCtP(int x, int y, Handle(V3d_View) aView)
{
Standard_Real aVx,aVy,aVz,aPx,aPy,aPz;
aView->Convert(x, y, aVx, aVy, aVz);
gp_Pnt a(aVx,aVy,aVz);
return a;

}

 gp_Pnt to3DPoint(Standard_Real x, Standard_Real y, Handle(V3d_View) aView)
{
// Make a plane perpendicular to the projection orientation.
    Standard_Real x_ori, y_ori, z_ori;
    aView->Proj(x_ori, y_ori, z_ori);
    gp_Dir proj_orientation(x_ori, y_ori, z_ori);
gp_Pln view_plane = gp_Pln(gp_Pnt (0, 0, 0), proj_orientation);
// Convert the 2d point into a 3d point.
Standard_Real xp, yp, zp;
aView->Convert(x, y, xp, yp, zp);
gp_Pnt converted_pnt(xp, yp, zp);
// Project the converted point in the plane.
gp_Pnt2d projected_pnt = ProjLib::Project(view_plane, converted_pnt);
// Get a 3d point from this 2d point.
gp_Pnt p3D = ElSLib::Value (projected_pnt.X(), projected_pnt.Y(), view_plane);
return p3D;
}


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

 vector<gp_Pnt> extract_points(const Handle(AIS_InteractiveContext) &Context)
{
 BRepTools_WireExplorer ex;
 vector<gp_Pnt> points;
    AIS_ListOfInteractive objList;
    Context->DisplayedObjects(objList);
    AIS_ListIteratorOfListOfInteractive iter;
    for(iter.Initialize(objList); iter.More(); iter.Next())
    {
    Handle(AIS_InteractiveObject) aisShp = iter.Value();
    if(aisShp->IsKind("AIS_Shape"))
    {
    TopoDS_Shape myShape = Handle(AIS_Shape)::DownCast(aisShp)->Shape();
    //now you that you got your shape, do something with it
    if (myShape.ShapeType() == TopAbs_WIRE)
    {
        TopoDS_Wire W = TopoDS::Wire(myShape);
        ex = BRepTools_WireExplorer(W);
        while (ex.More()== true)
        {
            TopoDS_Vertex vertex = ex.CurrentVertex();
            gp_Pnt pt = BRep_Tool::Pnt(vertex);
            points.push_back(pt);
            ex.Next();
        }
    };
};

};
    return points;
};