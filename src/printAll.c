#include "../include/headerA3.h"

void printAll (struct employee * headLL){

    int numEmployees = 0;

//while loop that runs until the end of the linked list is reached
    while (headLL != NULL){
	numEmployees++;

//print the information of the employees
        printf("Employee # %d:\n", numEmployees);
	printf("      Employee id: %d\n", headLL->empId);
	printf("      First name: %s\n", headLL->fname);
	printf("      Last name: %s\n", headLL->lname);
	printf("      Dependents [%d]: ", headLL->numDependents);

//for loop and if statement that prints the dependents of each employee and adds a coma if the employee has more than 1 dependent
	for (int i = 0; i < headLL->numDependents; i++){
	    printf("%s", headLL->dependents[i]);
	    if (i < headLL->numDependents - 1){
	        printf(", ");
	    }
	}
	printf("\n\n");

//move to the next employee node
	headLL = headLL->nextEmployee;
    }
    printf("Currently, there are %d employees.\n", numEmployees);
}
