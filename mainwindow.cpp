#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <AIS_ListOfInteractive.hxx>

#include <AIS_ListIteratorOfListOfInteractive.hxx>

#include <BRepPrimAPI_MakeSphere.hxx>

#include <AIS_Trihedron.hxx>

#include <Geom_Axis2Placement.hxx>
#include <Standard_PrimitiveTypes.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <V3d_View.hxx>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myOCCView = new MyGLView(this);
    setCentralWidget(myOCCView);
   myOCCView->ui = ui;
   myOCCView->Bar = ui->statusBar;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_actionLine_triggered()
{
    //myOCCView->drawLine();
    gp_Pnt pt1(0,0,0);
    gp_Pnt pt2(0,0,10000);
    gp_Pnt pt3(10000,0,12000);
    gp_Pnt pt4(20000,0,10000);
    gp_Pnt pt5(20000,0,0);

    vector<gp_Pnt> p;
    p.push_back(pt1);
    p.push_back(pt2);
    p.push_back(pt3);
    p.push_back(pt4);
    p.push_back(pt5);



    myOCCView->drawBuilding(p,6000,10);
}

void MainWindow::on_actionTop_triggered()
{
    myOCCView->myView->SetProj(V3d_Zpos);
}

void MainWindow::on_actionFront_triggered()
{
    myOCCView->myView->SetProj(V3d_Xpos);

}

void MainWindow::on_actionZoom_All_triggered()
{
    myOCCView->myView->FitAll();

}
