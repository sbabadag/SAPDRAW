
#ifndef DIVIDELINE_DIALOG_H
#define DIVIDELINE_DIALOG_H

#include <QDialog>
#include <AIS_InteractiveContext.hxx>

namespace Ui {
class DivideLine_Dialog;
}

class DivideLine_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit DivideLine_Dialog(QWidget *parent = nullptr);
    ~DivideLine_Dialog();
     Handle(AIS_InteractiveContext) theContext;
     gp_Pnt a,b;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DivideLine_Dialog *ui;

};

#endif // DIVIDELINE_DIALOG_H
