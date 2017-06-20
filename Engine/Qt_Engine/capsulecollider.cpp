#include "capsulecollider.h"
#include "ui_capsulecollider.h"

CapsuleCollider::CapsuleCollider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CapsuleCollider)
{
    ui->setupUi(this);
}

CapsuleCollider::~CapsuleCollider()
{
    delete ui;
}
