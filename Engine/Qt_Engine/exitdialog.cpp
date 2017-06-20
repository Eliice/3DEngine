#include "exitdialog.h"
#include "ui_exitdialog.h"


ExitDialog::ExitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitDialog)
{
    ui->setupUi(this);

	buttonSave = ui->buttonSave;
}

ExitDialog::~ExitDialog()
{
    delete ui;
}

void ExitDialog::on_buttonCancel_clicked()
{
    this->hide();
}

void ExitDialog::on_buttonDontSave_clicked()
{
	ui->buttonSave->connect(ui->buttonDontSave, SIGNAL(clicked()), qApp, SLOT(quit()));
}
