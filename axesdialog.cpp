#include "axesdialog.h"
#include "ui_axesdialog.h"

AxesDialog::AxesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AxesDialog)
{
    ui->setupUi(this);
}

AxesDialog::~AxesDialog()
{
    delete ui;
}
