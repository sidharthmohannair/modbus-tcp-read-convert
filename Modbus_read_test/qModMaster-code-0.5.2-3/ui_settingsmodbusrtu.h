/********************************************************************************
** Form generated from reading UI file 'settingsmodbusrtu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSMODBUSRTU_H
#define UI_SETTINGSMODBUSRTU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsModbusRTU
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QComboBox *cmbDev;
    QLabel *lblDev;
    QLabel *lblBaud;
    QSpinBox *sbPort;
    QComboBox *cmbBaud;
    QComboBox *cmbDataBits;
    QLabel *lblDataBits;
    QLabel *lblRTS;
    QLabel *lblStopBits;
    QComboBox *cmbRTS;
    QComboBox *cmbParity;
    QComboBox *cmbStopBits;
    QLabel *lblParity;
    QLabel *lblPort;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsModbusRTU)
    {
        if (SettingsModbusRTU->objectName().isEmpty())
            SettingsModbusRTU->setObjectName(QString::fromUtf8("SettingsModbusRTU"));
        SettingsModbusRTU->resize(220, 256);
        SettingsModbusRTU->setMinimumSize(QSize(220, 256));
        SettingsModbusRTU->setMaximumSize(QSize(220, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/options-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsModbusRTU->setWindowIcon(icon);
        SettingsModbusRTU->setModal(true);
        verticalLayout = new QVBoxLayout(SettingsModbusRTU);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cmbDev = new QComboBox(SettingsModbusRTU);
        cmbDev->addItem(QString());
        cmbDev->addItem(QString());
        cmbDev->setObjectName(QString::fromUtf8("cmbDev"));
        cmbDev->setEditable(true);

        gridLayout->addWidget(cmbDev, 0, 1, 1, 1);

        lblDev = new QLabel(SettingsModbusRTU);
        lblDev->setObjectName(QString::fromUtf8("lblDev"));

        gridLayout->addWidget(lblDev, 0, 0, 1, 1);

        lblBaud = new QLabel(SettingsModbusRTU);
        lblBaud->setObjectName(QString::fromUtf8("lblBaud"));
        lblBaud->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblBaud, 2, 0, 1, 1);

        sbPort = new QSpinBox(SettingsModbusRTU);
        sbPort->setObjectName(QString::fromUtf8("sbPort"));
        sbPort->setMinimum(1);
        sbPort->setMaximum(128);

        gridLayout->addWidget(sbPort, 1, 1, 1, 1);

        cmbBaud = new QComboBox(SettingsModbusRTU);
        cmbBaud->addItem(QString::fromUtf8("110"));
        cmbBaud->addItem(QString::fromUtf8("300"));
        cmbBaud->addItem(QString::fromUtf8("600"));
        cmbBaud->addItem(QString::fromUtf8("1200"));
        cmbBaud->addItem(QString::fromUtf8("2400"));
        cmbBaud->addItem(QString::fromUtf8("4800"));
        cmbBaud->addItem(QString::fromUtf8("9600"));
        cmbBaud->addItem(QString::fromUtf8("14400"));
        cmbBaud->addItem(QString::fromUtf8("19200"));
        cmbBaud->addItem(QString::fromUtf8("28800"));
        cmbBaud->addItem(QString::fromUtf8("38400"));
        cmbBaud->addItem(QString::fromUtf8("57600"));
        cmbBaud->addItem(QString::fromUtf8("115200"));
        cmbBaud->addItem(QString::fromUtf8("128000"));
        cmbBaud->addItem(QString::fromUtf8("256000"));
        cmbBaud->addItem(QString::fromUtf8("921600"));
        cmbBaud->setObjectName(QString::fromUtf8("cmbBaud"));

        gridLayout->addWidget(cmbBaud, 2, 1, 1, 1);

        cmbDataBits = new QComboBox(SettingsModbusRTU);
        cmbDataBits->addItem(QString::fromUtf8("7"));
        cmbDataBits->addItem(QString::fromUtf8("8"));
        cmbDataBits->setObjectName(QString::fromUtf8("cmbDataBits"));

        gridLayout->addWidget(cmbDataBits, 3, 1, 1, 1);

        lblDataBits = new QLabel(SettingsModbusRTU);
        lblDataBits->setObjectName(QString::fromUtf8("lblDataBits"));
        lblDataBits->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblDataBits, 3, 0, 1, 1);

        lblRTS = new QLabel(SettingsModbusRTU);
        lblRTS->setObjectName(QString::fromUtf8("lblRTS"));
        lblRTS->setText(QString::fromUtf8("RTS"));
        lblRTS->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblRTS, 6, 0, 1, 1);

        lblStopBits = new QLabel(SettingsModbusRTU);
        lblStopBits->setObjectName(QString::fromUtf8("lblStopBits"));
        lblStopBits->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblStopBits, 4, 0, 1, 1);

        cmbRTS = new QComboBox(SettingsModbusRTU);
        cmbRTS->setObjectName(QString::fromUtf8("cmbRTS"));

        gridLayout->addWidget(cmbRTS, 6, 1, 1, 1);

        cmbParity = new QComboBox(SettingsModbusRTU);
        cmbParity->addItem(QString());
        cmbParity->addItem(QString());
        cmbParity->addItem(QString());
        cmbParity->setObjectName(QString::fromUtf8("cmbParity"));

        gridLayout->addWidget(cmbParity, 5, 1, 1, 1);

        cmbStopBits = new QComboBox(SettingsModbusRTU);
        cmbStopBits->addItem(QString::fromUtf8("1"));
        cmbStopBits->addItem(QString::fromUtf8("1.5"));
        cmbStopBits->addItem(QString::fromUtf8("2"));
        cmbStopBits->setObjectName(QString::fromUtf8("cmbStopBits"));

        gridLayout->addWidget(cmbStopBits, 4, 1, 1, 1);

        lblParity = new QLabel(SettingsModbusRTU);
        lblParity->setObjectName(QString::fromUtf8("lblParity"));
        lblParity->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblParity, 5, 0, 1, 1);

        lblPort = new QLabel(SettingsModbusRTU);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));
        lblPort->setMinimumSize(QSize(0, 0));
        lblPort->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblPort, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(SettingsModbusRTU);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        lblBaud->setBuddy(cmbBaud);
        lblDataBits->setBuddy(cmbDataBits);
        lblStopBits->setBuddy(cmbStopBits);
        lblParity->setBuddy(cmbParity);
#endif // QT_NO_SHORTCUT

        retranslateUi(SettingsModbusRTU);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsModbusRTU, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsModbusRTU, SLOT(reject()));

        cmbBaud->setCurrentIndex(-1);
        cmbDataBits->setCurrentIndex(-1);
        cmbParity->setCurrentIndex(-1);
        cmbStopBits->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SettingsModbusRTU);
    } // setupUi

    void retranslateUi(QDialog *SettingsModbusRTU)
    {
        SettingsModbusRTU->setWindowTitle(QApplication::translate("SettingsModbusRTU", "Modbus RTU Settings", nullptr));
        cmbDev->setItemText(0, QApplication::translate("SettingsModbusRTU", "/dev/ttyS", nullptr));
        cmbDev->setItemText(1, QApplication::translate("SettingsModbusRTU", "/dev/ttyUSB", nullptr));

        lblDev->setText(QApplication::translate("SettingsModbusRTU", "Serial device", nullptr));
        lblBaud->setText(QApplication::translate("SettingsModbusRTU", "Baud", nullptr));


        lblDataBits->setText(QApplication::translate("SettingsModbusRTU", "Data Bits", nullptr));
        lblStopBits->setText(QApplication::translate("SettingsModbusRTU", "Stop Bits", nullptr));
        cmbParity->setItemText(0, QApplication::translate("SettingsModbusRTU", "None", nullptr));
        cmbParity->setItemText(1, QApplication::translate("SettingsModbusRTU", "Odd", nullptr));
        cmbParity->setItemText(2, QApplication::translate("SettingsModbusRTU", "Even", nullptr));


        lblParity->setText(QApplication::translate("SettingsModbusRTU", "Parity", nullptr));
        lblPort->setText(QApplication::translate("SettingsModbusRTU", "Serial port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsModbusRTU: public Ui_SettingsModbusRTU {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSMODBUSRTU_H
