/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_archive;
    QAction *actionSave_archive_copy_as;
    QAction *actionChange_drive;
    QAction *actionSet_default_password;
    QAction *actionCopy_files_to_clipboard;
    QAction *actionPaste_files_from_clipboard;
    QAction *actionSelect_all;
    QAction *actionSelect_group;
    QAction *actionDeselect_group;
    QAction *actionExit;
    QAction *actionAdd_files_to_archive;
    QAction *actionExtract_to;
    QAction *actionDelete_file;
    QAction *actionRename_file;
    QAction *actionAbout_QtArchive;
    QAction *actionUp_on_level;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *subToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1082, 661);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/img/data-storage.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_archive = new QAction(MainWindow);
        actionOpen_archive->setObjectName(QString::fromUtf8("actionOpen_archive"));
        actionSave_archive_copy_as = new QAction(MainWindow);
        actionSave_archive_copy_as->setObjectName(QString::fromUtf8("actionSave_archive_copy_as"));
        actionChange_drive = new QAction(MainWindow);
        actionChange_drive->setObjectName(QString::fromUtf8("actionChange_drive"));
        actionSet_default_password = new QAction(MainWindow);
        actionSet_default_password->setObjectName(QString::fromUtf8("actionSet_default_password"));
        actionCopy_files_to_clipboard = new QAction(MainWindow);
        actionCopy_files_to_clipboard->setObjectName(QString::fromUtf8("actionCopy_files_to_clipboard"));
        actionPaste_files_from_clipboard = new QAction(MainWindow);
        actionPaste_files_from_clipboard->setObjectName(QString::fromUtf8("actionPaste_files_from_clipboard"));
        actionSelect_all = new QAction(MainWindow);
        actionSelect_all->setObjectName(QString::fromUtf8("actionSelect_all"));
        actionSelect_group = new QAction(MainWindow);
        actionSelect_group->setObjectName(QString::fromUtf8("actionSelect_group"));
        actionDeselect_group = new QAction(MainWindow);
        actionDeselect_group->setObjectName(QString::fromUtf8("actionDeselect_group"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdd_files_to_archive = new QAction(MainWindow);
        actionAdd_files_to_archive->setObjectName(QString::fromUtf8("actionAdd_files_to_archive"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/img/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_files_to_archive->setIcon(icon1);
        actionExtract_to = new QAction(MainWindow);
        actionExtract_to->setObjectName(QString::fromUtf8("actionExtract_to"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/img/ExtractTo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtract_to->setIcon(icon2);
        actionDelete_file = new QAction(MainWindow);
        actionDelete_file->setObjectName(QString::fromUtf8("actionDelete_file"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/img/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_file->setIcon(icon3);
        actionRename_file = new QAction(MainWindow);
        actionRename_file->setObjectName(QString::fromUtf8("actionRename_file"));
        actionAbout_QtArchive = new QAction(MainWindow);
        actionAbout_QtArchive->setObjectName(QString::fromUtf8("actionAbout_QtArchive"));
        actionUp_on_level = new QAction(MainWindow);
        actionUp_on_level->setObjectName(QString::fromUtf8("actionUp_on_level"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/img/Arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUp_on_level->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        QFont font;
        font.setPointSize(11);
        listView->setFont(font);

        horizontalLayout->addWidget(listView);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFont(font);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        subToolBar = new QToolBar(MainWindow);
        subToolBar->setObjectName(QString::fromUtf8("subToolBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(subToolBar->sizePolicy().hasHeightForWidth());
        subToolBar->setSizePolicy(sizePolicy);
        subToolBar->setFont(font);
        subToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        MainWindow->addToolBar(Qt::TopToolBarArea, subToolBar);
        MainWindow->insertToolBarBreak(subToolBar);

        mainToolBar->addAction(actionAdd_files_to_archive);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExtract_to);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDelete_file);
        mainToolBar->addSeparator();
        subToolBar->addAction(actionUp_on_level);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QtArchiver", nullptr));
        actionOpen_archive->setText(QCoreApplication::translate("MainWindow", "Open archive", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_archive->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_archive_copy_as->setText(QCoreApplication::translate("MainWindow", "Save archive copy as...", nullptr));
        actionChange_drive->setText(QCoreApplication::translate("MainWindow", "Change drive", nullptr));
#if QT_CONFIG(shortcut)
        actionChange_drive->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSet_default_password->setText(QCoreApplication::translate("MainWindow", "Set default password", nullptr));
#if QT_CONFIG(shortcut)
        actionSet_default_password->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy_files_to_clipboard->setText(QCoreApplication::translate("MainWindow", "Copy files to clipboard", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy_files_to_clipboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste_files_from_clipboard->setText(QCoreApplication::translate("MainWindow", "Paste files from clipboard", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste_files_from_clipboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_all->setText(QCoreApplication::translate("MainWindow", "Select all", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_all->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_group->setText(QCoreApplication::translate("MainWindow", "Select group", nullptr));
        actionDeselect_group->setText(QCoreApplication::translate("MainWindow", "Deselect group", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAdd_files_to_archive->setText(QCoreApplication::translate("MainWindow", "Add files to archive", nullptr));
        actionAdd_files_to_archive->setIconText(QCoreApplication::translate("MainWindow", "Add", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_files_to_archive->setShortcut(QCoreApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExtract_to->setText(QCoreApplication::translate("MainWindow", "Extract to...", nullptr));
#if QT_CONFIG(shortcut)
        actionExtract_to->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_file->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete_file->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRename_file->setText(QCoreApplication::translate("MainWindow", "Rename file", nullptr));
#if QT_CONFIG(shortcut)
        actionRename_file->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_QtArchive->setText(QCoreApplication::translate("MainWindow", "About QtArchive", nullptr));
        actionUp_on_level->setText(QCoreApplication::translate("MainWindow", "Up on level", nullptr));
#if QT_CONFIG(shortcut)
        actionUp_on_level->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        subToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
