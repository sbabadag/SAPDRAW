#ifndef AXESDIALOG_H
#define AXESDIALOG_H

#include <QDialog>

namespace Ui {
class AxesDialog;
}

class AxesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AxesDialog(QWidget *parent = nullptr);
    ~AxesDialog();
    Ui::AxesDialog *Getui();
    void GetAxis(QString &X,QString &Y,QString &Z,int &XS,int &YS,int &ZS);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void GenerateGrid();

private:
    Ui::AxesDialog *ui;
};

#endif // AXESDIALOG_H
