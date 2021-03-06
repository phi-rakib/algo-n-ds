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
      node *newNode = new node();
      newNode->value = value;
      newNode->next = NULL;

      if(head == NULL) {
        head = newNode;
      } else {
        node *currentNode = head;
        while(currentNode->next != NULL) {
          currentNode = currentNode->next;
        }
        currentNode->next = newNode;
      }
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
  SinglyLinkedList list;
  
  list.addNode(4);
  list.addNode(6);
  list.addNode(9);
  list.addNode(7);

  list.display();

  cout << "The size of the linked list is " << list.size() << endl;

  cout << "7 " << (list.findNode(7) ? "Found" : "Not Found") << endl;
  cout << "6 " << (list.findNode(6) ? "Found" : "Not Found") << endl;
  cout << "5 " << (list.findNode(5) ? "Found" : "Not Found") << endl;

  cout << "Deleting node with value 7" << endl;
  list.deleteNode(7);
  cout << "The size of the linked list is " << list.size() << endl;
  list.display();

  cout << "Deleting node with value 4" << endl;
  list.deleteNode(4);
  cout << "The size of the linked list is " << list.size() << endl;
  list.display();

  cout << "Adding Nodes" << endl;
  list.addNode(11);
  list.addNode(21);
  cout << "The size of the linked list is " << list.size() << endl;
  list.display();

  cout << "Deleting node with value 9" << endl;
  list.deleteNode(9);
  cout << "The size of the linked list is " << list.size() << endl;
  list.display();
  return 0;
}
