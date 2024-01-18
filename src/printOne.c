#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne){

//for loop that traverses the linked list and stops at the node that is in the position entered by the user in main
    for (int i = 0; i < whichOne - 1; i++){
        headLL = headLL->nextEmployee;
    }

//same as function printAll.c just print all of the information for the employee that is in position whichOne
    printf("Employee id: %d\n", headLL->empId);
    printf("First name: %s\n", headLL->fname);
    printf("Last name: %s\n", headLL->lname);
    printf("Dependents: ");
    for (int j = 0; j < headLL->numDependents; j++){
        printf("%s", headLL->dependents[j]);
	if (j < headLL->numDependents - 1){
	    printf(", ");
	}
    }
    printf("\n");
}
