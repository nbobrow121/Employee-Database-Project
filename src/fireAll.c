#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL){

    a3Emp *employee = *headLL;

//while loop that runs until the end of the linked list is reached
    while (employee != NULL){

//move to the next employee in the linked list and free the employee
        employee = employee->nextEmployee;
	free(employee);
    }

//set the pointer of headLL to NULL
    *headLL = NULL;
}
