#include "Library.hpp"
using namespace std;

bool dataChecking (int check, int data) {
    return ((data < 1 || check < 1)? true: false);
}

void changingOneInstance (Task &value) {
    char *userPercentage = new char [10];
    int IntPercentage = 0;
    rewind(stdin);
    cout << "Enter Percentage Of Completion" << endl;
    for (int i = 0; i < 10; i++) {
        char c = cin.get();
        
        if (i == 0  && c == '\n') {
            cout << "You need to enter a number!" << endl << "Enter the number again" << endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if ((c < '0' || c > '9')  && c != '\n') {
            cout << "You need to enter a number!" << endl << "Enter the number again" << endl;
            i = -1;
            rewind(stdin);
            continue;
        }
        
        if (c == '\n') {
            userPercentage[i] = '\0';
            IntPercentage = atoi(userPercentage);
            if (IntPercentage < 0 || IntPercentage > 100) {
                i = -1;
                cout << "enter a number from 0 to 100" << endl;
                rewind(stdin);
                continue;
            }
            break;
        }
        userPercentage[i] = c;
    }
    
    value.SetPercentageOfCompletion(IntPercentage);
    
}

void changingAnInstance(Task *&userPointer, const int lenght) {
    if (userPointer == nullptr) {
        cout << "Array is empty!" << endl;
        return;
    }
    
    int userChoice;
    cout << endl <<"by what number do you want to change the instance?" << endl;
    output(userPointer, lenght);
    
    do {
        cin >> userChoice;
        if (userChoice < 0 || userChoice >= lenght) {
            cout << "There is no such id";
            cout << endl <<"by what number do you want to change the instance" << endl;
            continue;
        }
    }while (userChoice < 0 || userChoice >= lenght);
    
    changingOneInstance(userPointer[userChoice]);
}

int menu() {
    int tempMenu;
    cout << endl <<"Enter number for change." << endl;
    cout <<"1 - Output information." << endl;
    cout <<"2 - Change the information" << endl;
    cout <<"3 - Deletion of information" << endl;
    cout <<"4 - To finish work." << endl;
    
    cin >> tempMenu;
    
    return tempMenu;
}

void printTask (Task instanse) {
    printTaskProperties(instanse);
}

void output (const Task *userPointer, const int lenght) {
    if (userPointer == nullptr) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout <<"-------------------------------------------------------"<< endl;
    cout <<"| № |Percentage of completion  | Name           | ID  |" << endl;
    for (int i = 0; i < lenght; i++) {
        cout <<"-------------------------------------------------------"<< endl;
        cout << "| " << i << " ";
        printTask(userPointer[i]);
        cout << endl;
    }
    cout <<"-------------------------------------------------------"<< endl;
}

void deletingOneInstance (Task *&userPointer, int &lenght, Task deleteElement) {
    Task *temp = new Task[lenght - 1];
    for (int i = 0, j = 0; j < lenght; i++, j++) {
        if (userPointer[j] == deleteElement) {
            i--;
            continue;
        }
        temp[i] = userPointer[j];
    }
    delete [] userPointer;
    lenght--;
    if (lenght == 0) {
        userPointer = nullptr;
        return;
    }
    userPointer = temp;
}

void removalInstance (Task *&userPointer, int &lenght) {
    if (userPointer == nullptr) {
        cout << "Array is empty!" << endl;
        return;
    }
    int userChoice;
    cout << endl <<"by which number do you want to delete the instance?" << endl;
    output(userPointer, lenght);
    
    do {
        cin >> userChoice;
        if (userChoice < 0 || userChoice >= lenght) {
            cout << "There is no such id";
            cout << endl <<"by which ID do you want to delete the instance?" << endl;
            continue;
        }
    }while (userChoice < 0 || userChoice >= lenght);
    
    deletingOneInstance(userPointer, lenght, userPointer[userChoice]);
}
