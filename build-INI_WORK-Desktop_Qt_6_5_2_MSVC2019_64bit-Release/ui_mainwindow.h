/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *save_action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QComboBox *listOfGroups;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(508, 357);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(508, 357));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        save_action = new QAction(MainWindow);
        save_action->setObjectName("save_action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView::section\n"
"{\n"
"  border: none;\n"
"  background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QHeaderView::section:horizontal\n"
"{\n"
"  border-bottom: 1px solid #d8d8d8;\n"
"  border-right: 1px solid #d8d8d8;\n"
"  font-size: 9pt;\n"
"}\n"
"\n"
"QHeaderView::section:vertical\n"
"{\n"
"  border-right: 1px solid #d8d8d8;\n"
"  border-bottom: 1px solid #d8d8d8;\n"
"  font-size: 9pt;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section\n"
"{\n"
"  border: none;\n"
"  border-bottom: 1px solid #d8d8d8;\n"
"  border-right: 1px solid #d8d8d8;\n"
"  background-color: #ffffff;\n"
"}\n"
"\n"
"QTableWidget\n"
"{\n"
"	border:  none;\n"
"}\n"
"\n"
"QTableWidget::item:hover\n"
"{\n"
"	background-color: rgba(0, 0, 0, 45%);\n"
"	color: white;\n"
"}"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        listOfGroups = new QComboBox(centralwidget);
        listOfGroups->addItem(QString());
        listOfGroups->addItem(QString());
        listOfGroups->addItem(QString());
        listOfGroups->addItem(QString());
        listOfGroups->addItem(QString());
        listOfGroups->setObjectName("listOfGroups");

        gridLayout->addWidget(listOfGroups, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 508, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(save_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        save_action->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        save_action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        listOfGroups->setItemText(0, QCoreApplication::translate("MainWindow", "RECEIVER", nullptr));
        listOfGroups->setItemText(1, QCoreApplication::translate("MainWindow", "SOURCE", nullptr));
        listOfGroups->setItemText(2, QCoreApplication::translate("MainWindow", "MOTION", nullptr));
        listOfGroups->setItemText(3, QCoreApplication::translate("MainWindow", "SENSORS", nullptr));
        listOfGroups->setItemText(4, QCoreApplication::translate("MainWindow", "PROGRAMM", nullptr));

        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
