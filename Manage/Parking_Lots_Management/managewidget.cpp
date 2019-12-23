#include "managewidget.h"
#include "ui_managewidget.h"

ManageWidget::ManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageWidget)
{
    ui->setupUi(this);
}

ManageWidget::~ManageWidget()
{
    delete ui;
}
