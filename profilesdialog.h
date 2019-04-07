#ifndef PROFILESDIALOG_H
#define PROFILESDIALOG_H

#include <QDialog>
#include <QFile>
#include <QStringListModel>
#include <vector>
#include <QStandardItemModel>

struct Profile
{
    QString Name;
    double b;
    double h;
    double t;
    double w;
    double ix;
    double iy;
    double sx;
    double sy;

};

using namespace std;

namespace Ui {
class ProfilesDialog;
}

class ProfilesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfilesDialog(QWidget *parent = nullptr);
    ~ProfilesDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProfilesDialog *ui;
    QFile IPE_Profile_File;
    vector<Profile*> Profiles;
    QStandardItemModel model;

    void LoadProfiles();
};

#endif // PROFILESDIALOG_H
