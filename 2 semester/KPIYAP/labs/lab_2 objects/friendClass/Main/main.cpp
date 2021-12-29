#include "Library.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int lenght = 4;
    Task *instanceArray = new Task[lenght]{{"Vlad", 67}, {"Dima", 99}, {"Alex", 10}, {"Ivan", 92}};

while (1) {
        switch (menu()) {
            case 1:
                output(instanceArray, lenght);
                break;
            case 2:
                changingAnInstance(*&instanceArray, lenght);
                break;
            case 3:
                removalInstance(instanceArray, lenght);
                break;
            case 4:
                delete [] instanceArray;
                return 0;
                
            default:
                cout << "Choose another option." << endl;
                break;
        }
    }
}
