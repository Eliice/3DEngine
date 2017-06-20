#include "QSceneTree.h"
#include "QSceneNode.h"


QSceneTree::QSceneTree(QWidget* parent)
	: QListWidget(parent)
{
}


QSceneTree::~QSceneTree()
{
}

void QSceneTree::AddNode(QSceneNode* node)
{
	if (!node)
		return;

	addItem(node);
	m_Nodes.push_back(node);
}

QSceneNode* QSceneTree::GetSelectedNode()
{
	// TODO : isSelected is not working
	int size = m_Nodes.size();
	for (int i = 0; i < size; i++)
	{
		bool isSelected = m_Nodes[i]->isSelected();
		if (isSelected)
			return m_Nodes[i];
	}

	return nullptr;
}

void QSceneTree::LoadActiveNode()
{

	if (m_CurrentNode)
		m_CurrentNode->HideComponents();

	m_CurrentNode = GetSelectedNode();

	if (m_CurrentNode)
		m_CurrentNode->ShowComponents();
}