#include "QComponentWidget.h"



QComponentWidget::QComponentWidget(QString const& name, QWidget* parent)
	: QWidget(parent), m_Name(name)
{
}


QComponentWidget::~QComponentWidget()
{
	m_Data.clear();

	m_GameObject = nullptr;
}

void QComponentWidget::SetGameObject(QSceneNode* gameObject)
{
	if (!gameObject)
		return;

	m_GameObject = gameObject;
}

void QComponentWidget::OnTextChanged(QString const& value)
{
	QString name = sender()->objectName();
	m_Data[name] = value;
}