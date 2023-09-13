/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *table;
    QComboBox *comboBox;
    QLabel *label;
    QRadioButton *maj;
    QRadioButton *min;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        table = new QTableWidget(centralwidget);
        table->setObjectName("table");
        table->setGeometry(QRect(10, 160, 771, 222));
        table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(190, 30, 82, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 10, 63, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        maj = new QRadioButton(centralwidget);
        maj->setObjectName("maj");
        maj->setGeometry(QRect(320, 40, 112, 26));
        maj->setChecked(true);
        min = new QRadioButton(centralwidget);
        min->setObjectName("min");
        min->setGeometry(QRect(320, 100, 112, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Key:", nullptr));
        maj->setText(QCoreApplication::translate("MainWindow", "Major", nullptr));
        min->setText(QCoreApplication::translate("MainWindow", "Minor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
