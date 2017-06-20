#pragma once
#include <QListWidget>
#include <QVector>

class QSceneNode;

class QSceneTree :
	public QListWidget
{
public:
	QSceneTree(QWidget* parent);
	virtual ~QSceneTree();

	void AddNode(QSceneNode* node);

	QSceneNode* GetSelectedNode();
	void LoadActiveNode();

private:
	QSceneNode* m_CurrentNode = nullptr;
	QVector<QSceneNode*> m_Nodes;
};

