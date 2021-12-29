#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
class Button: public QObject
{
public:
  Button(QObject *parent = nullptr);
  QString FastAccess (QString &);
};

#endif // BUTTON_H
