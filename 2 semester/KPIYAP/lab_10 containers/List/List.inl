#include "List.hpp"

template <class T>
List<T>:: List () {
    Size = 0;
    head = nullptr;
}

template <class T>
void List<T>:: push_back(T data) {
    int number = Size;
    if (!head) {
        head = new Node(number + 1,data);
    }
    else {
        Node *current = head;
        while (current -> next != nullptr) {
            current = current -> next;
        }
        current -> next = new Node(number + 1, data);
        
        
    }
    Size++;
}


template <class T>
void List<T>:: sortAcrossContent() {
    int choice;
    std::cout << "Enter type sort " << std::endl;
    std::cout << "1 - по уменьшению" << std::endl;
    std::cout << "2 - по увеличению" << std::endl;

    Node* cur1 = head;
    Node* cur2 = head;
    std::cin >> choice;
    switch (choice) {
        case 1:
            
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size - 1; j++) {
                    if (cur1->data < cur2->data) {
                        int temp = cur1->data;
                        cur1->data = cur2->data;
                        cur2->data = temp;
                        
                    }
                    cur2 = cur2->next;
                }
                cur2 = head;
                cur1 = head->next;
                for (int k = 0; k < i; k++) {
                    cur1 = cur1->next;
                }
            }
            break;
        case 2:
            
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size - 1; j++) {
                    if (cur1->data > cur2->data) {
                        int temp = cur1->data;
                        cur1->data = cur2->data;
                        cur2->data = temp;
                        
                    }
                    cur2 = cur2->next;
                }
                cur2 = head;
                cur1 = head->next;
                for (int k = 0; k < i; k++) {
                    cur1 = cur1->next;
                }
            }
            break;
        default:
            break;
    }
    
}

template <class T>
List<T>::~List<T>() {
    while (Size) {
        pop_front();
        
    }
}

template <class T>
void List<T>:: Display() {
    Node *current = head;
    while (current) {
        std::cout << "Node data: " << current -> data << std::endl;
        std::cout << "Node number: " << current -> number << std::endl;
        std::cout << std::endl;
        current = current -> next;
    }
}

template <class T>
List<T>::List (Node &node) {
    this -> number = node.number;
    this -> data = node.data;
    this -> next = node.next;
}

template <class T>
void List<T>:: Displacement() {
    int choice;
    int newPlace;
    Node *temp = head;
    std::cout << "Enter node number: ";
    std::cin >> choice;
    std::cout << "Enter new place node number: ";
    std::cin >> newPlace;
    while (temp -> number != choice) {
        temp = temp -> next;
    }
    
    Node *newNode = new Node(*temp);
    temp = head;
    while (temp -> next -> number != choice) {
        temp = temp -> next;
    }
    Node *secondTemp = temp;
    temp = temp -> next;
    secondTemp -> next = newNode -> next;
    delete temp;
    temp = head;
    if (newPlace == 1) {
        newNode -> next = head;
        head = newNode;
    }
    else {
        while (temp -> next -> number != newPlace) {
            temp = temp -> next;
        }
        
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    
}

template<class T>
void List<T>::pop_front() {
    Node *temp = head;
    head = head -> next;
    delete temp;
    Size--;
}
