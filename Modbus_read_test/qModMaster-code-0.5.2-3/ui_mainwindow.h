/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "src/infobar.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSerial_RTU;
    QAction *actionTCP;
    QAction *actionAbout;
    QAction *actionBus_Monitor;
    QAction *actionSettings;
    QAction *actionRead_Write;
    QAction *actionConnect;
    QAction *actionScan;
    QAction *actionReset_Counters;
    QAction *actionSimplified_Chinese_zh_CN;
    QAction *actionTraditional_Chinese_zh_TW;
    QAction *actionEnglish_en_US;
    QAction *actionOpenLogFile;
    QAction *actionClear;
    QAction *actionModbus_Manual;
    QAction *actionLoad_Session;
    QAction *actionSave_Session;
    QAction *actionHeaders;
    QAction *actionTools;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    InfoBar *infobar;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_1;
    QHBoxLayout *horizontalLayout;
    QLabel *lblModbusMode;
    QComboBox *cmbModbusMode;
    QLabel *lblSlave;
    QSpinBox *sbSlaveID;
    QLabel *lblScan;
    QSpinBox *spInterval;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblFunctionCode;
    QComboBox *cmbFunctionCode;
    QLabel *lblStartAddress;
    QSpinBox *sbStartAddress;
    QComboBox *cmbStartAddrBase;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblNoOfCoils;
    QSpinBox *sbNoOfRegs;
    QLabel *lblDataFormat;
    QComboBox *cmbBase;
    QCheckBox *chkSigned;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tblRegisters;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuCommands;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(564, 400);
        MainWindow->setMinimumSize(QSize(564, 400));
        MainWindow->setMaximumSize(QSize(720, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/connect-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/exit-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionExit->setIconVisibleInMenu(true);
        actionSerial_RTU = new QAction(MainWindow);
        actionSerial_RTU->setObjectName(QString::fromUtf8("actionSerial_RTU"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/serial-pot-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSerial_RTU->setIcon(icon2);
        actionSerial_RTU->setText(QString::fromUtf8("Modbus RTU..."));
        actionSerial_RTU->setIconVisibleInMenu(true);
        actionTCP = new QAction(MainWindow);
        actionTCP->setObjectName(QString::fromUtf8("actionTCP"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/ethernet-port-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTCP->setIcon(icon3);
        actionTCP->setText(QString::fromUtf8("Modbus TCP..."));
        actionTCP->setIconVisibleInMenu(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/info-sign-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionAbout->setIconVisibleInMenu(true);
        actionBus_Monitor = new QAction(MainWindow);
        actionBus_Monitor->setObjectName(QString::fromUtf8("actionBus_Monitor"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/TV-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBus_Monitor->setIcon(icon5);
        actionBus_Monitor->setIconVisibleInMenu(true);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/options-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon6);
        actionSettings->setIconVisibleInMenu(true);
        actionRead_Write = new QAction(MainWindow);
        actionRead_Write->setObjectName(QString::fromUtf8("actionRead_Write"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/data-sort-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRead_Write->setIcon(icon7);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionConnect->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/plug-disconnect-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/icons/plug-connect-16.png"), QSize(), QIcon::Normal, QIcon::On);
        actionConnect->setIcon(icon8);
        actionScan = new QAction(MainWindow);
        actionScan->setObjectName(QString::fromUtf8("actionScan"));
        actionScan->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/cyclic-process-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScan->setIcon(icon9);
        actionReset_Counters = new QAction(MainWindow);
        actionReset_Counters->setObjectName(QString::fromUtf8("actionReset_Counters"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/reset-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset_Counters->setIcon(icon10);
        actionSimplified_Chinese_zh_CN = new QAction(MainWindow);
        actionSimplified_Chinese_zh_CN->setObjectName(QString::fromUtf8("actionSimplified_Chinese_zh_CN"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/China-flag-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSimplified_Chinese_zh_CN->setIcon(icon11);
        actionSimplified_Chinese_zh_CN->setText(QString::fromUtf8("\347\256\200\344\275\223\344\270\255\346\226\207 (zh_CN)"));
        actionSimplified_Chinese_zh_CN->setIconText(QString::fromUtf8("\347\256\200\344\275\223\344\270\255\346\226\207 (zh_CN)"));
#ifndef QT_NO_TOOLTIP
        actionSimplified_Chinese_zh_CN->setToolTip(QString::fromUtf8("\347\256\200\344\275\223\344\270\255\346\226\207 (zh_CN)"));
#endif // QT_NO_TOOLTIP
        actionSimplified_Chinese_zh_CN->setVisible(false);
        actionTraditional_Chinese_zh_TW = new QAction(MainWindow);
        actionTraditional_Chinese_zh_TW->setObjectName(QString::fromUtf8("actionTraditional_Chinese_zh_TW"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/Taiwan-flag-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTraditional_Chinese_zh_TW->setIcon(icon12);
        actionTraditional_Chinese_zh_TW->setText(QString::fromUtf8("\347\271\201\351\253\224\344\270\255\346\226\207 (zh_TW)"));
        actionTraditional_Chinese_zh_TW->setIconText(QString::fromUtf8("\347\271\201\351\253\224\344\270\255\346\226\207 (zh_TW)"));
#ifndef QT_NO_TOOLTIP
        actionTraditional_Chinese_zh_TW->setToolTip(QString::fromUtf8("\347\271\201\351\253\224\344\270\255\346\226\207 (zh_TW)"));
#endif // QT_NO_TOOLTIP
        actionTraditional_Chinese_zh_TW->setVisible(false);
        actionEnglish_en_US = new QAction(MainWindow);
        actionEnglish_en_US->setObjectName(QString::fromUtf8("actionEnglish_en_US"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/usa-flag-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnglish_en_US->setIcon(icon13);
        actionEnglish_en_US->setText(QString::fromUtf8("English (en_US)"));
        actionEnglish_en_US->setIconText(QString::fromUtf8("English (en_US)"));
#ifndef QT_NO_TOOLTIP
        actionEnglish_en_US->setToolTip(QString::fromUtf8("English (en_US)"));
#endif // QT_NO_TOOLTIP
        actionEnglish_en_US->setVisible(false);
        actionOpenLogFile = new QAction(MainWindow);
        actionOpenLogFile->setObjectName(QString::fromUtf8("actionOpenLogFile"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/text-x-log-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenLogFile->setIcon(icon14);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/edit-clear-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon15);
        actionModbus_Manual = new QAction(MainWindow);
        actionModbus_Manual->setObjectName(QString::fromUtf8("actionModbus_Manual"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/help-desk-icon-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModbus_Manual->setIcon(icon16);
        actionLoad_Session = new QAction(MainWindow);
        actionLoad_Session->setObjectName(QString::fromUtf8("actionLoad_Session"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/document-import-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Session->setIcon(icon17);
        actionSave_Session = new QAction(MainWindow);
        actionSave_Session->setObjectName(QString::fromUtf8("actionSave_Session"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/document-export-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Session->setIcon(icon18);
        actionHeaders = new QAction(MainWindow);
        actionHeaders->setObjectName(QString::fromUtf8("actionHeaders"));
        actionHeaders->setCheckable(true);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons/Header16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHeaders->setIcon(icon19);
        actionTools = new QAction(MainWindow);
        actionTools->setObjectName(QString::fromUtf8("actionTools"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons/tools-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTools->setIcon(icon20);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infobar = new InfoBar(centralWidget);
        infobar->setObjectName(QString::fromUtf8("infobar"));
        horizontalLayout_2 = new QHBoxLayout(infobar);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addWidget(infobar);

        frame_1 = new QFrame(centralWidget);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        frame_1->setMinimumSize(QSize(0, 36));
        frame_1->setFrameShape(QFrame::Box);
        frame_1->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame_1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 6, -1, 6);
        lblModbusMode = new QLabel(frame_1);
        lblModbusMode->setObjectName(QString::fromUtf8("lblModbusMode"));
        lblModbusMode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblModbusMode);

        cmbModbusMode = new QComboBox(frame_1);
        cmbModbusMode->addItem(QString::fromUtf8("RTU"));
        cmbModbusMode->addItem(QString::fromUtf8("TCP"));
        cmbModbusMode->setObjectName(QString::fromUtf8("cmbModbusMode"));

        horizontalLayout->addWidget(cmbModbusMode);

        lblSlave = new QLabel(frame_1);
        lblSlave->setObjectName(QString::fromUtf8("lblSlave"));
        lblSlave->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblSlave);

        sbSlaveID = new QSpinBox(frame_1);
        sbSlaveID->setObjectName(QString::fromUtf8("sbSlaveID"));
        sbSlaveID->setMinimum(0);
        sbSlaveID->setMaximum(255);
        sbSlaveID->setValue(1);

        horizontalLayout->addWidget(sbSlaveID);

        lblScan = new QLabel(frame_1);
        lblScan->setObjectName(QString::fromUtf8("lblScan"));

        horizontalLayout->addWidget(lblScan);

        spInterval = new QSpinBox(frame_1);
        spInterval->setObjectName(QString::fromUtf8("spInterval"));
        spInterval->setMinimum(1000);
        spInterval->setMaximum(10000);
        spInterval->setSingleStep(500);

        horizontalLayout->addWidget(spInterval);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame_1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 36));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 6, -1, 6);
        lblFunctionCode = new QLabel(frame_2);
        lblFunctionCode->setObjectName(QString::fromUtf8("lblFunctionCode"));
        lblFunctionCode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblFunctionCode);

        cmbFunctionCode = new QComboBox(frame_2);
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->addItem(QString());
        cmbFunctionCode->setObjectName(QString::fromUtf8("cmbFunctionCode"));
        cmbFunctionCode->setFrame(true);

        horizontalLayout_4->addWidget(cmbFunctionCode);

        lblStartAddress = new QLabel(frame_2);
        lblStartAddress->setObjectName(QString::fromUtf8("lblStartAddress"));
        lblStartAddress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblStartAddress);

        sbStartAddress = new QSpinBox(frame_2);
        sbStartAddress->setObjectName(QString::fromUtf8("sbStartAddress"));
        sbStartAddress->setMaximum(65535);
        sbStartAddress->setDisplayIntegerBase(10);

        horizontalLayout_4->addWidget(sbStartAddress);

        cmbStartAddrBase = new QComboBox(frame_2);
        cmbStartAddrBase->addItem(QString());
        cmbStartAddrBase->addItem(QString());
        cmbStartAddrBase->setObjectName(QString::fromUtf8("cmbStartAddrBase"));

        horizontalLayout_4->addWidget(cmbStartAddrBase);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 36));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 6, -1, -1);
        lblNoOfCoils = new QLabel(frame_3);
        lblNoOfCoils->setObjectName(QString::fromUtf8("lblNoOfCoils"));
        lblNoOfCoils->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblNoOfCoils);

        sbNoOfRegs = new QSpinBox(frame_3);
        sbNoOfRegs->setObjectName(QString::fromUtf8("sbNoOfRegs"));
        sbNoOfRegs->setMinimum(1);
        sbNoOfRegs->setMaximum(2000);

        horizontalLayout_3->addWidget(sbNoOfRegs);

        lblDataFormat = new QLabel(frame_3);
        lblDataFormat->setObjectName(QString::fromUtf8("lblDataFormat"));
        lblDataFormat->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lblDataFormat);

        cmbBase = new QComboBox(frame_3);
        cmbBase->addItem(QString());
        cmbBase->addItem(QString());
        cmbBase->addItem(QString());
        cmbBase->setObjectName(QString::fromUtf8("cmbBase"));

        horizontalLayout_3->addWidget(cmbBase);

        chkSigned = new QCheckBox(frame_3);
        chkSigned->setObjectName(QString::fromUtf8("chkSigned"));
        chkSigned->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(chkSigned);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(frame_3);

        tblRegisters = new QTableView(centralWidget);
        tblRegisters->setObjectName(QString::fromUtf8("tblRegisters"));
        tblRegisters->setCornerButtonEnabled(false);
        tblRegisters->horizontalHeader()->setVisible(true);
        tblRegisters->horizontalHeader()->setHighlightSections(true);
        tblRegisters->verticalHeader()->setVisible(true);
        tblRegisters->verticalHeader()->setHighlightSections(true);

        verticalLayout->addWidget(tblRegisters);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 564, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuCommands = new QMenu(menuBar);
        menuCommands->setObjectName(QString::fromUtf8("menuCommands"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setAutoFillBackground(false);
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        lblModbusMode->setBuddy(cmbModbusMode);
        lblSlave->setBuddy(sbSlaveID);
        lblFunctionCode->setBuddy(cmbFunctionCode);
        lblStartAddress->setBuddy(sbStartAddress);
        lblNoOfCoils->setBuddy(sbNoOfRegs);
        lblDataFormat->setBuddy(sbStartAddress);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuCommands->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_Session);
        menuFile->addAction(actionSave_Session);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionSerial_RTU);
        menuOptions->addAction(actionTCP);
        menuOptions->addSeparator();
        menuOptions->addAction(actionSettings);
        menuHelp->addAction(actionModbus_Manual);
        menuHelp->addAction(actionAbout);
        menuView->addAction(actionOpenLogFile);
        menuView->addAction(actionBus_Monitor);
        menuView->addAction(actionTools);
        menuView->addSeparator();
        menuView->addAction(actionHeaders);
        menuCommands->addAction(actionConnect);
        menuCommands->addAction(actionRead_Write);
        menuCommands->addAction(actionScan);
        menuCommands->addAction(actionClear);
        menuCommands->addAction(actionReset_Counters);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        cmbStartAddrBase->setCurrentIndex(0);
        cmbBase->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QModMaster", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", nullptr));
        actionBus_Monitor->setText(QApplication::translate("MainWindow", "Bus Monitor", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings...", nullptr));
        actionRead_Write->setText(QApplication::translate("MainWindow", "Read / Write", nullptr));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        actionScan->setText(QApplication::translate("MainWindow", "Scan", nullptr));
        actionReset_Counters->setText(QApplication::translate("MainWindow", "Reset Counters", nullptr));
        actionOpenLogFile->setText(QApplication::translate("MainWindow", "Log File", nullptr));
        actionClear->setText(QApplication::translate("MainWindow", "Clear Table", nullptr));
        actionModbus_Manual->setText(QApplication::translate("MainWindow", "Modbus Manual", nullptr));
        actionLoad_Session->setText(QApplication::translate("MainWindow", "Load Session...", nullptr));
        actionSave_Session->setText(QApplication::translate("MainWindow", "Save Session...", nullptr));
        actionHeaders->setText(QApplication::translate("MainWindow", "Headers", nullptr));
        actionTools->setText(QApplication::translate("MainWindow", "Tools", nullptr));
        lblModbusMode->setText(QApplication::translate("MainWindow", "Modbus Mode", nullptr));

        lblSlave->setText(QApplication::translate("MainWindow", "Slave Addr", nullptr));
        lblScan->setText(QApplication::translate("MainWindow", "Scan Rate (ms)", nullptr));
        lblFunctionCode->setText(QApplication::translate("MainWindow", "Function Code", nullptr));
        cmbFunctionCode->setItemText(0, QApplication::translate("MainWindow", "Read Coils (0x01)", nullptr));
        cmbFunctionCode->setItemText(1, QApplication::translate("MainWindow", "Read Discrete Inputs (0x02)", nullptr));
        cmbFunctionCode->setItemText(2, QApplication::translate("MainWindow", "Read Holding Registers (0x03)", nullptr));
        cmbFunctionCode->setItemText(3, QApplication::translate("MainWindow", "Read Input Registers (0x04)", nullptr));
        cmbFunctionCode->setItemText(4, QApplication::translate("MainWindow", "Write Single Coil (0x05)", nullptr));
        cmbFunctionCode->setItemText(5, QApplication::translate("MainWindow", "Write Single Register (0x06)", nullptr));
        cmbFunctionCode->setItemText(6, QApplication::translate("MainWindow", "Write Multiple Coils (0x0f)", nullptr));
        cmbFunctionCode->setItemText(7, QApplication::translate("MainWindow", "Write Multiple Registers (0x10)", nullptr));

        lblStartAddress->setText(QApplication::translate("MainWindow", "Start Address", nullptr));
        cmbStartAddrBase->setItemText(0, QApplication::translate("MainWindow", "Dec", nullptr));
        cmbStartAddrBase->setItemText(1, QApplication::translate("MainWindow", "Hex", nullptr));

        lblNoOfCoils->setText(QApplication::translate("MainWindow", "Number of Coils", nullptr));
        lblDataFormat->setText(QApplication::translate("MainWindow", "Data Format", nullptr));
        cmbBase->setItemText(0, QApplication::translate("MainWindow", "Bin", nullptr));
        cmbBase->setItemText(1, QApplication::translate("MainWindow", "Dec", nullptr));
        cmbBase->setItemText(2, QApplication::translate("MainWindow", "Hex", nullptr));

        cmbBase->setCurrentText(QApplication::translate("MainWindow", "Dec", nullptr));
        chkSigned->setText(QApplication::translate("MainWindow", "Signed", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuCommands->setTitle(QApplication::translate("MainWindow", "Commands", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
