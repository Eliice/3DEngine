#ifndef EXITDIALOG_H
#define EXITDIALOG_H

#include <QDialog>

#include "Service\servicelocator.h"
#include "Scene\Scene.h"


namespace Ui {
class ExitDialog;
}

class ExitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExitDialog(QWidget *parent = 0);
    ~ExitDialog();

	inline QPushButton* GetSaveButton() { return buttonSave; }

private slots:
    void on_buttonCancel_clicked();

    void on_buttonDontSave_clicked();

private:

    Ui::ExitDialog *ui;

	QPushButton* buttonSave;
};

#endif // EXITDIALOG_H
