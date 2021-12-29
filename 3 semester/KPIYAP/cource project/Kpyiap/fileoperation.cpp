#include "fileoperation.h"
#include <QMessageBox>

FileOperation::FileOperation(QObject *parent) : QObject(parent)
{

}

bool FileOperation::CreateNewFolder(QString FolderName)
{
  QDir dir(folderPath);
  return dir.mkdir(FolderName);
}

bool FileOperation::RenameFolder(QString newName)
{
  QDir dir(chosenPath);
  auto src = QDir::cleanPath(dir.filePath("."));
  auto dst = QDir::cleanPath(dir.filePath(QStringLiteral("..%1%2").arg(QDir::separator()).arg(newName)));
  auto rc = QFile::rename(src, dst);
  if (rc) dir.setPath(dst);
  return rc;
}

void FileOperation::recursiveContentList(QDir &dir, QFileInfoList &contentList)
{
  foreach (QFileInfo info, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst)) {
      contentList.append(info);
      if (info.isDir() && dir.cd(info.fileName())) {
          recursiveContentList(dir, contentList);
          dir.cdUp();
        }
    }
}

bool FileOperation::Search(QString userFileName, QFileInfoList *fileInfoList, QDir &cDir)
{
  foreach (QFileInfo cInfo, cDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst)) {
      if (userFileName == cInfo.fileName() && cInfo.isDir()) {
          fileInfoList->append(cInfo);
          cDir.cd(cInfo.fileName());
          Search(userFileName, fileInfoList, cDir);
          cDir.cdUp();
        }
      if (cInfo.isDir() &&  userFileName != cInfo.fileName()) {
          cDir.cd(cInfo.fileName());
          Search(userFileName, fileInfoList, cDir);
          cDir.cdUp();
        }

    }
  return fileInfoList->isEmpty();
}

void FileOperation::SetFolderPath(QString folderPath)
{
  this -> folderPath = folderPath;
}

void FileOperation::SetChosenPath(QString chosenPath)
{
  this -> chosenPath = chosenPath;
}

QString FileOperation::GetFolderPath()
{
  return folderPath;
}

QString FileOperation::GetChosenPath()
{
  return chosenPath;
}

void FileOperation::contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffLIst)
{
  foreach (QFileInfo sInfo, sDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst)) {
      bool fileExists = false;
      foreach(QFileInfo dInfo, dDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst)) {
          if (sInfo.fileName() == dInfo.fileName()) {
              if (sInfo.isDir() || sInfo.lastModified() <= dInfo.lastModified())
                fileExists = true;
              break;
            }
        }
      if (!fileExists) {
          diffLIst.append(sInfo);
        }
      if (sInfo.isFile()) {
          continue;
        }
      if (fileExists) {
          sDir.cd(sInfo.fileName());
          dDir.cd(sInfo.fileName());
          contentDifference(sDir, dDir, diffLIst);
          sDir.cdUp();
          dDir.cdUp();
        }
      else {
          sDir.cd(sInfo.fileName());
          recursiveContentList(sDir, diffLIst);
          sDir.cdUp();
        }
    }
}
