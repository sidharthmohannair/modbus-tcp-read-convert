/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpinBox *sbResponseTimeout;
    QLabel *lblTimeout;
    QLabel *lblMaxNoOfRawDataLines;
    QSpinBox *sbMaxNoOfRawDataLines;
    QSpinBox *sbBaseAddr;
    QLabel *lblBaseAddr;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(220, 134);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Settings->sizePolicy().hasHeightForWidth());
        Settings->setSizePolicy(sizePolicy);
        Settings->setMinimumSize(QSize(220, 134));
        Settings->setMaximumSize(QSize(320, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/options-16.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sbResponseTimeout = new QSpinBox(Settings);
        sbResponseTimeout->setObjectName(QString::fromUtf8("sbResponseTimeout"));
        sbResponseTimeout->setMinimum(0);
        sbResponseTimeout->setMaximum(20);

        gridLayout->addWidget(sbResponseTimeout, 1, 2, 1, 1);

        lblTimeout = new QLabel(Settings);
        lblTimeout->setObjectName(QString::fromUtf8("lblTimeout"));
        lblTimeout->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblTimeout, 1, 1, 1, 1);

        lblMaxNoOfRawDataLines = new QLabel(Settings);
        lblMaxNoOfRawDataLines->setObjectName(QString::fromUtf8("lblMaxNoOfRawDataLines"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblMaxNoOfRawDataLines->sizePolicy().hasHeightForWidth());
        lblMaxNoOfRawDataLines->setSizePolicy(sizePolicy1);
        lblMaxNoOfRawDataLines->setMinimumSize(QSize(132, 0));
        lblMaxNoOfRawDataLines->setMaximumSize(QSize(16777215, 16777215));
        lblMaxNoOfRawDataLines->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblMaxNoOfRawDataLines, 0, 1, 1, 1);

        sbMaxNoOfRawDataLines = new QSpinBox(Settings);
        sbMaxNoOfRawDataLines->setObjectName(QString::fromUtf8("sbMaxNoOfRawDataLines"));
        sizePolicy1.setHeightForWidth(sbMaxNoOfRawDataLines->sizePolicy().hasHeightForWidth());
        sbMaxNoOfRawDataLines->setSizePolicy(sizePolicy1);
        sbMaxNoOfRawDataLines->setMinimumSize(QSize(50, 0));
        sbMaxNoOfRawDataLines->setMaximumSize(QSize(75, 16777215));
        sbMaxNoOfRawDataLines->setMinimum(1);
        sbMaxNoOfRawDataLines->setMaximum(600);
        sbMaxNoOfRawDataLines->setSingleStep(60);
        sbMaxNoOfRawDataLines->setValue(60);

        gridLayout->addWidget(sbMaxNoOfRawDataLines, 0, 2, 1, 1);

        sbBaseAddr = new QSpinBox(Settings);
        sbBaseAddr->setObjectName(QString::fromUtf8("sbBaseAddr"));
        sbBaseAddr->setMaximum(1);
        sbBaseAddr->setValue(0);

        gridLayout->addWidget(sbBaseAddr, 2, 2, 1, 1);

        lblBaseAddr = new QLabel(Settings);
        lblBaseAddr->setObjectName(QString::fromUtf8("lblBaseAddr"));

        gridLayout->addWidget(lblBaseAddr, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", nullptr));
        lblTimeout->setText(QApplication::translate("Settings", "Response Timeout (sec)", nullptr));
        lblMaxNoOfRawDataLines->setText(QApplication::translate("Settings", "Max No Of Bus Monitor Lines", nullptr));
        lblBaseAddr->setText(QApplication::translate("Settings", "Base Addr", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
