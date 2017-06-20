#include "position.h"
#include "ui_position.h"
#include "QSceneNode.h"

Position::Position(QComponentWidget *parent) :
    QComponentWidget("Position", parent),
    ui(new Ui::Position)
{
    ui->setupUi(this);
    SetPosition(math::Vector3(0,0,0), math::Vector3(0,0,0), math::Vector3(1,1,1));

	connect(ui->Xpos, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
	connect(ui->Ypos, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
	connect(ui->Zpos, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));

	connect(ui->Xrotation, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
	connect(ui->Yrotation, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
	connect(ui->Zrotation, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));

	connect(ui->Xscale, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
	connect(ui->Yscale, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
	connect(ui->Zscale, SIGNAL(textEdited(QString const&)), this, SLOT(OnTextChanged(QString const&)));
}

Position::~Position()
{
    delete ui;
}

void Position::Initialize()
{
	m_Data["Xpos"] = ui->Xpos->text();
	m_Data["Ypos"] = ui->Ypos->text();
	m_Data["Zpos"] = ui->Zpos->text();

	m_Data["Xrotation"] = ui->Xrotation->text();
	m_Data["Yrotation"] = ui->Yrotation->text();
	m_Data["Zrotation"] = ui->Zrotation->text();

	m_Data["Xscale"] = ui->Xscale->text();
	m_Data["Yscale"] = ui->Yscale->text();
	m_Data["Zscale"] = ui->Zscale->text();
}

QMap<QString, QString> Position::GetValues()
{
	return m_Data;
}

void Position::LoadValues(QMap<QString, QString> const& data)
{
	math::Vector3 position(data["Xpos"].toFloat(), data["Xpos"].toFloat(), data["Xpos"].toFloat());
	math::Vector3 rotation(data["Xrotation"].toFloat(), data["Xrotation"].toFloat(), data["Xrotation"].toFloat());
	math::Vector3 scale(data["Xscale"].toFloat(), data["Yscale"].toFloat(), data["Zscale"].toFloat());

	SetPosition(position, rotation, scale);
}

void Position::SetPosition(math::Vector3 pos, math::Vector3 rotation, math::Vector3 scale)
{
    ui->Xpos->setText(QString::number(pos.x));
    ui->Ypos->setText(QString::number(pos.y));
    ui->Zpos->setText(QString::number(pos.z));

    ui->Xrotation->setText(QString::number(rotation.x));
    ui->Yrotation->setText(QString::number(rotation.y));
    ui->Zrotation->setText(QString::number(rotation.z));

    ui->Xscale->setText(QString::number(scale.x));
    ui->Yscale->setText(QString::number(scale.y));
    ui->Zscale->setText(QString::number(scale.z));

	if (m_GameObject)
		m_GameObject->SetNodePosition(pos, rotation, scale);
}

void Position::OnTextChanged(QString const& value)
{
	QComponentWidget::OnTextChanged(value);

	math::Vector3 position(ui->Xpos->text().toFloat(), ui->Ypos->text().toFloat(), ui->Zpos->text().toFloat());
	math::Vector3 rotation(ui->Xrotation->text().toFloat(), ui->Yrotation->text().toFloat(), ui->Zrotation->text().toFloat());
	math::Vector3 scale(ui->Xscale->text().toFloat(), ui->Yscale->text().toFloat(), ui->Zscale->text().toFloat());

	SetPosition(position, rotation, scale);
}