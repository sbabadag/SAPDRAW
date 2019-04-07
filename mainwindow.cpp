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
#include <profilesdialog.h>
#include <occ_helper_functions.h>
#include "axesdialog.h"
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myOCCView = new MyGLView(this);
    setCentralWidget(myOCCView);
   myOCCView->ui = ui;
   myOCCView->Bar = ui->statusBar;
   AD = new AxesDialog();
   //
   ViewCombo = new QComboBox();
   ViewList = new QStringList();
   ViewList->push_back( QString(" XY "));
   ViewList->push_back( QString(" XZ "));
   ViewList->push_back( QString(" YZ "));
   ViewCombo->addItems(*ViewList);
   //
   DistCombo = new QComboBox();
   DistList = new QStringList();
   DistList->push_back( QString(" 0 "));
   DistList->push_back( QString(" 6000 "));
   DistList->push_back( QString(" 12000 "));
   DistCombo->addItems(*DistList);

   ui->statusBar->addPermanentWidget(ViewCombo);
   ui->statusBar->addPermanentWidget(DistCombo);




   connect(ViewCombo,SIGNAL(activated(int)),this,SLOT(clickedaction(int)));
   connect(DistCombo,SIGNAL(activated(int)),this,SLOT(clickedaction1(int)));
   connect(AD,SIGNAL(GenerateGrid()),this,SLOT(GenerateGridSlot()));
   connect(myOCCView,SIGNAL(ChangeDistances(QString)),this,SLOT(ModifyDistCombo(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
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
    myOCCView->myView->FitAll();
}

void MainWindow::on_actionFront_triggered()
{
    myOCCView->myView->SetProj(V3d_Ypos);
    myOCCView->myView->FitAll();

}

void MainWindow::on_actionZoom_All_triggered()
{
    myOCCView->myView->FitAll();

}

void MainWindow::on_actionPoint_mode_triggered()
{
}

void MainWindow::on_actionPoint_mode_changed()
{
    if (ui->actionPoint_mode->isChecked())
    {
        myOCCView->getContext()->ActivateStandardMode(TopAbs_VERTEX);
    }
    else {
        myOCCView->getContext()->ActivateStandardMode(TopAbs_EDGE);
    }
}

void MainWindow::on_actionB_l_triggered()
{
    myOCCView->DivideDialog->show();
}

void MainWindow::on_actionClip_Plane_triggered()
{
    gp_Pln Pln1(gp_Pnt(0,12001,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,1,0))));
    gp_Pln Pln2(gp_Pnt(0,18000,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,-1,0))));

  CreateClipPlane(myOCCView->myView,Pln1,Pln2,p1,p2);
}

void MainWindow::on_actionIzgara_triggered()
{
    AD->show();
}

void MainWindow::on_actionProfiller_triggered()
{
    ProfilesDialog *PD = new ProfilesDialog();
    PD->show();
}

void MainWindow::clickedaction(int)
{
    double xd=0,yd=0,zd=0;
    gp_Pnt dir;
    gp_Ax3 Pln1;

    if (myOCCView->myView->GetClipPlanes().IsEmpty() != true)
    {
        myOCCView->myView->RemoveClipPlane(&p1);
        myOCCView->myView->RemoveClipPlane(&p2);
    }


       switch (ViewCombo->currentIndex()) {
       case 0:
       {
           xd = 0;
           yd = 0;
           zd = DistCombo->currentText().toDouble();
           myOCCView->ChangeDistances(Z);

           P1 = gp_Pln(gp_Pnt(0,0,zd),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,0,1))));
           P2 = gp_Pln(gp_Pnt(0,0,zd+10),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,0,-1))));

            Pln1 = gp_Ax3(gp_Pnt(xd,yd,zd),gp_Dir(0,0,zd+1));
            myOCCView->myView->SetProj(V3d_Zpos);




       }
           break;
       case 1:
       {
           xd = 0;
           yd = DistCombo->currentText().toDouble();
           zd = 0;
           myOCCView->ChangeDistances(Y);
           P1 = gp_Pln(gp_Pnt(0,yd,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,1,0))));
           P2 = gp_Pln(gp_Pnt(0,yd+10,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,-1,0))));
           Pln1 = gp_Ax3(gp_Pnt(xd,yd,zd),gp_Dir(0,yd+1,0));
           myOCCView->myView->SetProj(V3d_Ypos);



       }

           break;
       case 2:
       {
           xd = DistCombo->currentText().toDouble();
           yd = 0;
           zd = 0;
           myOCCView->ChangeDistances(X);
           P1 = gp_Pln(gp_Pnt(xd,0,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(1,0,0))));
           P2 = gp_Pln(gp_Pnt(xd+10,0,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(-1,0,0))));
           Pln1 = gp_Ax3(gp_Pnt(xd,yd,zd),gp_Dir(xd+1,0,0));
           myOCCView->myView->SetProj(V3d_Xpos);
       }

           break;
       }



       myOCCView->myView->Viewer()->SetPrivilegedPlane(Pln1);
       CreateClipPlane(myOCCView->myView,P1,P2,p1,p2);
       myOCCView->myView->FitAll();

}

void MainWindow::clickedaction1(int)
{
    double xd=0,yd=0,zd=0;
    gp_Pnt dir;
    gp_Ax3 Pln1;

    if (myOCCView->myView->GetClipPlanes().IsEmpty() != true)
    {
        myOCCView->myView->RemoveClipPlane(&p1);
        myOCCView->myView->RemoveClipPlane(&p2);
    }



       switch (ViewCombo->currentIndex()) {
       case 0:
       {
           xd = 0;
           yd = 0;
           zd = DistCombo->currentText().toDouble();

           P1 = gp_Pln(gp_Pnt(0,0,zd),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,0,1))));
           P2 = gp_Pln(gp_Pnt(0,0,zd+10),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,0,-1))));

            Pln1 = gp_Ax3(gp_Pnt(xd,yd,zd),gp_Dir(0,0,1));
       }
           break;
       case 1:
       {
           xd = 0;
           yd = DistCombo->currentText().toDouble();
           zd = 0;
           P1 = gp_Pln(gp_Pnt(-1,yd,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,1,0))));
           P2 = gp_Pln(gp_Pnt(-1,yd+10,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(0,-1,0))));
           Pln1 = gp_Ax3(gp_Pnt(xd,yd,zd),gp_Dir(0,1,0));
       }

           break;
       case 2:
       {
           xd = DistCombo->currentText().toDouble();
           yd = 0;
           zd = 0;
           P1 = gp_Pln(gp_Pnt(xd,0,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(1,0,0))));
           P2 = gp_Pln(gp_Pnt(xd+10,0,0),gp_Dir(gp_Vec(gp_Pnt(0,0,0),gp_Pnt(-1,0,0))));
           Pln1 = gp_Ax3(gp_Pnt(xd,yd,zd),gp_Dir(1,0,0));
       }

           break;
       }



       myOCCView->myView->Viewer()->SetPrivilegedPlane(Pln1);
       CreateClipPlane(myOCCView->myView,P1,P2,p1,p2);
       myOCCView->myView->FitAll();

}


void MainWindow::GenerateGridSlot()
{
    int XS,YS,ZS;

    AD->GetAxis(X,Y,Z,XS,YS,ZS);
    CreateMainGrid(myOCCView->myView,myOCCView->getContext(),gp_Pnt(XS,YS,ZS),X,Y,Z,2);
    myOCCView->myView->FitAll();

}

void MainWindow::ModifyDistCombo(QString G)
{
   DistCombo->clear();
   DistCombo->addItems(G.split(" "));
}

void MainWindow::on_actionViewDepth_triggered()
{
    if (myOCCView->myView->GetClipPlanes().IsEmpty() != true)
    {
        myOCCView->myView->RemoveClipPlane(&p1);
        myOCCView->myView->RemoveClipPlane(&p2);
    }
    myOCCView->myView->SetProj(V3d_XposYposZpos );
    myOCCView->myView->FitAll();



}
