#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){

    int numEmployees = 0;

//while loop that runs until the end of the linked list is reached
    while (headLL != NULL){

//increment the numEmployees count to keep track of the number of employees and then move to the next employee node
        numEmployees++;
	headLL = headLL->nextEmployee;
    }

//return the counted number of employees
    return numEmployees;
}
