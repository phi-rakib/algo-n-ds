#include <iostream>
using namespace std;

struct node {
  int value;
  node *next;
};
class SinglyLinkedList {
  private:
    node *head;

  public:
    SinglyLinkedList() {
      head = NULL;
    }

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

    int size() {
      int count = 0;
      node *currentNode = head;
      
      while(currentNode != NULL) {
        currentNode = currentNode->next;
        count++;
      }

      return count;
    }

    bool findNode(int value) {
      node *currentNode = head;
      while(currentNode != NULL) {
        if(currentNode->value == value)
          return true;
        currentNode = currentNode->next;
      }
      return false;
    }

    void deleteNode(int value) {
      if(head == NULL)
        return;

      node *currentNode = head;
      node *previousNode = head;

      while(currentNode != NULL) {
        if(currentNode->value == value) {
          if(currentNode == head) {
            node *tmp = head;
            head = currentNode->next;
            delete tmp;
          }
          else
          {
            previousNode->next = currentNode->next;
            delete currentNode;
          }
          return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
      }
    }
};

int main() {
  
  return 0;
}
