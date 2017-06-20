#ifndef ADDCOMPONENTFONT_H
#define ADDCOMPONENTFONT_H

#include <QWidget>
#include <qpushbutton.h>
#include <ui_addcomponentfont.h>
#include <qobject.h>

namespace Ui {
class AddComponentFont;
}

class AddComponentFont : public QWidget
{
    Q_OBJECT

public:
    explicit AddComponentFont(QWidget *parent = 0);
    ~AddComponentFont();

	inline QPushButton* GetPushButton() { return button; }

private:
	Ui::AddComponentFont *ui;
	QPushButton* button;
	  
};

#endif // ADDCOMPONENTFONT_H
