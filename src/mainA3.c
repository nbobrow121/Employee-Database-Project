#include "../include/headerA3.h"

int main(int argc, char * argv[]){

    struct employee *headLL = NULL;
    loadEmpData(&headLL, "proFile.txt");
    int whichTask;
    int whichOne;
    int whichEmpId;
    int positionId;
    char whichName[MAX_LENGTH];
    int positionName;
    int countNum;
    int fireWhichOne;
    char yesOrNo[1];

    do {
	printf("\n**********_Menu_**********");
	printf("\n1 - Add a new employee\n");
        printf("2 - Print data of all employees\n");
	printf("3 - Print employee data at position n in the LL\n");
	printf("4 - View employee data based on empId\n");
        printf("5 - View employee data based on full name\n");
	printf("6 - Count number of employees\n");
        printf("7 - Sort Employee data in ascending order of empId\n");
	printf("8 - Fire the nth employee\n");
	printf("9 - Fire all employees\n");
	printf("10 - Quit\n");
	printf("Choose a menu option: ");
	scanf("%d", &whichTask);
        printf("\n");

	switch (whichTask){
	    case 1:
	        recruitEmployee(&headLL);	//call function 1
	        break;
	    case 2:
	        printAll(headLL);		//call function 2
		break;
	    case 3:
	        printf("\nEnter a position: ");
	        scanf("%d", &whichOne);
		printf("\n");
		printOne(headLL, whichOne);	//call function 3
	        break;
	    case 4:
		printf("Enter an employee ID: ");
                scanf("%d", &whichEmpId);
		printf("\n");
                positionId = lookOnId(headLL, whichEmpId);	//call function 4

//this is self explanitory
		if (positionId == -1){
		    printf("The ID entered does not exist\n");
		}
		else{

//basically the same code as in printAll except we use a temporary pointer to print the information
                    a3Emp *temp = headLL;
                    for (int i = 0; i < positionId; i++) {
                        temp = temp->nextEmployee;
                    }
                    printf("Employee id: %d\n", temp->empId);
                    printf("First name: %s\n", temp->fname);
                    printf("Last name: %s\n", temp->lname);
		    printf("Dependents: ");
                    for (int j = 0; j < temp->numDependents; j++){
                        printf("%s", temp->dependents[j]);
	                if (j < temp->numDependents - 1){
	                    printf(", ");
	                }
                    }
		    printf("\n");
		}
		break;
	    case 5:

//get the user input for the full name of the employee
		getchar();
		printf("Enter the full name of the employee: ");
		fgets(whichName, 100, stdin);
		positionName = lookOnFullName(headLL, whichName);	//call function 5
		if (positionName == -1){
                    printf("The ID entered does not exist\n");
                }
                else{

//exactly the same as case 4 and how we print the employee information (WE USE THIS MANY TIMES)
                    a3Emp *temp = headLL;
                    for (int i = 0; i < positionName; i++) {
                        temp = temp->nextEmployee;
                    }
                    printf("Employee id: %d\n", temp->empId);
                    printf("First name: %s\n", temp->fname);
                    printf("Last name: %s\n", temp->lname);
                    printf("Dependents: ");
                    for (int j = 0; j < temp->numDependents; j++){
                        printf("%s", temp->dependents[j]);
                        if (j < temp->numDependents - 1){
                            printf(", ");
                        }
                    }
                    printf("\n");
                }
		break;
	    case 6:
		countNum = countEmployees(headLL);			//call function 6
		printf("Total number of employees = %d\n", countNum);
		break;
	    case 7:
		sortEmployeesId(headLL);		//call function 7
		break;
	    case 8:
		countNum = countEmployees(headLL);	//call function 6 because we need to know the num of employees and print it first
	        printf("Currently there are %d employees.\n", countNum);
		printf("Which employee do you wish to fire - enter a value between 1 and %d: ", countNum);
		scanf("%d", &fireWhichOne);
		fireOne(&headLL, fireWhichOne);		//call function 8
		countNum = countEmployees(headLL);	//once again call function 6 and print the number of employees so we can see the num after one employee got fired
		printf("There are now %d employees.\n", countNum);
		break;
	    case 9:
		printf("Are you sure you want to fire everyone: ");
		scanf("%s", yesOrNo);

//if statement to check if the user wants to fire all employees
		if (strcmp(yesOrNo, "y") == 0){
		    fireAll(&headLL);					//call function 9
		    printf("All fired. Linked list is now empty.\n");
		}
		else{
		    printf("None were fired.\n");
		}
		break;
	    case 10:

//set whichTask equal to 0 so that the program ends
		whichTask = 0;
		break;

	    default: printf("Invalid choice\n");
	}
    } while(whichTask >= 1 && whichTask <= 10);

    return 0;
}
