/********************************************************************************
** Form generated from reading UI file 'busmonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSMONITOR_H
#define UI_BUSMONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BusMonitor
{
public:
    QAction *actionClear;
    QAction *actionExit;
    QAction *actionSave;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblRawData;
    QListView *lstRawData;
    QLabel *lblPDU;
    QPlainTextEdit *txtPDU;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BusMonitor)
    {
        if (BusMonitor->objectName().isEmpty())
            BusMonitor->setObjectName(QString::fromUtf8("BusMonitor"));
        BusMonitor->setWindowModality(Qt::NonModal);
        BusMonitor->resize(564, 400);
        BusMonitor->setMinimumSize(QSize(500, 400));
        BusMonitor->setMaximumSize(QSize(720, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/TV-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        BusMonitor->setWindowIcon(icon);
        actionClear = new QAction(BusMonitor);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/edit-clear-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon1);
        actionClear->setIconVisibleInMenu(true);
        actionExit = new QAction(BusMonitor);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/Close-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionSave = new QAction(BusMonitor);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/save-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        centralwidget = new QWidget(BusMonitor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblRawData = new QLabel(centralwidget);
        lblRawData->setObjectName(QString::fromUtf8("lblRawData"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lblRawData->setFont(font);

        verticalLayout_2->addWidget(lblRawData);

        lstRawData = new QListView(centralwidget);
        lstRawData->setObjectName(QString::fromUtf8("lstRawData"));
        lstRawData->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(8);
        lstRawData->setFont(font1);
        lstRawData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstRawData->setAlternatingRowColors(true);
        lstRawData->setSelectionMode(QAbstractItemView::SingleSelection);
        lstRawData->setSelectionBehavior(QAbstractItemView::SelectRows);
        lstRawData->setSelectionRectVisible(false);

        verticalLayout_2->addWidget(lstRawData);

        lblPDU = new QLabel(centralwidget);
        lblPDU->setObjectName(QString::fromUtf8("lblPDU"));
        lblPDU->setFont(font);
        lblPDU->setText(QString::fromUtf8("ADU"));

        verticalLayout_2->addWidget(lblPDU);

        txtPDU = new QPlainTextEdit(centralwidget);
        txtPDU->setObjectName(QString::fromUtf8("txtPDU"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        txtPDU->setFont(font2);
        txtPDU->setTabChangesFocus(false);
        txtPDU->setReadOnly(true);
        txtPDU->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(txtPDU);


        verticalLayout->addLayout(verticalLayout_2);

        BusMonitor->setCentralWidget(centralwidget);
        toolBar = new QToolBar(BusMonitor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setWindowTitle(QString::fromUtf8("toolBar"));
        BusMonitor->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(BusMonitor);

        QMetaObject::connectSlotsByName(BusMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *BusMonitor)
    {
        BusMonitor->setWindowTitle(QApplication::translate("BusMonitor", "Bus Monitor", nullptr));
        actionClear->setText(QApplication::translate("BusMonitor", "Clear", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("BusMonitor", "Clear", nullptr));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("BusMonitor", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("BusMonitor", "Exit", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("BusMonitor", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("BusMonitor", "Save", nullptr));
#endif // QT_NO_TOOLTIP
        lblRawData->setText(QApplication::translate("BusMonitor", "Raw Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BusMonitor: public Ui_BusMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSMONITOR_H
