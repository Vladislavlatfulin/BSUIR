#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>

Dialog::Dialog(QString title , QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
  ui -> label -> setText(title);

  connect(ui->buttonBox -> button(QDialogButtonBox::Ok), SIGNAL(clicked()), SLOT(OkClicked()));
  connect(ui->buttonBox -> button(QDialogButtonBox::Cancel), SIGNAL(clicked()), SLOT(close()));
}

void Dialog::OkClicked() {
  if (ui ->label -> text() == "Enter folder name") {
      emit NewFileName(ui ->lineEdit -> text());
    }
  else if (ui -> label -> text() == "Enter new folder name") {
      emit RenameFolder(ui -> lineEdit -> text());
    }

  close();
}



Dialog::~Dialog()
{
  delete ui;
}
