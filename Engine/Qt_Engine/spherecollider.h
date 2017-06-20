#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include <QWidget>

namespace Ui {
class SphereCollider;
}

class SphereCollider : public QWidget
{
    Q_OBJECT

public:
    explicit SphereCollider(QWidget *parent = 0);
    ~SphereCollider();

private:
    Ui::SphereCollider *ui;
};

#endif // SPHERECOLLIDER_H
