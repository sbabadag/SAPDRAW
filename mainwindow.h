#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <view.h>
#include <QMessageBox>
#include "axesdialog.h"
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList *ViewList ;
    QStringList *DistList;
    QComboBox *ViewCombo ;
    QComboBox *DistCombo ;
    QString X,Y,Z;
    gp_Pln P1,P2;
    Graphic3d_ClipPlane  p1;
    Graphic3d_ClipPlane  p2;




private slots:

    void on_actionLine_triggered();

    void on_actionTop_triggered();

    void on_actionFront_triggered();

    void on_actionZoom_All_triggered();

    void on_actionPoint_mode_triggered();

    void on_actionPoint_mode_changed();

    void on_actionB_l_triggered();

    void on_actionClip_Plane_triggered();

    void on_actionIzgara_triggered();

    void on_actionProfiller_triggered();

    void clickedaction(int);

    void clickedaction1(int);


    void on_actionViewDepth_triggered();

public slots:

    void GenerateGridSlot();
    void ModifyDistCombo(QString G);

private:
    Ui::MainWindow *ui;
    MyGLView *myOCCView ;
    AxesDialog *AD ;





};

#endif // MAINWINDOW_H
