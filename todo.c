#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

struct arrayOfStrings{
int size;
char **stringArrayPtr;
};

void printOptions();
int getUserInput(int* selection);
void addTask(struct arrayOfStrings *myArray);
void viewTasks(struct arrayOfStrings *myArray);
void deleteTasks();

int main() {
    int selection;
    bool loop = true;

    struct arrayOfStrings *myArray = malloc(sizeof(struct arrayOfStrings));

    myArray->size = 10;
    myArray->stringArrayPtr = malloc(myArray->size * sizeof(char*));

    for(int i = 0; i < myArray->size; i++ ){
        myArray->stringArrayPtr[0] = NULL;
    }
    
    if(myArray->stringArrayPtr == 0 || myArray->stringArrayPtr == NULL){
        printf("memory allocation failed!");
    }

    for(int i = 0; i < myArray->size; i++){
        printf("%p\n", &myArray->stringArrayPtr[i]);
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
                deleteTasks();
                break;
            case 4:
                loop = false;
                break;
            default:
            printf("\n\nPlease Enter a Valid Number 1 - 4\n\n");
                break;
            
        }
    }
    
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
    scanf("%s", inputString);
    printf("\n\n");
    printf("You entered: %s\n", inputString);
    // myArray.stringArrayPtr[0] = inputString;

    for(int i = 0; i < myArray->size; i++){
        if(myArray->stringArrayPtr[i] != NULL){
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
        printf("%s\n", myArray->stringArrayPtr[i]);
    }

}
void deleteTasks(){
   
}