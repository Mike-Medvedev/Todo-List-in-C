#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include <string.h>

struct arrayOfStrings{
int size;
char **stringArrayPtr;
};

void printOptions();
int getUserInput(int* selection);
void addTask(struct arrayOfStrings *myArray);
void viewTasks(struct arrayOfStrings *myArray);
void deleteTasks(struct arrayOfStrings *myArray);
void printCell(char* cellValue);

int main() {
    int selection;
    bool loop = true;

    struct arrayOfStrings *myArray = malloc(sizeof(struct arrayOfStrings));

    myArray->size = 10;
    myArray->stringArrayPtr = malloc(myArray->size * sizeof(char*));

    //init all pointers to null
    for(int i = 0; i < myArray->size; i++ ){
        myArray->stringArrayPtr[i] = NULL;
    }
    
    if(myArray->stringArrayPtr == 0 || myArray->stringArrayPtr == NULL){
        printf("memory allocation failed!");
    }

    printf("\n\nWelcome to the To-do List Manager\n\n\n");


    while(loop){
        printOptions();
        selection = getUserInput(&selection);
        switch(selection){
            case 1:
                addTask(myArray);
                break;
            case 2:
                viewTasks(myArray);
                break;
            case 3:
                deleteTasks(myArray);
                break;
            case 4:
                loop = false;
                break;
            default:
            printf("\n\nPlease Enter a Valid Number 1 - 4\n\n");
                break;
            
        }
    }
    for (int i =0; i<myArray->size; i++){
        free(myArray->stringArrayPtr[i]);
        myArray->stringArrayPtr[i] = NULL;
    }
    free(myArray->stringArrayPtr);
    free(myArray);
}

void printOptions(){
    printf("\n1. Add a task\n2. View Tasks\n3. Delete a task\n4. Exit\n");
}
int getUserInput(int *selection){
    printf("\n Enter a Number: ");
    scanf("%d", selection);
    return *selection;
}
void addTask(struct arrayOfStrings *myArray){
    char* inputString = malloc(20 * sizeof(char));
    printf("Please enter a task\n");
    scanf("%19s", inputString);
    printf("\n\n");
    printf("You entered: %s\n", inputString);

    //Search through the array until we find a null pointer
    //Then add the new task there
    for(int i = 0; i < myArray->size; i++){
        if(myArray->stringArrayPtr[i] != NULL){
            if(i == myArray->size-1){
                //If last element was not null, array is full, increase size
                int newSize = myArray->size + 10;
                char **newArray = realloc(myArray->stringArrayPtr, newSize * sizeof(char*));
                if (newArray == NULL) {
                    printf("Memory allocation failed!\n");
                    exit(1);
                }
                myArray->stringArrayPtr = newArray;
                myArray->size = newSize;
                break;
            }
            continue;
        }
        printf("Adding task: %s", inputString);
        myArray->stringArrayPtr[i] = inputString;
            break;
    }
}
void viewTasks(struct arrayOfStrings *myArray){
    printf("Current Tasks: \n");
    
    for(int i = 0; i < myArray->size; i++){
        if(myArray->stringArrayPtr[i] == NULL) return;
        printCell(myArray->stringArrayPtr[i]);
    }

}
void deleteTasks(struct arrayOfStrings *myArray){
    printf("Enter the task to delete\n");
   char* taskToDelete = malloc(20 * sizeof(char));
   scanf("%s", taskToDelete);
   for(int i = 0; i < myArray->size; i++){
    if(myArray->stringArrayPtr[i] != NULL && strcmp(myArray->stringArrayPtr[i], taskToDelete) == 0){
        free(myArray->stringArrayPtr[i]);
        myArray->stringArrayPtr[i]= NULL;
        printf("Deleted Task: %s", taskToDelete);
        break;
    }
   }
   free(taskToDelete);
}
//Create a cell around text +--+
                        //  +--+
void printCell(char* cellValue){
    int sizeOfValue = strlen(cellValue);
    char *topBorder = malloc((2 + sizeOfValue) * sizeof(char));
    char *cells = malloc((2 + sizeOfValue) * sizeof(char));
        cells[0] = '|';
        for(int i = 1; i <= sizeOfValue; i++){
            cells[i] = ' ';
        }
        strncpy(&cells[1], cellValue, sizeOfValue);
        cells[sizeOfValue + 1] = '|';
        cells[sizeOfValue + 2] = '\0';
        topBorder[0] = '+';
        for(int i = 1; i <= sizeOfValue; i++){
            topBorder[i] = '-';
        }
        topBorder[sizeOfValue + 1] = '+';
        topBorder[sizeOfValue + 2] = '\0';

        printf("%s\n", topBorder);
        printf("%s\n", cells);
        printf("%s\n", topBorder);

        free(topBorder);
        free(cells);
}