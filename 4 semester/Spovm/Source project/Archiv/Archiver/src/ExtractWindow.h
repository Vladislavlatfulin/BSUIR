#ifndef EXTRACT_WINDOW_H
#define EXTRACT_WINDOW_H

#include <QDialog>
#include "src/Rle.h"
#include "src/Huffman.h"

namespace Ui {
class Extract_window;
}

class Extract_window : public QDialog
{
    Q_OBJECT

public:
    explicit Extract_window(QWidget *parent = nullptr);
    ~Extract_window();

private slots:
    void on_BrowseButton_clicked();
    void on_AppendButton_clicked();
    void on_OK_clicked();
    void recvText(const QString &text);

private:
    Ui::Extract_window *ui;
    QString direct;
    QStringList filesToDecompress;
    QString pathsForQLineEdit;
    CompressorRLE compressorRle;
    CompressorHuffman compressorHuf;

    bool IsDir(QString path);
};

#endif // EXTRACT_WINDOW_H
