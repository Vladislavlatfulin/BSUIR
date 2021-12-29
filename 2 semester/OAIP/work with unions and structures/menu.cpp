
#include "functional.hpp"

int main () {
    int numberOfPassengers = 0, i, oldValue = 0;
    struct Passenger *passengerPointer = NULL;
    
    while (1) {
        switch (menu()) {
            case 1:
                printf("\nEnter number of passengers\n");
                numberOfPassengers = inputChoice();
                
                do {
                    if (!(passengerPointer = (struct Passenger*)malloc(numberOfPassengers * sizeof(struct Passenger)))) {
                        printf("Too many passengers. Reduce their number.\n");
                        continue;
                    }
                } while (!passengerPointer);
                
//                for (i = 0; i < numberOfPassengers; i++) { // что-то среднее между методом и инициализатором
//                    passengerPointer[i].init(i);
//                }
                
                for (i = 0; i < numberOfPassengers; i++) {
                    inputInformation(passengerPointer, i);
                }
                break;
                
            case 2:
                if (!passengerPointer) {
                    printf("You have not entered information.\n");
                    break;
                }
                
                output(passengerPointer, numberOfPassengers);
                break;
                
            case 3:
                if (!passengerPointer) {
                    printf("You have not entered information.\n");
                    break;
                }
                
                search(passengerPointer, numberOfPassengers);
                break;
                
            case 4:
                if (!passengerPointer) {
                    printf("You have not entered information.\n");
                    break;
                }
                
                deleteStructure(passengerPointer, numberOfPassengers);
                break;
                
            case 5:
                if (!passengerPointer) {
                    printf("You have not entered information.\n");
                    break;
                }
                oldValue = numberOfPassengers;
                
                addInformation(passengerPointer, numberOfPassengers, oldValue);
                break;
            
            case 6:
                free(passengerPointer);
                return 0;
                
            default:
                printf("Choose another option\n");
                break;
        }
    }
}
