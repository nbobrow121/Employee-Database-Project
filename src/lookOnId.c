#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId){

    int positionId = 0;

//while loop that runs until the end of the linked list is reached
    while (headLL != NULL) {

//if statement that checks if the employee ID of the current employee node is equal to the entered employee ID by the user and if it is then return the position
        if (headLL->empId == whichEmpId) {
            return positionId;
        }

//move onto the next employee node
        headLL = headLL->nextEmployee;
        positionId++;
    }

//return -1 to signify that the employee could not be found
    return -1;
}
