#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node *next;
};

struct Node *head = NULL;

void createNode(int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->number = data;
  if (head == NULL) {
    head = newNode;
    newNode->next = newNode;
  } else {
    newNode->next = head->next;
    head->next = newNode;
    head = newNode;
  }
}

void dequeue() {
  struct Node *lastNode = head;

  if (lastNode == NULL) return;

  struct Node *currentNode = head->next;

  if (currentNode == NULL) free(lastNode);
  else {
    lastNode->next = currentNode->next;
    free(currentNode);
  }
}

void printNodeList() {
  struct Node *currentNode = head;
  struct Node *lastNode = currentNode;

  if (currentNode == NULL) return;

  do {
    printf("%i\t", currentNode->number);
    currentNode = currentNode->next;
  } while (currentNode != lastNode);
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
  } while (continueAdding == 'y');

  printNodeList();

  return 0;
}
