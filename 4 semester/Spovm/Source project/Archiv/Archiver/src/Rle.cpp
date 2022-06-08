#include "Rle.h"
#include <map>
#include <string>
#include <QMessageBox>
#include <fstream>
#include <vector>
#include <QFileDialog>
#include <QQueue>

using namespace std;

void CompressorRLE::compressRLE(QString &compressFileName, QString &rleFileName)
{ 
    QStringList listFile;
    if(!IsDir(compressFileName)) {
        listFile.append(compressFileName);
        auto relativePath = compressFileName.split("/").back();
        compressFileName.remove(relativePath);
        compressFileName.chop(1);
    }
    else  {
        dirWalk(compressFileName.toStdString().c_str(), listFile);
    }

    ofstream fileCompressed(rleFileName.toStdString()); // архив

    for(const auto &it: listFile) {
        auto relativePath = getRelativePath(compressFileName.toStdString(), it.toStdString());
               fileCompressed << relativePath.toStdString();
               if(IsDir(it)) { fileCompressed << " $"; }
               fileCompressed << '\n';
    }
    fileCompressed << '\n';

    for(const auto &it: listFile) {
        if(IsDir(it)) continue;
        ifstream fileInput(it.toStdString());
         char sym1;

         while(fileInput.good())
         {
             int count=1;//кол-во совпавших символов
             fileInput.get(sym1);//считываем первый символ из файла fileInput в sym1
             while (sym1 == fileInput.peek() && count < 9)//пока первый символ равен следующему за ним и кол-во меньше 9 - повторяем
             {
                 //увеличиваем кол-во совпадений и считываем второй символ в sym1
                 count++;
                 fileInput.get(sym1);
             }
             //записываем результат в файл для записи
             fileCompressed << sym1 << count;
         }
         fileCompressed << "$$";
         fileInput.close();
    }

    fileCompressed.close();
}

void CompressorRLE::decompressRLE(QString &compressedRLEDirPath, QString &decompressedDirPath)
{
    mkdir(decompressedDirPath.toStdString().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    QQueue<QString> queueFilesPath;  // очередь путей файлов сжатой директории
    ifstream dirToDescompress(compressedRLEDirPath.toStdString());

    char ch1 = '\0';
    while(ch1 != '\n' || dirToDescompress.peek() != '\n') {    // цикл получения адресов сжатых файлов и занесения их в очередь
        QString filePath;
        dirToDescompress.get(ch1);

        while(ch1 != '\n') {
            filePath.append(ch1);
            dirToDescompress.get(ch1);
        }

        filePath.prepend(decompressedDirPath);
        queueFilesPath.enqueue(filePath);
    }
    dirToDescompress.get(ch1);

    while(!queueFilesPath.isEmpty()) {   // берем из очереди пути и восстанавливаем файлы и директории

        QString fileOrDirPath = queueFilesPath.dequeue();

        if (fileOrDirPath.back() == '$') {
            fileOrDirPath.chop(2);
           mkdir(fileOrDirPath.toStdString().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        } else {
            ofstream decompressedFile(fileOrDirPath.toStdString());
            dirToDescompress.get(ch1);  // считывание символов
            char ch2;
            while ((char)dirToDescompress.peek() != '$' || ch1 != '$') {
                dirToDescompress.get(ch2); //  считываение повторений символов
                for (int i = 0; i < ch2 - '0'; i++) { //пока не запишем все повторяющиеся символы не выйдем
                    decompressedFile << ch1;
                }
                dirToDescompress.get(ch1);
            }
            decompressedFile.close();
            dirToDescompress.get(ch1);
        }
    }

    dirToDescompress.close();
    queueFilesPath.clear();
}

QString CompressorRLE::getRelativePath(string compressibleFolderPath, string fullPathFile) {
    string::size_type pos = fullPathFile.find(compressibleFolderPath);
        while (pos != string::npos) {
            fullPathFile.erase(pos, compressibleFolderPath.size());
            pos = fullPathFile.find(compressibleFolderPath, pos + 1);
        }
        return QString::fromStdString(fullPathFile);
}



void CompressorRLE::dirWalk(const char* dirPath, QStringList &filesList){
    DIR *dir;
    struct dirent *entry;

    if((dir = opendir(dirPath))) {
            while((entry = readdir(dir))) {

                if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".DS_Store") == 0 || strcmp(entry->d_name, "") == 0)
                    continue;

                char *path = (char*)malloc((strlen(dirPath)+2+strlen(entry->d_name))*sizeof(char));
                strcpy(path, dirPath);
                strcat(path, "/");
                strcat(path, entry->d_name);
                strcat(path, "\0");

                switch(entry->d_type){
                    case DT_DIR:
                        filesList.push_back(QString::fromUtf8(path));
                        break;
                    case DT_REG:
                        filesList.push_back(QString::fromUtf8(path));
                        break;
                    case DT_LNK:
                        filesList.push_back(QString::fromUtf8(path));
                        break;
                }

                dirWalk(path, filesList);
            }
            closedir(dir);
        }
    else return;
}

bool CompressorRLE::IsDir(QString path) {
    if((opendir(path.toStdString().c_str()))) {
        closedir(opendir(path.toStdString().c_str()));
        return true;
    }
    return false;
}










