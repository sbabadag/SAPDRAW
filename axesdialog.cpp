#include "axesdialog.h"
#include "ui_axesdialog.h"

AxesDialog::AxesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AxesDialog)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
}

AxesDialog::~AxesDialog()
{
    delete ui;
}

Ui::AxesDialog *AxesDialog::Getui()
{
    return ui;
}

void AxesDialog::GetAxis(QString &X, QString &Y, QString &Z, int &XS, int &YS, int &ZS)
{
    X = ui->lineEdit->text();
    Y = ui->lineEdit_2->text();
    Z = ui->lineEdit_3->text();

    //
    XS = ui->lineEdit_7->text().toInt();
    YS = ui->lineEdit_7->text().toInt();
    ZS = ui->lineEdit_7->text().toInt();
    //
}

void AxesDialog::on_pushButton_clicked()
{
 GenerateGrid();
 this->close();
}

void AxesDialog::on_pushButton_2_clicked()
{
    this->close();
}
