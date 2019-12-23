#ifndef MANAGEWIDGET_H
#define MANAGEWIDGET_H

#include <QWidget>

namespace Ui {
class ManageWidget;
}

class ManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ManageWidget(QWidget *parent = 0);
    ~ManageWidget();

private:
    Ui::ManageWidget *ui;
};

#endif // MANAGEWIDGET_H
