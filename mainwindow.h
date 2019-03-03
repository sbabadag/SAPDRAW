#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <view.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_actionLine_triggered();

    void on_actionTop_triggered();

    void on_actionFront_triggered();

    void on_actionZoom_All_triggered();

    void on_actionPoint_mode_triggered();

    void on_actionPoint_mode_changed();

    void on_actionB_l_triggered();

private:
    Ui::MainWindow *ui;
    MyGLView *myOCCView ;

};

#endif // MAINWINDOW_H
