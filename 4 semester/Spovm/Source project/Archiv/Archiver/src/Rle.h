#ifndef RLE_H
#define RLE_H
#include <QFileInfo>
#include <QString>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

class CompressorRLE
{
public:
    void compressRLE(QString &compressFileName, QString &rleFileName);
    void decompressRLE(QString &compressedRLE, QString &decompressedFileName);
private:

    QString getRelativePath(string compressibleFolderPath, string fullPathFile);
    void dirWalk(const char *dirPath, QStringList &filesList);
    bool IsDir(QString path);
};

#endif // RLE_H
