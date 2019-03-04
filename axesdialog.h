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

private:
    Ui::AxesDialog *ui;
};

#endif // AXESDIALOG_H
