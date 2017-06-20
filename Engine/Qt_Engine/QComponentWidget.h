#pragma once
#include <QWidget>
#include <QMap>

class QSceneNode;

class QComponentWidget : public QWidget
{
public:
	QComponentWidget(QString const& name, QWidget* parent);
	virtual ~QComponentWidget();

	virtual void Initialize() = 0;

	inline virtual QMap<QString, QString> GetValues() {	return m_Data;}
	inline virtual void LoadValues(QMap<QString, QString> const& data) { (void) data; }

	void SetGameObject(QSceneNode* gameObject);

	inline QString GetName() const { return m_Name; }

public slots:
	virtual void OnTextChanged(QString const& value);

protected:
	QMap<QString, QString> m_Data;
	QSceneNode* m_GameObject = nullptr;

	QString const m_Name;
};

