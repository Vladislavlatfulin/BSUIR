/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Folder;
    QAction *actionBackup;
    QAction *actionRemove;
    QAction *actionRename;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Search;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *IcloudDrive;
    QPushButton *Desktop;
    QPushButton *Documents;
    QPushButton *Downloads;
    QPushButton *Programs;
    QSpacerItem *verticalSpacer;
    QListView *LvSource;
    QListView *LvBackup;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew_Folder = new QAction(MainWindow);
        actionNew_Folder->setObjectName(QString::fromUtf8("actionNew_Folder"));
        actionBackup = new QAction(MainWindow);
        actionBackup->setObjectName(QString::fromUtf8("actionBackup"));
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QString::fromUtf8("actionRename"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Search = new QPushButton(widget);
        Search->setObjectName(QString::fromUtf8("Search"));

        horizontalLayout->addWidget(Search);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        IcloudDrive = new QPushButton(widget1);
        IcloudDrive->setObjectName(QString::fromUtf8("IcloudDrive"));

        verticalLayout->addWidget(IcloudDrive);

        Desktop = new QPushButton(widget1);
        Desktop->setObjectName(QString::fromUtf8("Desktop"));

        verticalLayout->addWidget(Desktop);

        Documents = new QPushButton(widget1);
        Documents->setObjectName(QString::fromUtf8("Documents"));

        verticalLayout->addWidget(Documents);

        Downloads = new QPushButton(widget1);
        Downloads->setObjectName(QString::fromUtf8("Downloads"));

        verticalLayout->addWidget(Downloads);

        Programs = new QPushButton(widget1);
        Programs->setObjectName(QString::fromUtf8("Programs"));

        verticalLayout->addWidget(Programs);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        splitter->addWidget(widget1);

        horizontalLayout_2->addWidget(splitter);

        LvSource = new QListView(centralwidget);
        LvSource->setObjectName(QString::fromUtf8("LvSource"));

        horizontalLayout_2->addWidget(LvSource);

        LvBackup = new QListView(centralwidget);
        LvBackup->setObjectName(QString::fromUtf8("LvBackup"));

        horizontalLayout_2->addWidget(LvBackup);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionNew_Folder);
        menu->addAction(actionBackup);
        menu->addAction(actionRemove);
        menu->addAction(actionRename);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Folder->setText(QCoreApplication::translate("MainWindow", "New Folder", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Folder->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBackup->setText(QCoreApplication::translate("MainWindow", "Backup", nullptr));
#if QT_CONFIG(shortcut)
        actionBackup->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove->setText(QCoreApplication::translate("MainWindow", "Remove Folder", nullptr));
#if QT_CONFIG(shortcut)
        actionRemove->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRename->setText(QCoreApplication::translate("MainWindow", "Rename", nullptr));
#if QT_CONFIG(shortcut)
        actionRename->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        Search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\261\321\200\320\260\320\275\320\275\320\276\320\265", nullptr));
        IcloudDrive->setText(QCoreApplication::translate("MainWindow", "Icloud drive", nullptr));
        Desktop->setText(QCoreApplication::translate("MainWindow", "Desktop", nullptr));
        Documents->setText(QCoreApplication::translate("MainWindow", "Documents", nullptr));
        Downloads->setText(QCoreApplication::translate("MainWindow", "Downloads", nullptr));
        Programs->setText(QCoreApplication::translate("MainWindow", "Programs", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
