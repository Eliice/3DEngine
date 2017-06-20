#pragma once
#include <QListWidgetItem>
#include <QVector>
#include <QMap>

#include "Vector3.h"

class SceneNode;
class QComponentWidget;

class QSceneNode : public QListWidgetItem
{
public:
	QSceneNode(QString const& name, SceneNode* node);
	virtual ~QSceneNode();

	void AddComponent(QComponentWidget* newComponent);
	void ShowComponents() const;
	void HideComponents();

	void SetNodePosition(math::Vector3 const& position, math::Vector3 const& rotation, math::Vector3 const& scale);

	void SetName(QString const& name);

	inline QString GetName() const { return m_Name; }
	inline SceneNode* GetNode() { return m_Node; }
private:
	SceneNode* m_Node = nullptr;

	QMap<QString, QMap<QString, QString>> m_ComponentData; // data["posX"] = 2;

	QVector<QComponentWidget*> m_Components;

	QString m_Name;

	int m_ComponentCount = 0;
};

