#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDir>
#include <QDebug>
#include <QFile>




class FileOperation:public QObject
{
public:
  explicit FileOperation(QObject *parent = nullptr);
    bool CreateNewFolder(QString);
    bool RenameFolder(QString);
    void contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffLIst);
    void recursiveContentList(QDir &dir, QFileInfoList &contentList);
    bool Search(QString userFileName, QFileInfoList *fileInfoList, QDir &cDir);
    void SetFolderPath(QString folderPath);
    void SetChosenPath(QString chosenPath);
    QString GetFolderPath();
    QString GetChosenPath();
private:
    QString folderPath;
    QString chosenPath;
};
#endif // FILEOPERATION_H
