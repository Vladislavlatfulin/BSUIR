#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "fileoperation.h"
#include <QDebug>

namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QString title, QWidget *parent = nullptr);
  ~Dialog();
signals:
  void RenameFolder(const QString &fileName);
  void NewFileName(const QString &fileName);

private slots:
  void OkClicked();

private:
  Ui::Dialog *ui;
  FileOperation *obj;
};

#endif // DIALOG_H
