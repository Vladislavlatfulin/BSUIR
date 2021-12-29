#include "Task.hpp"

int Task:: totalId = 0;
Task::Task (string name, int percentageOfCompletion) {
    id = ++totalId;
    SetName(name);
    SetPercentageOfCompletion(percentageOfCompletion);
}

Task:: Task () {
    id = ++totalId;
    SetPercentageOfCompletion(0);
    SetName(" ");
}

Task:: ~Task () {
    --totalId;
}

void Task::SetName(string name) {
    this -> name = name;
}
void Task:: SetPercentageOfCompletion(int percentageOfCompletion) {
    assert((percentageOfCompletion >= 0 && percentageOfCompletion <= 100) && "Poor percentage of work");
    this -> percentageOfCompletion = percentageOfCompletion;
}

void printTaskProperties (Task &value) {
    cout <<"|" << value.percentageOfCompletion  <<"                        | " <<value.name<< "           | "<< value.id <<"   |";
}


