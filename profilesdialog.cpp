#include "profilesdialog.h"
#include "ui_profilesdialog.h"
#include <QMessageBox>
#include <QTextStream>
#include <QStringListModel>
#include <QStandardItemModel>

ProfilesDialog::ProfilesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilesDialog)
{
    ui->setupUi(this);
    LoadProfiles();


}

ProfilesDialog::~ProfilesDialog()
{
    delete ui;
}

void ProfilesDialog::LoadProfiles()
{
    Profile *P;

    IPE_Profile_File.setFileName("/Users/selahattinbabadag/Documents/SAPDRAW/IPE.txt");
    if(!IPE_Profile_File.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "error", IPE_Profile_File.errorString());
    }

    QTextStream in(&IPE_Profile_File);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("	");
        ui->comboBox_2->addItem("IPE"+fields[0]);
        P = new Profile;
        P->Name = "IPE"+fields[0];
        P->b = fields[2].toDouble();
        P->h = fields[1].toDouble();
        P->t = fields[3].toDouble();
        P->w = fields[4].toDouble();
        P->ix = fields[11].toDouble();
        P->iy = fields[13].toDouble();
        P->sx = fields[12].toDouble();
        P->sy = fields[14].toDouble();
        Profiles.push_back(P);
    }

    IPE_Profile_File.close();



}

void ProfilesDialog::on_pushButton_clicked()
{
    Profile *P;
 int i= ui->comboBox_2->currentIndex();

        QStandardItem *group = new QStandardItem(QString("%1").arg(Profiles[i]->Name));
        for (int j=0;j<=7;j++)
        {
            P= Profiles[i];

            switch (j)
            {
            case 0:{QStandardItem *child = new QStandardItem(QString("b=%1  (%2)").arg(P->b).arg(P->Name));group->appendRow(child);};break;
            case 1:{QStandardItem *child = new QStandardItem(QString("h=%1  (%2)").arg(P->h).arg(P->Name));group->appendRow(child);};break;
            case 2:{QStandardItem *child = new QStandardItem(QString("t=%1  (%2)").arg(P->t).arg(P->Name));group->appendRow(child);};break;
            case 3:{QStandardItem *child = new QStandardItem(QString("w=%1  (%2)").arg(P->w).arg(P->Name));group->appendRow(child);};break;
            case 4:{QStandardItem *child = new QStandardItem(QString("ix=%1 (%2)").arg(P->ix).arg(P->Name));group->appendRow(child);};break;
            case 5:{QStandardItem *child = new QStandardItem(QString("iy=%1 (%2)").arg(P->iy).arg(P->Name));group->appendRow(child);};break;
            case 6:{QStandardItem *child = new QStandardItem(QString("Sx=%1 (%2)").arg(P->sx).arg(P->Name));group->appendRow(child);};break;
            case 7:{QStandardItem *child = new QStandardItem(QString("Sy=%1 (%2)").arg(P->sy).arg(P->Name));group->appendRow(child);};break;
            };

        }
        model.appendRow(group);

    ui->columnView->setModel(&model);
}
