#include <stdio.h>
#include <stdlib.h>

 struct Node  {
    int number;
    struct Node* next;
} ;

struct Node* head = NULL;

void createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->number = data;
    newNode->next = head;
    head = newNode;
}

void printNodeList() {
    struct Node* currentNode = head;
    while(currentNode != NULL) {
        printf("%i\t", currentNode->number);
        currentNode = currentNode-> next;
    }
}


int main() {
    char continueAdding = 'y';
    do {
        int input;
        printf("Please type a integer value: ");
        scanf("%d", &input);
        fflush(stdin);

        createNode(input);

        printf("Do you want to continue? y/n\n");
        scanf("%c", &continueAdding);
        fflush(stdin);

    } while(continueAdding == 'y');

    printNodeList();

    return 0;
}
