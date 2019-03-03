#include "divideline_dialog.h"
#include "ui_divideline_dialog.h"
#include "mainwindow.h"
#include "occ_helper_functions.h"

DivideLine_Dialog::DivideLine_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DivideLine_Dialog)
{
    ui->setupUi(this);

}

DivideLine_Dialog::~DivideLine_Dialog()
{
    delete ui;
}

void DivideLine_Dialog::on_buttonBox_accepted()
{
    ExtractLinesCoordinates(theContext,a,b);
    DivideToPointsOnLine(theContext,a,b,ui->lineEdit->text().toInt());
}
