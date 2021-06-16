#include <iostream>
using namespace std;

struct node {
  int value;
  node *next;
};

node *head = NULL;

void addNode(int value) {
  if(head == NULL) {
    head = new node();
    head->value = value;
    head->next = NULL;
    return;
  }
  
  node *currentNode = head;
  while(currentNode->next != NULL) {
    currentNode = currentNode->next;
  }

  node *newNode = new node();
  newNode->value = value;
  newNode->next = NULL;

  currentNode->next = newNode;
}

int main() {
  
  return 0;
}