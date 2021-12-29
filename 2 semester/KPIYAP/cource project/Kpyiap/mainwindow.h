#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fileoperation.h"
#include "dialog.h"
#include <QKeyEvent>
#include <QShortcut>
#include "button.h"
#include <QDesktopServices>
#include <QProcess>
#include <QStringListModel>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void CreateFolder(const QString &fileName);
  void RenameFolder(const QString newFileName);

  void on_LvSource_doubleClicked(const QModelIndex &index);

  void on_Desktop_clicked();

  void on_actionNew_Folder_triggered();

  void on_actionBackup_triggered();

  void slotShortcutCmdB();

  void slotShortcutCmdR();

  void slotShortcutCmdF();

  void slotShortcutCmdD();

  void on_LvSource_clicked(const QModelIndex &index);

  void on_actionRemove_triggered();

  void on_actionRename_triggered();

  void on_Search_clicked();

private:
  QShortcut       *keyCmdB;
  QShortcut       *keyCmdR;
  QShortcut       *keyCmdF;
  QShortcut       *keyCmdD;
  Ui::MainWindow       *ui;
  QFileSystemModel  *model;
  FileOperation *operation;
  Button *button;

  void printQMessage(QString title, QString message);


};
#endif // MAINWINDOW_H
