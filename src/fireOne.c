#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne){

    a3Emp *employee = *headLL;
    a3Emp *previousEmployee = NULL;
    int num = 0;

//while loop that runs until the end of the linked list is reached
    while (employee != NULL){

//increment the linked list by one
        num++;

//if the num is equal to the number entered by the user than it goes to the next if statement
	if (num == whichOne){

//if the previousEmployee is equal to NULL then set the head equal to the nextEmployee, this accounts for the case when there is only one employee
	    if (previousEmployee == NULL){
		*headLL = employee->nextEmployee;
	    }

//else, set the previousEmployee->nextEmployee equal to the employee->nextEmployee
	    else{
		previousEmployee->nextEmployee = employee->nextEmployee;
	    }
	    printf("Employee [Id: %d] fired.\n", employee->empId);

//free employee to get rid of the employees information that is being fired
	    free(employee);
	    return;
	}

//set the previous employee equal to employee and move on to the next employee node in the linked list
	previousEmployee = employee;
	employee = employee->nextEmployee;
    }

//if the employee could not be found then print that the employee could not be found in the position entered by the user
    printf("Could not find the employee in position %d.\n", whichOne);
}
