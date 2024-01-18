#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]){

    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    int positionName = 0;

//scan the string entered and store the two strings into separate values that are named firstName and lastName
    sscanf(whichName,"%s %s", firstName, lastName);

//while loop that runs until the end of the linked list is reached
    while (headLL != NULL){

//using strcmp, compare the names of the employee with the name entered by the user and if it equals zero then it means that the name is found and return the position of the employee
        if (strcmp(headLL->fname, firstName) == 0 && strcmp(headLL->lname, lastName) == 0){
            return positionName;
        }

//move to the next employee node
        headLL = headLL->nextEmployee;
	positionName++;
    }

//once again return -1 to signify that they employee could not be found
    return -1;
}
