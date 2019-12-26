#include "managewidget.h"
#include "ui_managewidget.h"
#include <windows.h>
#include <dbt.h>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSerialPortInfo>
#include <QSqlQuery>
#include <QDateTime>

ManageWidget::ManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageWidget)
{
    ui->setupUi(this);
    uiInit();
    dataInit();
    connectDatabase();
    updateTableView();
}

ManageWidget::~ManageWidget()
{
    delete ui;
}

//重写nativeEvent函数
bool ManageWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    //其中eventType表明了此次消息的类型，message存储着具体是什么信息，result是个传出变量；
    //eventType在windows操作系统下是"windows_generic_MSG"字符串，可以查看Qt的文档知道
    //message表明这个信号附带哪些信息，在热插拔事件中是WM_DEVICECHANGE类型，具体windows定义了哪些，可以查看“Dbt.h”文件
    if(eventType == QByteArray("windows_generic_MSG"))
    {
        //MSG是winApi定义的结构体，具体定义如下：
        /*
         * typedef struct tagMSG {
         * HWND hwnd;
         * UINT message;   //消息类型，热插拔是WM_DEVICECHANGE
         * WPARAM wParam;  //对消息的进一步描述
         * LPARAM lParam;  //指向一个结构体，结构中有好多消息
         * DWORD time;     //产生时间
         * POINT pt;       //鼠标坐标
         * } MSG;
        */
        MSG *pMsg = reinterpret_cast<MSG*>(message);

        if(pMsg->message == WM_DEVICECHANGE)
        {
            switch(pMsg->wParam)
            {
            //设备连上
            case DBT_DEVICEARRIVAL:
                qDebug() << "设备连上";
                scanPort();
                break;
            //设备断开
            case DBT_DEVICEREMOVECOMPLETE:
                qDebug() << "设备断开";
                foreach(const QSerialPortInfo info, QSerialPortInfo::availablePorts())
                {
                    qDebug() << info.portName();
                    if(info.portName() == serialPort->portName())
                    {

                        return false;
                    }
                    else
                    {
                        seriFlag = false;
                        serialPort->close();
                        QPalette palette;                       //初始化状态颜色
                        palette.setColor(QPalette::Background, QColor(255, 0, 0));
                        ui->labelConnectStatus->setPalette(palette);
                        ui->labelConnectStatus->setText("未连接");
                    }
                }
                break;
            //其他的消息可以查看“Dbt.h”文件
            }
        }
    }

    return false;
}

//UI控件初始化
void ManageWidget::uiInit()
{
    QPalette palette;                       //初始化状态颜色
    palette.setColor(QPalette::Background, QColor(255, 0, 0));
    ui->labelConnectStatus->setAutoFillBackground(true);
    ui->labelConnectStatus->setPalette(palette);
    ui->lineEditAllNum->setEnabled(false);
    ui->lineEditInNum->setEnabled(false);
}

//数据初始化
void ManageWidget::dataInit()
{
    iNNums = 0;
    allNums = 0;
    serialPort = new QSerialPort();
    //接收串口的信息
    connect(serialPort, &QSerialPort::readyRead, this, &ManageWidget::dealReadFromSerialPort);
}

//连接数据库
void ManageWidget::connectDatabase()
{
    //设置数据库驱动
    database = QSqlDatabase::addDatabase("QSQLITE");
    //连接数据库
    //database.setHostName("127.0.0.1");
    //database.setPort(3306);
    database.setDatabaseName("dataBase.db");
    //打开数据库
    if( !database.open() )
    {
        QMessageBox::warning(this, "错误", database.lastError().text());
    }
    model = new QSqlTableModel(ui->tableViewInfo, database);
    model->setTable("doorinfo");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    //获取总人数
    QSqlQuery query(database);
    QString qbuf = QString("select count(*) from doorinfo;");
    query.exec(qbuf);
    query.next();
    allNums = query.value(0).toInt();
    ui->lineEditAllNum->setText(QString::number(allNums));
}

//更新显示
void ManageWidget::updateTableView()
{
    model->setHeaderData(0, Qt::Horizontal,"学号");
    model->setHeaderData(1, Qt::Horizontal,"姓名");
    model->setHeaderData(2, Qt::Horizontal,"性别");
    model->setHeaderData(3, Qt::Horizontal,"进入时间");
    model->setHeaderData(4, Qt::Horizontal,"离开时间");
    model->setHeaderData(5, Qt::Horizontal,"面部ID");
    model->setHeaderData(6, Qt::Horizontal,"是否离开");
    ui->tableViewInfo->setModel(model);
}

//扫描串口
void ManageWidget::scanPort()
{
    foreach(const QSerialPortInfo info, QSerialPortInfo::availablePorts())
    {
        serialPort->setPort(info);
        if(serialPort->open(QIODevice::ReadWrite))
        {
            qDebug() << info.portName();
            //设置串口名
            //serialPort->setPortName(info.portName());
            //设置波特率
            serialPort->setBaudRate(115200);
            //设置数据位数
            serialPort->setDataBits(QSerialPort::Data8);
            //设置奇偶校验
            serialPort->setParity(QSerialPort::NoParity);
            //设置停止位
            serialPort->setStopBits(QSerialPort::OneStop);
            //设置流控制
            serialPort->setFlowControl(QSerialPort::NoFlowControl);
            serialPort->write("#");
            qDebug() << "write success";
            serialPort->waitForBytesWritten(100);
            serialPort->waitForReadyRead(100);
            QString ans(serialPort->readAll());
            if(ans.contains('!'))
            {
                //接收串口的信息
                bool b = connect(serialPort, &QSerialPort::readyRead, this, &ManageWidget::dealReadFromSerialPort);
                qDebug() << "是否连接成功" <<b;
                QPalette palette;                       //改变状态颜色
                ui->labelConnectStatus->setText("已连接");
                palette.setColor(QPalette::Background, QColor(0, 255, 0));
                ui->labelConnectStatus->setPalette(palette);
                seriFlag = true;
                return;
            }
            else
                serialPort->close();
            qDebug() << serialPort->isOpen() << "串口状态";
        }
    }
}

//信息处理
void ManageWidget::dealReadFromSerialPort()
{
/*
 * 帧头:* 帧尾:#
*/
    qDebug() << "OK" << seriFlag;
    if(!seriFlag)
    {
        return;
    }
    QString ReadData;
    QString BufferData = serialPort->readAll();
    qDebug() << BufferData;
    //异常类：无头且变量为空，已丢失头部，数据不可靠，直接返回
    if ((!BufferData.contains("*"))&&(PasteData.isNull()))
    {
        return;
    }
    //第一种：有头无尾，先清空原有内容，再附加
    if ((BufferData.contains("*"))&&(!BufferData.contains("#")))
    {
        PasteData.clear();
        PasteData.append(BufferData);
    }
    //第二种：无头无尾且变量已有内容，数据中段部分，继续附加即可
    if ((!BufferData.contains("*"))&&(!BufferData.contains("#"))&&(!PasteData.isNull()))
    {
        PasteData.append(BufferData);
    }
    //第三种：无头有尾且变量已有内容，已完整读取，附加后输出数据，并清空变量
    if ((!BufferData.contains("*"))&&(BufferData.contains("#"))&&(!PasteData.isNull()))
    {
        PasteData.append(BufferData);
        ReadData = PasteData;
        PasteData.clear();
    }
    //第四种：有头有尾（一段完整的内容），先清空原有内容，再附加，然后输出，最后清空变量
    if ((BufferData.contains("*"))&(BufferData.contains("#")))
    {
        PasteData.clear();
        PasteData.append(BufferData);
        ReadData = PasteData;
        PasteData.clear();
    }
    if(ReadData == "")
    {
        return;
    }
    qDebug() << ReadData << "(ReadData)";
    QString buffer;
    QString isRegist;
    isRegist = ReadData[1];
    int i = 2;
    while(1)
    {
        if(ReadData.data()[i] == "#")
            break;
        buffer += ReadData.data()[i];
        i++;
    }
    qDebug() << buffer << "(buffer)";
    QSqlQuery query(database);
    //注册
    if(isRegist == "0")
    {
        int rowNum = model->rowCount(); //获得表的行数
        model->insertRow(rowNum); //添加一行
        model->setData(model->index(rowNum,3), "N/A");
        model->setData(model->index(rowNum,4), "N/A");
        model->setData(model->index(rowNum,5), buffer);
        model->setData(model->index(rowNum,6), "0");
        allNums++;
        ui->lineEditAllNum->setText(QString(allNums));
    }
    //有人进入或离开
    else
    {
        //获取系统时间
        QDateTime local(QDateTime::currentDateTime());
        QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
        //查询信息
        QString qbuf = QString("select * from doorinfo where faceid=\"%1\";").arg(buffer);
        query.exec(qbuf);
        query.next();
        QString flag;
        flag = query.value(6).toString();
        //如果未进入
        if(flag == "0")
        {
            qbuf = QString("UPDATE doorinfo SET entrytime = \"%1\"WHERE faceid = \"%2\"").arg(localTime, buffer);
            query.exec(qbuf);
            qbuf = QString("UPDATE doorinfo SET flag = \"%1\"WHERE faceid = \"%2\"").arg("1", buffer);
            query.exec(qbuf);
            iNNums++;
        }
        else if(flag == "1") //已经进入
        {
            qbuf = QString("UPDATE doorinfo SET lefttime = \"%1\"WHERE faceid = \"%2\"").arg(localTime, buffer);
            query.exec(qbuf);
            qbuf = QString("UPDATE doorinfo SET flag = \"%1\"WHERE faceid = \"%2\"").arg("0", buffer);
            query.exec(qbuf);
            iNNums--;
            if(iNNums < 0)
                iNNums = 0;
        }
        qbuf = QString("select * from doorinfo where faceid=\"%1\";").arg(buffer);
        query.exec(qbuf);
        query.next();
        ui->labelId->setText(query.value(0).toString());
        ui->labelName->setText(query.value(1).toString());
        ui->labelSex->setText(query.value(2).toString());
        ui->labelEntryTime->setText(query.value(3).toString());
        ui->labelLeftTime->setText(query.value(4).toString());
    }
    if(iNNums < 0)
        iNNums = 0;
    ui->lineEditInNum->setText(QString::number(iNNums));
    ui->lineEditAllNum->setText(QString::number(allNums));
}

//增加信息
void ManageWidget::on_buttonAdd_released()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "注意", "请将面部对准摄像头。", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        serialPort->write("!");
    }
}

//删除信息
void ManageWidget::on_buttonDelete_released()
{
    int curRow = ui->tableViewInfo->currentIndex().row();
    //获取选中的行
//    model->removeRow(curRow);
    //删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),
                                  QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); //如果不删除，则撤销
    }
    else
    {
//        model->submitAll(); //否则提交，在数据库中删除该行
//        allNums--;
//        QString faceId = model->data(model->index(curRow, 5)).toString();
//        serialPort->write(faceId.toUtf8());
//        ui->lineEditAllNum->setText(QString::number(allNums));
        allNums--;
        QAbstractItemModel *qModel = ui->tableViewInfo->model();
        QString faceId = qModel->data(qModel->index(curRow, 5)).toString();
        if(serialPort->isOpen())
            serialPort->write(faceId.toUtf8());
        ui->lineEditAllNum->setText(QString::number(allNums));
        model->removeRow(curRow);
        model->database().transaction(); //开始事务操作
        if (model->submitAll()) {
            model->database().commit(); //提交
        } else {
            model->database().rollback(); //回滚
        }
    }
}

//撤销修改
void ManageWidget::on_buttonReset_released()
{
    model->revertAll();
}

//提交修改
void ManageWidget::on_buttonSubmit_released()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
    }
}

//刷新
void ManageWidget::on_pushButtonFlesh_released()
{
    //获取总人数
    QSqlQuery query(database);
    QString qbuf = QString("select count(*) from doorinfo where flag='1';");
    query.exec(qbuf);
    query.next();
    iNNums = query.value(0).toInt();
    model->select();
    ui->lineEditInNum->setText(QString::number(iNNums));
    ui->lineEditAllNum->setText(QString::number(allNums));
}
