#include "Functions.hpp"

int main () {
 
    int check, numberOftrain = 0;
    struct RailwayStation *traintInformation = NULL;
    
    while (1) {
        switch (menu()) {
            case 1:
                do {
                    printf("\nEnter number of train.\n");
                    check = scanf("%d", &numberOftrain);
                    if (dataChecking(check, numberOftrain)) {
                        printf("There is no such number. Try to enter again.\n");
                        fflush(stdin);
                        continue;
                    }
 
                    if (!(traintInformation = (struct RailwayStation*)malloc(numberOftrain * sizeof(struct RailwayStation)))) {
                        printf("Too many trips. Reduce their number.\n");
                        continue;
                    }
                } while(!traintInformation);
 
                for (int i = 0; i < numberOftrain; i++) {
                    inputTripDays(traintInformation, i);
                    inputTrainNumber(traintInformation, i);
                    inputDestination(traintInformation, i);
                    inputArrivalTime(traintInformation, i);
                    inputParkingTime(traintInformation, i);
                }
                
                break;
            
            case 2:
                if (!traintInformation) {
                    printf("You have not entered information.\n");
                    break;
                }
                
                for (int i = 0; i < numberOftrain; i++) {
                    printf("\n%d trip information.\n", i + 1);
                    outputInformation(traintInformation[i]);
                }
                
                break;
            
            case 3:
                chengeInformation(traintInformation, numberOftrain);
                break;
            
            case 4:
                searchSelectedField(traintInformation, numberOftrain);
                break;
            
            case 5:
                sortPointer(traintInformation, numberOftrain);
                break;
            
            case 6:
                deleteStructure(traintInformation, numberOftrain);
                break;
            
            case 7:
                partialSearch(traintInformation, numberOftrain);
                break;
            
            case 8:
                free(traintInformation);
                return 0;
            
            default:
                printf("choose another option\n");
                break;
        }
    }
}

