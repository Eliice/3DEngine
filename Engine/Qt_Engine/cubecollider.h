#ifndef CUBECOLLIDER_H
#define CUBECOLLIDER_H

#include <QWidget>

namespace Ui {
class CubeCollider;
}

class CubeCollider : public QWidget
{
    Q_OBJECT

public:
    explicit CubeCollider(QWidget *parent = 0);
    ~CubeCollider();

private:
    Ui::CubeCollider *ui;
};

#endif // BOXCOLLIDER_H
