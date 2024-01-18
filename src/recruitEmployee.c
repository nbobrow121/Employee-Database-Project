#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL){

    int num = 0;
    char selection = 'y';
    int dependent = 0;
    char depend[MAX_LENGTH];
    int length;

//dynamically allocate memory for newEmployee
    a3Emp *newEmployee = malloc(sizeof(a3Emp));

//ask the user to enter first name and last name of employee
    printf("Enter the first name of the employee: ");
    scanf("%s", newEmployee->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmployee->lname);

//dynamically allocate memory the size of 1 for the dependents of the employee
    newEmployee->nextEmployee = NULL;
    newEmployee->dependents = malloc(1 *sizeof(char *));

//while look that runs until the user enters something other than y
    while (selection == 'y'){
	printf("\n");
        printf("Enter name of dependent# %d: ", dependent + 1);
        scanf("%s", depend);

//dynamically allocate memory for more dependents if the user wants to enter more
        newEmployee->dependents[dependent] = malloc((strlen(depend) + 1) * sizeof(char));
        strcpy(newEmployee->dependents[dependent], depend);
	dependent++;
	printf("Do you have any more dependents? ");
	scanf(" %c", &selection);
    }

//set numDependents equal dependent so that we can print the number of dependents that the employee has
    newEmployee->numDependents = dependent;
    printf("\nYou have %d dependents.\n", dependent);

//for loop to calculate the employee ID
    for (int i = 0; i < strlen(newEmployee->fname); i++){
        num += newEmployee->fname[i];
    }

//find the length of the last name and add it to the number that was calculated above based on ASCII values of first name
    length = strlen(newEmployee->lname);
    newEmployee->empId = num + length;

//create a temporary pointer for the linked list
    a3Emp *temp = *headLL;

//while loop that runs until the end of the linked list is reached
    while (temp != NULL) {

//if there are to empId that are equal than pick a random number and add it to the employee ID
        if (temp->empId == newEmployee->empId) {
            newEmployee->empId = rand() % 999 + 1;

//go back to the start
                temp = *headLL;
        }

//move onto the next employee node in the linked list
        temp = temp->nextEmployee;
    }

    printf("\nYour computer-generated empId is %d\n", newEmployee->empId);

//insert the employee entered by the user into the end of the linked list
    if (*headLL == NULL){
        *headLL = newEmployee;
    }
    else{
        a3Emp *temp = *headLL;
	while(temp->nextEmployee != NULL){
	    temp = temp->nextEmployee;
	}
	temp->nextEmployee = newEmployee;
    }

}
