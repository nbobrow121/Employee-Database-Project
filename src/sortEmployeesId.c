#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL){

    a3Emp *tempLL = headLL;
    a3Emp *tail = NULL;
    a3Emp *current = NULL;
    char **dependents;
    char fname[MAX_LENGTH];
    char lname[MAX_LENGTH];
    int empId;
    int numDependents;

//while loop that runs until the end of the linked list is reached
    while (tempLL != NULL){

//set tail equal to tempLL because the current node has the tail of empId
        tail = tempLL;

//with the while loop and if statement we check if the remainder of the linked list has a lower empId
	current = tempLL->nextEmployee;
	while (current != NULL){
	    if (current->empId < tail->empId){

//if there is an empId that is less then set tail = current
                tail = current;
	    }

//move onto the next employee node
	    current = current->nextEmployee;
	}

//If statement that swaps the employee node if the current does not contain the lowest employee ID
	if (tail != tempLL){

//strcpy information from current to new variables
	    strcpy(fname, tempLL->fname);
	    strcpy(lname, tempLL->lname);
	    empId = tempLL->empId;
	    numDependents = tempLL->numDependents;
	    dependents = tempLL->dependents;

//strcpy information from the employee node that has the lowest employee ID to the current
	    strcpy(tempLL->fname, tail->fname);
	    strcpy(tempLL->lname, tail->lname);
	    tempLL->empId = tail->empId;
	    tempLL->numDependents = tail->numDependents;
	    tempLL->dependents = tail->dependents;

//strcpy information from the new variables to the employee node that has the lowest employee ID
	    strcpy(tail->fname, fname);
	    strcpy(tail->lname, lname);
	    tail->empId = empId;
	    tail->numDependents = numDependents;
	    tail->dependents = dependents;
	}

//move to the next employee node in the linked list
	tempLL = tempLL->nextEmployee;
    }

    int numEmployees = 0;

//just like printAll.c function just print all of the employee information with while loop, for loop, and an if statement
    while (headLL != NULL){
	numEmployees++;
        printf("Employee # %d:\n", numEmployees);
	printf("      Employee id: %d\n", headLL->empId);
	printf("      First name: %s\n", headLL->fname);
	printf("      Last name: %s\n", headLL->lname);
	printf("      Dependents [%d]: ", headLL->numDependents);

	for (int i = 0; i < headLL->numDependents; i++){
	    printf("%s", headLL->dependents[i]);
	    if (i < headLL->numDependents - 1){
	        printf(", ");
	    }
	}
	printf("\n\n");

//move to the next employee node in the linked list
	headLL = headLL->nextEmployee;
    }
}
