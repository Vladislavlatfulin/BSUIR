#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  model = new QFileSystemModel(this);
  operation = new FileOperation(this);
  model -> setFilter(QDir::QDir::AllEntries);

  model -> setRootPath("");
  ui -> LvBackup -> setModel(model);
  ui -> LvSource -> setModel(model);
  connect(ui->LvBackup, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_LvSource_doubleClicked(QModelIndex)));
  connect(ui->IcloudDrive, SIGNAL(clicked()), this, SLOT(on_Desktop_clicked()));
  connect(ui->Documents, SIGNAL(clicked()), this, SLOT(on_Desktop_clicked()));
  connect(ui->Programs, SIGNAL(clicked()), this, SLOT(on_Desktop_clicked()));
  connect(ui->Downloads, SIGNAL(clicked()), this, SLOT(on_Desktop_clicked()));

  keyCmdB = new QShortcut(this);
  keyCmdB->setKey(Qt::CTRL|Qt::Key_B);
  connect(keyCmdB, SIGNAL(activated()), this, SLOT(slotShortcutCmdB()));

  keyCmdF = new QShortcut(this);
  keyCmdF->setKey(Qt::CTRL|Qt::Key_F);
  connect(keyCmdF, SIGNAL(activated()), this, SLOT(slotShortcutCmdF()));

  keyCmdD = new QShortcut(this);
  keyCmdD->setKey(Qt::CTRL|Qt::Key_D);
  connect(keyCmdD, SIGNAL(activated()), this, SLOT(slotShortcutCmdD()));

  keyCmdR = new QShortcut(this);
  keyCmdR->setKey(Qt::CTRL|Qt::Key_R);
  connect(keyCmdR, SIGNAL(activated()), this, SLOT(slotShortcutCmdR()));

}

MainWindow::~MainWindow()
{
  delete ui;
  delete operation;
  delete model;
}


void MainWindow::slotShortcutCmdB() {
  on_actionBackup_triggered();
}

void MainWindow::slotShortcutCmdF() {
  on_actionNew_Folder_triggered();
}

void MainWindow::slotShortcutCmdD() {
  on_actionRemove_triggered();
}

void MainWindow::slotShortcutCmdR() {
  on_actionRename_triggered();
}

void MainWindow::on_LvSource_doubleClicked(const QModelIndex &index)
{
  QListView *listView = (QListView*)sender();
  QFileInfo fileInfo = model -> fileInfo(index);
  bool isExe = false;
  operation -> SetFolderPath(model -> fileInfo(index).absoluteFilePath());
  if (fileInfo.fileName() == "..") {
      QDir dir = fileInfo.dir();
      dir.cdUp();
      listView -> setRootIndex(model -> index(dir.absolutePath()));
    }
  else if (fileInfo.fileName() == ".") {
      listView -> setRootIndex(model -> index(""));
    }
  else if (fileInfo.isExecutable()) {
     QProcess process;
     if (process.startDetached(operation -> GetFolderPath())) {
         isExe = true;
       }
    if (!isExe) {

         listView -> setRootIndex(index);
      }
    }
  else if (fileInfo.isFile()) {
      QDesktopServices::openUrl(QUrl::fromLocalFile(operation -> GetFolderPath()));
    }
}

void MainWindow::on_Desktop_clicked()
{
  QString textButton = ((QPushButton*)sender()) -> text();
  operation -> SetFolderPath(button -> FastAccess(textButton));
  ui -> LvSource -> setRootIndex(model -> index(operation -> GetFolderPath()));
  ui->statusbar->showMessage("the " + textButton + " button was pressed");
}


void MainWindow::on_actionNew_Folder_triggered()
{
  Dialog *wnd = new Dialog("Enter folder name" , this);
  wnd -> show();
  connect(wnd, SIGNAL(NewFileName(QString)), this, SLOT(CreateFolder(QString)));
}

void MainWindow::CreateFolder(const QString &fileName) {
  if (!operation->CreateNewFolder(fileName)) {
      printQMessage("Error", "A folder with the same name already exists");
    }
}

void MainWindow::RenameFolder(const QString newFileName)
{
  if (!operation -> RenameFolder(newFileName)) {
      printQMessage("Error", "You cannot rename this folder because you have folder with this title");
    }
}

void MainWindow::on_actionBackup_triggered() {
  QDir sDir = QDir(model -> filePath(ui -> LvSource->rootIndex()));
  QDir dDir = QDir(model -> filePath(ui -> LvBackup->rootIndex()));
  if (sDir == dDir) {
      printQMessage("Error", "You can't make a backup!");
      return;
    }

  else {
      QMessageBox::StandardButton reply = QMessageBox::question(this, "Backup", "Are you sure you want to make a backup?", QMessageBox::Yes | QMessageBox::No);
      if(reply == QMessageBox::Yes) {
          QFileInfoList diffList = QFileInfoList();
          operation -> contentDifference(sDir, dDir, diffList);

          foreach(QFileInfo diffInfo, diffList) {
              QString backupPath = diffInfo.filePath().replace(sDir.absolutePath(), dDir.absolutePath());
              if (diffInfo.isFile()) {
                  QFile::remove(backupPath);
                  QFile::copy(diffInfo.absoluteFilePath(), backupPath);
                }
              if (diffInfo.isDir()) {
                  dDir.mkdir(backupPath);
                }
            }
        }
      else if (reply == QMessageBox::No)  {
          ui -> statusbar -> showMessage("You refused to back up.");
        }
    }
}

void MainWindow::printQMessage(QString title, QString message) {
  QMessageBox::information(this, title, message);
}

void MainWindow::on_LvSource_clicked(const QModelIndex &index)
{
  QFileInfo fileInfo = model -> fileInfo(index);
  operation -> SetChosenPath(fileInfo.filePath());
}

void MainWindow::on_actionRemove_triggered() //
{
  QMessageBox::StandardButton reply = QMessageBox::question(this, "Remove", "Are you sure you want to delete the object?", QMessageBox::Yes | QMessageBox::No);
  if (reply == QMessageBox::Yes) {
      QDir dir(operation -> GetChosenPath());
      dir.removeRecursively();
    }
  else if (reply == QMessageBox::No) {
      ui -> statusbar -> showMessage("You refused to delete");
    }
}

void MainWindow::on_actionRename_triggered()
{
  Dialog *wnd = new Dialog("Enter new folder name" , this);
  wnd -> show();
  connect(wnd, SIGNAL(RenameFolder(QString)), this, SLOT(RenameFolder(QString)));
}

void MainWindow::on_Search_clicked()
{
  QString userFileName = ui -> lineEdit -> text();
  QFileInfoList infoList;
  QDir dir("/Users/vladislavlatfulin");
  if (operation -> Search(userFileName, &infoList, dir)) {
      printQMessage("Error", "Nothing found");
      return;
    }
  else {
      ui -> LvSource -> setRootIndex(model -> index(infoList.first().absolutePath()));
    }
}


