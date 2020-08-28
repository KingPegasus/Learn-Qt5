#ifndef CUTOMDIALOG_H
#define CUTOMDIALOG_H

#include <QDialog>

namespace Ui {
class CutomDialog;
}

class CutomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CutomDialog(QWidget *parent = nullptr);
    ~CutomDialog();

private:
    Ui::CutomDialog *ui;
};

#endif // CUTOMDIALOG_H
