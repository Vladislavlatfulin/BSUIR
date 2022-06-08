#include "src/Huffman.h"
#include "src/HuffmanTreeNode.h"
#include <list>
#include <QMessageBox>
#include <fstream>

using namespace std;

Node *CompressorHuffman::root = 0;//обнуляем первый узел

struct Compare
{
    bool operator()(const Node* left, const Node* right)
    {
        return left->count < right->count;
    }
};
//прочитать все байты из файла
void CompressorHuffman::readAllBytesFile(QString &fileName, std::vector<char> &info){
    ifstream file(fileName.toStdString(), ios::binary | ios::ate);
    if (file.is_open())
    {
        ifstream::pos_type pos = file.tellg();//устанавливаем текущую позицию
        info.resize(pos);//изменяем размер строки, чтобы она могра содержать pos символов
        file.seekg(0, ios::beg);//ставим на начало
        file.read(&info[0], pos);//читаем весь файл в info[0]
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Warning, "Error", "Unable to open file");
        msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
        msgBox.exec();
    }
    file.close();
}

void CompressorHuffman::compressHuffman(QString &compressFileName, QString &hufFileName)
{
    vector<char> info;//вектор ,который будет содержать символы
    readAllBytesFile(compressFileName, info);//читаем все символы в вектор
    map<char, int> symbols;//карта, которая содержит символ и кол-во вхождений этого символа
    for(auto it : info)
    {
        symbols[it]++;//заполняем карту <символом, кол-во вхождений символа>: 1 - 'a':5, 2 - 'c':1, ...
    }

    list<Node*> tree;//создаём лист указателей на узел - дерево
    map<char, int>::iterator it;// инератор для прохода
    for (it = symbols.begin(); it != symbols.end(); it++)// заполняем дерево
    {
        Node *p = new Node(it->first, it->second); // key = symbol;  value = count
        tree.push_back(p);
    }

    //Формируем закодированное бинарное дерево - цикл, до тех пор, пока не останется один корень
    while(tree.size() != 1)
    {
        tree.sort(Compare());//сортируем лист по кол-ву вхождений: 1 - 'c':1, 2 - 'a':5, ...

        //выбираем первые два узкла, т.к. они минимальные и запоминаем их
        Node *tmp1 = tree.front();
        tree.pop_front();//удаляем первый
        Node *tmp2 = tree.front();
        tree.pop_front();//удаляем второй


        Node *parent = new Node(tmp1, tmp2);// формируем один узел с указателями на те, что удалили, но запомнили в tmp1 и tmp2
        tree.push_back(parent);//добавляем сформированый узел и повторяем опять цикл
    }
    this->root = tree.front();//помещяем последний корень(вершину) в root
    Print(this->root);

    buildTable(this->root);//формируем таблицу
    ifstream fileCodes(compressFileName.toStdString());//создаём объект, для чтения и кодировки символа
    ofstream fileCompressed(hufFileName.toStdString(), ios::out | ios::binary);//создаём объект для записи сжатых данных

    QStringList pathList = compressFileName.split(".");
        string format = pathList.back().toStdString();
        for(auto chr: format) {
            fileCompressed << chr;
        }
        fileCompressed << ' ';

    int count = 0;//для подсчёта битов
    char buffer = 0;//для закодированного символа(байта)
    //пока не конец файла заполняю файл - fileCompressed моими кодами из таблицы

    while(fileCodes.good())
    {
        char ch = fileCodes.get();
        vector<bool> x = table[ch];//записываю вектор данного символа
        for(int i = 0; i < (int)x.size(); i++)//пока не пройдём по коду из таблицы (x.size)
        {
            //разбиваем нашибайты по 8
            buffer = buffer | x[i]<<(7-count);//проверяем биты и записываем их в байт(7 - count, т.к. мы проверяем слева направа)
            count++;
            //если прошли 8 битов, то записываем байт в файл fileCompressed
            if(count == 8)
            {
                count = 0;//обнуляем, для считывания следующих 8 битов(1 байт)
                fileCompressed << buffer;
                buffer = 0;
            }
        }
    }

    fileCodes.close();
    fileCompressed.close();
    info.clear();
    symbols.clear();
}

//функция формирования таблицы
void CompressorHuffman::buildTable(Node *root)
{
    if (root->left)//если слева не NULL (т.е слева есть сын)
    {
        code.push_back(0);//ставим вектор 0
        buildTable(root->left);//и опять рекурсивно запускаем функцию root->left
    }

    if (root->right)//если справа не NULL(т.е. справа есть сын)
    {
        code.push_back(1);//ставим вектор 1
        buildTable(root->right);//и рекрсивно запускаем функцию с root->right
    }

    if(root->symbol)//если нашли букву
        table[root->symbol] = code;//ассоциируем букву с символом

    if(code.size())//Если размер кода не NULL
        code.pop_back();//то уменьшаем на 1, чтобы вернутся назад и проверять остальное дерево
}

void CompressorHuffman::decompressHuffman(QString &hufFileName, QString &decompressDirName)
{
    Node *p = this->root;
    if(p == NULL) {
        QMessageBox msgBox(QMessageBox::Warning, "Error", "Failed to unzip file");
        msgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
        msgBox.exec();
        return;
    }

    ifstream hufFile(hufFileName.toStdString(), ios::in | ios::binary);
    QString format = "";
        char chr;
        while (hufFile.get(chr) && chr != ' ') {
             format.append(chr);

        }

    format.prepend('.');
    QString decompressedFileName =  decompressDirName.append(hufFileName.split("/").back().split(".").front().append(format).prepend("/"));

    //создаём объекты для чтения и записи
    ofstream decompressFile(decompressedFileName.toStdString());
    //узел, в который присваиваем наш корень от которого мы будем идти по дереву
    int count = 0;
    char byte;
    //считываем байт
    hufFile.read(&byte, sizeof(char));

    while(true)
    {
        bool b = byte &(1 << (7 - count));//проверяем биты и получаем 0 или 1(7 - count, т.к. мы проверяем слева направа)
        //проверяем в какуб сторон идти: 1-право, 0-лево
        if(b)
            p = p->right;//переходим вправо
        else
            p = p->left;//переходим влево
        //если дошли до символа, т.е. конца какого-либо уза
        if(p->left == nullptr && p->right == nullptr)
        {

            decompressFile<<p->symbol;//записываем символ в файл
            p = root;
        }
        count++;
        //если прошли 8 битов, то обнуляем count и считываем дальше
        if(count == 8)
        {
            count = 0;
            hufFile.read(&byte, sizeof(char));
            if (hufFile.eof()) break;
        }
    }

    hufFile.close();
    decompressFile.close();
}




