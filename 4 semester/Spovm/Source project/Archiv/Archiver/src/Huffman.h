#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "src/HuffmanTreeNode.h"
#include <QString>
#include <vector>
#include <map>
#include <QDebug>

class CompressorHuffman
{
public:
    //методы класса
    void readAllBytesFile(QString &fileName, std::vector<char> &info);
    void compressHuffman(QString &compressFileName, QString &hufFileName);
    void decompressHuffman(QString &hufFileName, QString &decompressFileName);
    void buildTable(Node *root);
    void Print(Node *root, int depth = 0) { //вывод на экран нашего дерева
        if (!root) return;
        if (root->symbol)//если нашли символ, то
        {
            for (int i = 0; i < depth; i++)
                qDebug() << ".";//глубина дерева
            qDebug() << root->symbol;//символ, т.е. конец
        }
        else depth++;//глубина, т.е. место где находится символ
        //рекурсивно проходемся по левому и правому узлу, чтобы найти символ
        Print(root->left, depth);
        Print(root->right, depth);
    }
private:
    std::vector<bool> code;//код, bool, т.к. только 0 и 1
    std::map<char, std::vector<bool>> table;//таблица(ассоциация) символа с кодом
    static Node *root;//указатель на вершину дерева
};
#endif // HUFFMAN_H
