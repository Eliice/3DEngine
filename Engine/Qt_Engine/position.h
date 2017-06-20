#ifndef POSITION_H
#define POSITION_H

#include <QWidget>

#include "Vector3.h"
#include "QComponentWidget.h"

namespace Ui {
class Position;
}

class Position : public QComponentWidget
{
    Q_OBJECT

public:
    explicit Position(QComponentWidget *parent = 0);
    ~Position();

	virtual void Initialize() override;

	virtual QMap<QString, QString> GetValues() override;
	virtual void LoadValues(QMap<QString, QString> const& data) override;

    void SetPosition(math::Vector3 pos, math::Vector3 rotation, math::Vector3 scale);

	public slots:
	virtual void OnTextChanged(QString const& value);

private:
    Ui::Position *ui;
};

#endif // POSITION_H
