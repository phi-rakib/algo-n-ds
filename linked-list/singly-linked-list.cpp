#include <iostream>
using namespace std;

struct node
{
  int value;
  node *next;
};

struct SinglyLinkedList
{
  node *head;

  SinglyLinkedList()
  {
    this->head = NULL;
  }

  void addNode(int value)
  {
    node *newNode = new node();
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      node *currentNode = head;
      while (currentNode->next != NULL)
      {
        currentNode = currentNode->next;
      }
      currentNode->next = newNode;
    }
  }

  void display()
  {
    node *currentNode = head;
    while (currentNode != NULL)
    {
      cout << currentNode->value << endl;
      currentNode = currentNode->next;
    }
  }

  int size()
  {
    int count = 0;
    node *currentNode = head;

    while (currentNode != NULL)
    {
      currentNode = currentNode->next;
      count++;
    }

    return count;
  }

  bool findNode(int value)
  {
    node *currentNode = head;
    while (currentNode != NULL)
    {
      if (currentNode->value == value)
        return true;
      currentNode = currentNode->next;
    }
    return false;
  }

  void deleteNode(int value)
  {
    if (head == NULL)
      return;

    node *currentNode = head;
    node *previousNode = head;

    while (currentNode != NULL)
    {
      if (currentNode->value == value)
      {
        if (currentNode == head)
        {
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

int main()
{
  SinglyLinkedList singlyLinkedList;
  singlyLinkedList.addNode(4);
  singlyLinkedList.addNode(6);
  singlyLinkedList.addNode(9);
  singlyLinkedList.addNode(7);

  singlyLinkedList.display();

  cout << "The size of the linked list is " << singlyLinkedList.size() << endl;

  cout << "7 " << (singlyLinkedList.findNode(7) ? "Found" : "Not Found") << endl;
  cout << "6 " << (singlyLinkedList.findNode(6) ? "Found" : "Not Found") << endl;
  cout << "5 " << (singlyLinkedList.findNode(5) ? "Found" : "Not Found") << endl;

  cout << "Deleting node with value 7" << endl;
  singlyLinkedList.deleteNode(7);
  cout << "The size of the linked list is " << singlyLinkedList.size() << endl;
  singlyLinkedList.display();

  cout << "Deleting node with value 4" << endl;
  singlyLinkedList.deleteNode(4);
  cout << "The size of the linked list is " << singlyLinkedList.size() << endl;
  singlyLinkedList.display();

  singlyLinkedList.addNode(11);
  singlyLinkedList.addNode(21);
  cout << "The size of the linked list is " << singlyLinkedList.size() << endl;
  singlyLinkedList.display();

  cout << "Deleting node with value 9" << endl;
  singlyLinkedList.deleteNode(9);
  cout << "The size of the linked list is " << singlyLinkedList.size() << endl;
  singlyLinkedList.display();

  return 0;
}