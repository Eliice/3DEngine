#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QWidget>
#include "QComponentWidget.h"

namespace Ui {
class Transform;
}

class Transform : public QComponentWidget
{
    Q_OBJECT

public:
    explicit Transform(QWidget *parent = 0);
    ~Transform();

	virtual void Initialize() override;

    void GetTransformText(const QString& name);

	virtual QMap<QString, QString> GetValues() override;
	virtual void LoadValues(QMap<QString, QString> const& data) override;
private:
    Ui::Transform*  ui;

};

#endif // TRANSFORM_H
