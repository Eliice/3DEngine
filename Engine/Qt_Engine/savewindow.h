#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QWidget>

namespace Ui {
class SaveWindow;
}

class SaveWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SaveWindow(QWidget *parent = 0);
    ~SaveWindow();

private:
    Ui::SaveWindow *ui;
};

#endif // SAVEWINDOW_H
