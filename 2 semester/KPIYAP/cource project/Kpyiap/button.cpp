#include "button.h"

Button::Button(QObject *parent): QObject(parent)
{

}

QString Button::FastAccess(QString &buttonText) {
  if (buttonText == "Desktop") { return "/Users/vladislavlatfulin/Desktop";}
  else if(buttonText == "Icloud drive") { return "/Users/vladislavlatfulin/Library/Mobile Documents/com~apple~CloudDocs";}
  else if (buttonText == "Documents") {return "/Users/vladislavlatfulin/Documents";}
  else if (buttonText == "Downloads") {return "/Users/vladislavlatfulin/Downloads";}
  else if (buttonText == "Programs") {return "/Applications";}
  return "";
}
