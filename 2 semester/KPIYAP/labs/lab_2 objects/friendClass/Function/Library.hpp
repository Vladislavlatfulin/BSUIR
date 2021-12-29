#ifndef Library_hpp
#define Library_hpp
#include "Task.hpp"

int menu();
void output (const Task *userPointer , const int lenght);
void deletingOneInstance (Task *&userPointer, int &lenght, Task);
void removalInstance (Task *&userPointer, int &lenght);
void changingAnInstance (Task *&userPointer, const int lenght);
void changingOneInstance (Task &value);
#endif 
