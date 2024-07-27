/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblVersion;
    QLabel *lblLibVersion;
    QLabel *lblURL;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(320, 90);
        About->setMinimumSize(QSize(320, 90));
        About->setMaximumSize(QSize(400, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/info16.png"), QSize(), QIcon::Normal, QIcon::Off);
        About->setWindowIcon(icon);
        About->setModal(true);
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblVersion = new QLabel(About);
        lblVersion->setObjectName(QString::fromUtf8("lblVersion"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        lblVersion->setFont(font);
        lblVersion->setText(QString::fromUtf8("QModMaster"));
        lblVersion->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblVersion);

        lblLibVersion = new QLabel(About);
        lblLibVersion->setObjectName(QString::fromUtf8("lblLibVersion"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        lblLibVersion->setFont(font1);
        lblLibVersion->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblLibVersion);

        lblURL = new QLabel(About);
        lblURL->setObjectName(QString::fromUtf8("lblURL"));
        lblURL->setFont(font1);
        lblURL->setText(QString::fromUtf8("http://"));
        lblURL->setAlignment(Qt::AlignCenter);
        lblURL->setOpenExternalLinks(true);

        verticalLayout->addWidget(lblURL);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", nullptr));
        lblLibVersion->setText(QApplication::translate("About", "lib version", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
