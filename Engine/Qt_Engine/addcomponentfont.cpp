#include "addcomponentfont.h"
#include "ui_addcomponentfont.h"

AddComponentFont::AddComponentFont(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddComponentFont)
{
    ui->setupUi(this);

	button = ui->AddComponent;
}

AddComponentFont::~AddComponentFont()
{
    delete ui;
}

