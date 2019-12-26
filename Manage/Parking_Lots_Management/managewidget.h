#ifndef MANAGEWIDGET_H
#define MANAGEWIDGET_H

#include <QWidget>

#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QSerialPort>

namespace Ui {
class ManageWidget;
}

class ManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ManageWidget(QWidget *parent = 0);
    ~ManageWidget();

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;    //重写nativeEvent函数

private slots:
    void dealReadFromSerialPort();  //处理信息

    void on_buttonAdd_released();

    void on_buttonDelete_released();

    void on_buttonReset_released();

    void on_buttonSubmit_released();

    void on_pushButtonFlesh_released();

private:
    Ui::ManageWidget *ui;
    QSqlDatabase database;     //数据库
    QSqlTableModel *model;      //表
    QSerialPort *serialPort; //串口
    QString PasteData;
    bool seriFlag;
    int iNNums;             //进入人数
    int allNums;            //总人数

    void uiInit();          //UI控件初始化
    void dataInit();        //数据初始化
    void connectDatabase(); //连接数据库
    void updateTableView(); //更新显示
    void scanPort();        //扫描串口
};

#endif // MANAGEWIDGET_H
