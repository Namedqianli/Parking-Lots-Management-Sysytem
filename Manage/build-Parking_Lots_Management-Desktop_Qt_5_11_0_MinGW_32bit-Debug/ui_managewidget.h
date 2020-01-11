/********************************************************************************
** Form generated from reading UI file 'managewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEWIDGET_H
#define UI_MANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tabLogisticsInfo;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *labelId;
    QLabel *labelName;
    QLabel *labelEntryTime;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *labelBalance;
    QLabel *label_7;
    QLabel *labelLeftTime;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_39;
    QLabel *labelConnectStatus;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonReflsh;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEditInNum;
    QLineEdit *lineEditAllNum;
    QWidget *tabLogisticsChange;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonAdd;
    QPushButton *buttonDelete;
    QPushButton *buttonReset;
    QPushButton *buttonSubmit;
    QPushButton *pushButtonFlesh;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableViewInfo;

    void setupUi(QWidget *ManageWidget)
    {
        if (ManageWidget->objectName().isEmpty())
            ManageWidget->setObjectName(QStringLiteral("ManageWidget"));
        ManageWidget->resize(844, 562);
        gridLayout = new QGridLayout(ManageWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ManageWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(ManageWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabLogisticsInfo = new QWidget();
        tabLogisticsInfo->setObjectName(QStringLiteral("tabLogisticsInfo"));
        gridLayout_4 = new QGridLayout(tabLogisticsInfo);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        splitter = new QSplitter(tabLogisticsInfo);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 6, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 12, 0, 1, 1);

        labelId = new QLabel(groupBox);
        labelId->setObjectName(QStringLiteral("labelId"));

        gridLayout_2->addWidget(labelId, 3, 1, 1, 1);

        labelName = new QLabel(groupBox);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout_2->addWidget(labelName, 1, 1, 1, 1);

        labelEntryTime = new QLabel(groupBox);
        labelEntryTime->setObjectName(QStringLiteral("labelEntryTime"));

        gridLayout_2->addWidget(labelEntryTime, 7, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        labelBalance = new QLabel(groupBox);
        labelBalance->setObjectName(QStringLiteral("labelBalance"));

        gridLayout_2->addWidget(labelBalance, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 7, 0, 1, 1);

        labelLeftTime = new QLabel(groupBox);
        labelLeftTime->setObjectName(QStringLiteral("labelLeftTime"));

        gridLayout_2->addWidget(labelLeftTime, 9, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 9, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_9, 8, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_39 = new QLabel(groupBox_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_3->addWidget(label_39, 9, 1, 1, 2);

        labelConnectStatus = new QLabel(groupBox_2);
        labelConnectStatus->setObjectName(QStringLiteral("labelConnectStatus"));
        labelConnectStatus->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelConnectStatus, 9, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 10, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 5, 3, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_14, 1, 1, 1, 2);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 3, 1, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 9, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 4, 1, 2);

        pushButtonReflsh = new QPushButton(groupBox_2);
        pushButtonReflsh->setObjectName(QStringLiteral("pushButtonReflsh"));

        gridLayout_3->addWidget(pushButtonReflsh, 9, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 9, 5, 1, 1);

        lineEditInNum = new QLineEdit(groupBox_2);
        lineEditInNum->setObjectName(QStringLiteral("lineEditInNum"));
        lineEditInNum->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("3ds"));
        font3.setPointSize(10);
        lineEditInNum->setFont(font3);
        lineEditInNum->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lineEditInNum, 1, 3, 1, 1);

        lineEditAllNum = new QLineEdit(groupBox_2);
        lineEditAllNum->setObjectName(QStringLiteral("lineEditAllNum"));
        lineEditAllNum->setMinimumSize(QSize(0, 50));
        lineEditAllNum->setFont(font3);
        lineEditAllNum->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lineEditAllNum, 3, 3, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_4->addWidget(splitter, 0, 0, 1, 1);

        tabWidget->addTab(tabLogisticsInfo, QString());
        tabLogisticsChange = new QWidget();
        tabLogisticsChange->setObjectName(QStringLiteral("tabLogisticsChange"));
        gridLayout_5 = new QGridLayout(tabLogisticsChange);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_3 = new QGroupBox(tabLogisticsChange);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonAdd = new QPushButton(groupBox_3);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        horizontalLayout->addWidget(buttonAdd);

        buttonDelete = new QPushButton(groupBox_3);
        buttonDelete->setObjectName(QStringLiteral("buttonDelete"));

        horizontalLayout->addWidget(buttonDelete);

        buttonReset = new QPushButton(groupBox_3);
        buttonReset->setObjectName(QStringLiteral("buttonReset"));

        horizontalLayout->addWidget(buttonReset);

        buttonSubmit = new QPushButton(groupBox_3);
        buttonSubmit->setObjectName(QStringLiteral("buttonSubmit"));

        horizontalLayout->addWidget(buttonSubmit);

        pushButtonFlesh = new QPushButton(groupBox_3);
        pushButtonFlesh->setObjectName(QStringLiteral("pushButtonFlesh"));

        horizontalLayout->addWidget(pushButtonFlesh);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 1);

        tableViewInfo = new QTableView(tabLogisticsChange);
        tableViewInfo->setObjectName(QStringLiteral("tableViewInfo"));

        gridLayout_5->addWidget(tableViewInfo, 1, 0, 1, 1);

        tabWidget->addTab(tabLogisticsChange, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(ManageWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManageWidget);
    } // setupUi

    void retranslateUi(QWidget *ManageWidget)
    {
        ManageWidget->setWindowTitle(QApplication::translate("ManageWidget", "ManageWidget", nullptr));
        label->setText(QApplication::translate("ManageWidget", "\345\201\234\350\275\246\345\234\272\347\256\241\347\220\206", nullptr));
        groupBox->setTitle(QApplication::translate("ManageWidget", "\350\275\246\350\276\206\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("ManageWidget", "\350\275\246\344\270\273:", nullptr));
        labelId->setText(QApplication::translate("ManageWidget", "NA", nullptr));
        labelName->setText(QApplication::translate("ManageWidget", "NA", nullptr));
        labelEntryTime->setText(QApplication::translate("ManageWidget", "NA", nullptr));
        label_4->setText(QApplication::translate("ManageWidget", "\350\275\246\347\211\214:", nullptr));
        label_9->setText(QApplication::translate("ManageWidget", "\344\275\231\351\242\235:", nullptr));
        labelBalance->setText(QApplication::translate("ManageWidget", "NA", nullptr));
        label_7->setText(QApplication::translate("ManageWidget", "\350\277\233\345\205\245\346\227\266\351\227\264:", nullptr));
        labelLeftTime->setText(QApplication::translate("ManageWidget", "NA", nullptr));
        label_11->setText(QApplication::translate("ManageWidget", "\347\246\273\345\274\200\346\227\266\351\227\264:", nullptr));
        groupBox_2->setTitle(QApplication::translate("ManageWidget", "\347\212\266\346\200\201", nullptr));
        label_39->setText(QApplication::translate("ManageWidget", "\350\256\241\350\264\271\346\234\272\345\231\250\347\212\266\346\200\201", nullptr));
        labelConnectStatus->setText(QApplication::translate("ManageWidget", "\346\234\252\350\277\236\346\216\245", nullptr));
        label_14->setText(QApplication::translate("ManageWidget", "\345\201\234\350\275\246\345\234\272\350\275\246\350\276\206\346\225\260\351\207\217", nullptr));
        label_15->setText(QApplication::translate("ManageWidget", "\350\275\246\350\276\206\346\200\273\346\225\260", nullptr));
        pushButtonReflsh->setText(QApplication::translate("ManageWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabLogisticsInfo), QApplication::translate("ManageWidget", "\346\203\205\345\206\265", nullptr));
        groupBox_3->setTitle(QApplication::translate("ManageWidget", "\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        buttonAdd->setText(QApplication::translate("ManageWidget", "\345\242\236\345\212\240", nullptr));
        buttonDelete->setText(QApplication::translate("ManageWidget", "\345\210\240\351\231\244", nullptr));
        buttonReset->setText(QApplication::translate("ManageWidget", "\346\222\244\351\224\200\344\277\256\346\224\271", nullptr));
        buttonSubmit->setText(QApplication::translate("ManageWidget", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        pushButtonFlesh->setText(QApplication::translate("ManageWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabLogisticsChange), QApplication::translate("ManageWidget", "\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageWidget: public Ui_ManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEWIDGET_H
