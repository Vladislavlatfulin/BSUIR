#include "src/AddWindow.h"
#include "ui_AddWindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <fstream>
#include <vector>

#define SPACE ' '
using namespace std;

Add_window::Add_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_window)
{
    ui->setupUi(this);
}

Add_window::~Add_window()
{
    delete ui;
}


void Add_window::on_BrowseButton_clicked()
{
    direct = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home",
                                               QFileDialog::ShowDirsOnly
                                               | QFileDialog::DontResolveSymlinks);//получаем определлёную пользователем директорию

    this->ui->BrowseLineEdit->setText(direct);//и помещаем путь в "BrowseLineEdit"
}

void Add_window::on_AppendButton_clicked()
{
    filesToCompress = QFileDialog::getOpenFileNames(0, "ChooseFile(s) to archive",
                                                    QDir::homePath(),""); //получаем определлённые файлы для архивации

    pathsForQLineEdit = filesToCompress.join(";");
    this->ui->AppendLineEdit->setText(pathsForQLineEdit);
}

void Add_window::on_Ok_clicked()
{
    if(this->ui->AppendLineEdit->text().isEmpty() ||
            this->ui->BrowseLineEdit->text().isEmpty()) //Проверка на присутсвие места куда сохранить и файл, который будем сохранять
    {
        QMessageBox msgBox(QMessageBox::Warning, "Error", "Error : empty fields");
        msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
        msgBox.exec();
    }
    //Выбираем сбособ сжатия
    else {

            if(this->ui->RLERadioButton->isChecked()) {
                for(auto it:filesToCompress) {
                     QString tempDir = direct;
                    QString rleFileName =  tempDir.append(it.split("/").back().split(".").front().append(".rle").prepend("/"));
                    compressorRle.compressRLE(it, rleFileName);

                }
            } else {

                for(auto it:filesToCompress) {
                    if (!IsDir(it)) {
                        QString tempDir = direct;
                        QString huffmanFileName =  tempDir.append(it.split("/").back().split(".").front().append(".huf").prepend("/"));
                        compressorHuf.compressHuffman(it, huffmanFileName);
                    }
                    else {
                        QMessageBox msgBox(QMessageBox::Warning, "Error", "This algorithm is under development.\n This algorithm can only compress text files.");
                        msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
                        msgBox.exec();
                    }
                }
            }
        }
}

void Add_window::recvText(const QString &text)
{
    filesToCompress.clear();
    filesToCompress.append(text);
    pathsForQLineEdit = filesToCompress.join(";");
    this->ui->AppendLineEdit->setText(pathsForQLineEdit);
}

bool Add_window::IsDir(QString path) {
    if((opendir(path.toStdString().c_str()))) {
        closedir(opendir(path.toStdString().c_str()));
        return true;
    }
    return false;
}
