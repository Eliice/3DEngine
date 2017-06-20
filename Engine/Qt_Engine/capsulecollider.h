#ifndef CAPSULECOLLIDER_H
#define CAPSULECOLLIDER_H

#include <QWidget>

namespace Ui {
class CapsuleCollider;
}

class CapsuleCollider : public QWidget
{
    Q_OBJECT

public:
    explicit CapsuleCollider(QWidget *parent = 0);
    ~CapsuleCollider();

private:
    Ui::CapsuleCollider *ui;
};

#endif // CAPSULECOLLIDER_H
