#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include "Library.hpp"
template <typename T>

class List {
private:
    int Size;
    class Node {
    public:
        T data;
        Node *next;
        int number;
        Node(int number, T data = T(), Node *next = nullptr) {
            this -> number = number;
            this -> next = next;
            this -> data = data;
        }
    };
public:
    List();
    List(Node &);
    ~List();
    Node *head;
    void Displacement();
    void pop_front();
    
    void push_back(T data);
    void sortAcrossContent();
    void Display();
};

#include "List.inl"

#endif
