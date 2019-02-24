#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myView = new MyGLView(this);
    setCentralWidget(myView);

}

MainWindow::~MainWindow()
{
    delete ui;
}
