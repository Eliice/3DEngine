#include "savewindow.h"
#include "ui_savewindow.h"

SaveWindow::SaveWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
}

SaveWindow::~SaveWindow()
{
    delete ui;
}
