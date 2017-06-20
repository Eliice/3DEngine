#ifndef COLLIDER_H
#define COLLIDER_H

#include <QWidget>

#include "QComponentWidget.h"



namespace Ui {
class Collider;
}

class Collider : public QComponentWidget
{
    Q_OBJECT

public:
    explicit Collider(QWidget *parent = 0);
    ~Collider();

	virtual void Initialize() override;

	void SetUsed(bool isColliderSet);

	void UpdateBox();

private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Collider *ui;
	bool m_colliderSet = false;
};

#endif // COLLIDER_H
