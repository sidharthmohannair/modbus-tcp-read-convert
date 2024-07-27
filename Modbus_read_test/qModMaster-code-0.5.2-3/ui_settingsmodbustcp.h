/********************************************************************************
** Form generated from reading UI file 'settingsmodbustcp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSMODBUSTCP_H
#define UI_SETTINGSMODBUSTCP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsModbusTCP
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *lblSlaveIP;
    QLabel *lblTCPPort;
    QLineEdit *leTCPPort;
    QLineEdit *leSlaveIP;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsModbusTCP)
    {
        if (SettingsModbusTCP->objectName().isEmpty())
            SettingsModbusTCP->setObjectName(QString::fromUtf8("SettingsModbusTCP"));
        SettingsModbusTCP->resize(240, 110);
        SettingsModbusTCP->setMinimumSize(QSize(240, 110));
        SettingsModbusTCP->setMaximumSize(QSize(240, 160));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/network-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsModbusTCP->setWindowIcon(icon);
        SettingsModbusTCP->setModal(true);
        verticalLayout = new QVBoxLayout(SettingsModbusTCP);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblSlaveIP = new QLabel(SettingsModbusTCP);
        lblSlaveIP->setObjectName(QString::fromUtf8("lblSlaveIP"));

        gridLayout->addWidget(lblSlaveIP, 1, 0, 1, 1);

        lblTCPPort = new QLabel(SettingsModbusTCP);
        lblTCPPort->setObjectName(QString::fromUtf8("lblTCPPort"));
        lblTCPPort->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblTCPPort, 2, 0, 1, 1);

        leTCPPort = new QLineEdit(SettingsModbusTCP);
        leTCPPort->setObjectName(QString::fromUtf8("leTCPPort"));
        leTCPPort->setMaxLength(5);

        gridLayout->addWidget(leTCPPort, 2, 1, 1, 1);

        leSlaveIP = new QLineEdit(SettingsModbusTCP);
        leSlaveIP->setObjectName(QString::fromUtf8("leSlaveIP"));
        leSlaveIP->setInputMask(QString::fromUtf8("999.999.999.999;_"));

        gridLayout->addWidget(leSlaveIP, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(SettingsModbusTCP);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        lblTCPPort->setBuddy(leTCPPort);
#endif // QT_NO_SHORTCUT

        retranslateUi(SettingsModbusTCP);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsModbusTCP, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsModbusTCP, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsModbusTCP);
    } // setupUi

    void retranslateUi(QDialog *SettingsModbusTCP)
    {
        SettingsModbusTCP->setWindowTitle(QApplication::translate("SettingsModbusTCP", "Modbus TCP Settings", nullptr));
        lblSlaveIP->setText(QApplication::translate("SettingsModbusTCP", "Slave IP", nullptr));
        lblTCPPort->setText(QApplication::translate("SettingsModbusTCP", "TCP Port", nullptr));
        leTCPPort->setInputMask(QString());
        leTCPPort->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingsModbusTCP: public Ui_SettingsModbusTCP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSMODBUSTCP_H
