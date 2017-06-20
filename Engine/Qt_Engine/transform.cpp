#include "transform.h"
#include "ui_transform.h"
#include "QSceneNode.h"

Transform::Transform(QWidget *parent) :
    QComponentWidget("Transform", parent),
    ui(new Ui::Transform)
{    
    ui->setupUi(this);

}

Transform::~Transform()
{
    delete ui;

}

void Transform::Initialize()
{
	if (!m_GameObject)
		return;

	m_Data["NodeName"] = m_GameObject->GetName();
}

void Transform::GetTransformText(const QString& name)
{
    ui->lineEdit->setText(name);
}

QMap<QString, QString> Transform::GetValues()
{
	m_Data["NodeName"] = ui->lineEdit->text();

	QString name = ui->lineEdit->objectName();

	return m_Data;
}

void Transform::LoadValues(QMap<QString, QString> const& data)
{
	ui->lineEdit->setText(data["NodeName"]);
}

