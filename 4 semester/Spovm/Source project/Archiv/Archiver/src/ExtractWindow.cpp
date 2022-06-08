#include "src/ExtractWindow.h"
#include "ui_ExtractWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <map>
#include <string>
#include <fstream>
#include <QDebug>

using namespace std;

Extract_window::Extract_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Extract_window)
{
    ui->setupUi(this);
}

Extract_window::~Extract_window()
{
    delete ui;
}

void Extract_window::on_BrowseButton_clicked()
{
    direct = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                "/home",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    this->ui->BrowseLineEdit->setText(direct);
}

void Extract_window::on_AppendButton_clicked()
{
    if (this->ui->RLERadioButton->isChecked())
    {
        filesToDecompress = QFileDialog::getOpenFileNames(this, "ChooseFile(s) to decompress",QDir::homePath()," files (*.rle)");
    } else {
        filesToDecompress = QFileDialog::getOpenFileNames(this, "ChooseFile(s) to decompress",QDir::homePath(),"HUF files (*.huf)");
    }

    pathsForQLineEdit = filesToDecompress.join(";");
    this->ui->AppendLineEdit->clear();
    this->ui->AppendLineEdit->setText(pathsForQLineEdit);
}


void Extract_window::on_OK_clicked()
{
    if(this->ui->AppendLineEdit->text().isEmpty() ||
            this->ui->BrowseLineEdit->text().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Warning, "Error", "Error : empty fields");
        msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
        msgBox.exec();
    }
    else {

        for(auto it: filesToDecompress) {

            if (this->ui->RLERadioButton->isChecked() && it.split(".").back() == "rle") {
                QString tempDir = direct;
                QString decompressedDirPath =  tempDir.append(it.split("/").back().split(".").front().prepend("/"));
                compressorRle.decompressRLE(it, decompressedDirPath);
            }
            else if(this->ui->HuffmanRadioButton->isChecked() && it.split(".").back() == "huf") {
                if (!IsDir(it)) {
                    compressorHuf.decompressHuffman(it, direct);
                }
                else {
                    QMessageBox msgBox(QMessageBox::Warning, "Error", "This algorithm is under development.\n This algorithm can only compress text files.");
                    msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
                    msgBox.exec();
                }
            }
            else {
                QMessageBox msgBox(QMessageBox::Warning, "Error", "Сhoose another type of unzipping");
                msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
                msgBox.exec();
            }
        }
    }
}

void Extract_window::recvText(const QString &text)
{
    filesToDecompress.clear();
    filesToDecompress.append(text);
    pathsForQLineEdit = filesToDecompress.join(";");
    this->ui->AppendLineEdit->setText(pathsForQLineEdit);

}

bool Extract_window::IsDir(QString path) {
    if((opendir(path.toStdString().c_str()))) {
        closedir(opendir(path.toStdString().c_str()));
        return true;
    }
    return false;
}
