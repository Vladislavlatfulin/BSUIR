#ifndef FINDLIST_H
#define FINDLIST_H

#include "mainwindow.h"

class FindList: public QAbstractListModel
{
public:
  explicit FindList(QObject *parent = 0);

  int RowCount(const QModelIndex & parent = QModelIndex()) const;
private:
  QFileInfoList list;
  FileOperation operation;
};

#endif // FINDLIST_H
