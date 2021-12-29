#ifndef Task_hpp
#define Task_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Task {
private:
    static int totalId;
    string name;
    int percentageOfCompletion;
    int id;
public:
    Task (string name, int percentageOfCompletion);
    Task ();
    ~Task();
    void SetName (string name);
    void SetPercentageOfCompletion(int percentageOfCompletion);
    bool operator == (const Task &value) {
        return value.id == this -> id && value.name == this -> name && value.percentageOfCompletion == this -> percentageOfCompletion;
    }
    
    bool operator != (const Task &value) {
        return (value.id == this -> id && value.name == this -> name && value.percentageOfCompletion == this -> percentageOfCompletion);
    }
    
    friend void printTaskProperties (Task &value);
    friend class Inspector;
};


#endif /* Task_hpp */
