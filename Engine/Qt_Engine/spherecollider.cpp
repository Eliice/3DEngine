#include "spherecollider.h"
#include "ui_spherecollider.h"

SphereCollider::SphereCollider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SphereCollider)
{
    ui->setupUi(this);
}

SphereCollider::~SphereCollider()
{
    delete ui;
}
