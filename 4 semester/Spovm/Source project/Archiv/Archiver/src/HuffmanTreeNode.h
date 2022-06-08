#ifndef HUFFMANTREENODE_H
#define HUFFMANTREENODE_H
class Node
{
public:
    Node *left;
    Node *right;
    int count;
    char symbol;
    Node(){left = right = 0;}// создаёт узел без параметров тоесть пустой (новый)

    Node(char symbol, int count) //конструктор, для инициализации // key = symbol;  value = count
    {
        this->count = count;
        this->symbol = symbol;
        //обнуляем левый и правый узел
        this->left = 0;
        this->right = 0;
    }

    Node(Node *left, Node *right)// создают узел где-то в середине и поэтому уже известны его ветви левая и правая
    {
        this->symbol = 0;
        this->left = left;
        this->right = right;
        count = left->count + right->count;// переменная кол-во элементов на ветве
    }
};
#endif // HUFFMANTREENODE_H
