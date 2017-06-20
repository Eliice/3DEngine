#include "cubecollider.h"
#include "ui_cubecollider.h"

CubeCollider::CubeCollider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CubeCollider)
{
    ui->setupUi(this);
}

CubeCollider::~CubeCollider()
{
    delete ui;
}
