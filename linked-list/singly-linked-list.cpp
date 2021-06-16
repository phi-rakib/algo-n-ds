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

void display() {
  node *currentNode = head;
  while (currentNode != NULL) {
    cout << currentNode->value << endl;
    currentNode = currentNode->next;
  }
}

int main() {
  addNode(4);
  addNode(6);
  addNode(9);
  addNode(7);

  display();
  return 0;
}