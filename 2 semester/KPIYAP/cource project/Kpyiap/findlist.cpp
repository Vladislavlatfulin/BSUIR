#include "findlist.h"


FindList::FindList(QObject *parent):QAbstractListModel(parent) {
  QString userFileName = ui -> lineEdit -> text();
  QFileInfoList infoList;
  QDir dir("/Users/vladislavlatfulin");
  operation.Search(userFileName, &list, dir);
}

