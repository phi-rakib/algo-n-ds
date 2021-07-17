#include <iostream>
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
      std::cout << currentNode->value << std::endl;
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

  std::cout << "The size of the linked list is " << singlyLinkedList.size() << std::endl;

  std::cout << "7 " << (singlyLinkedList.findNode(7) ? "Found" : "Not Found") << std::endl;
  std::cout << "6 " << (singlyLinkedList.findNode(6) ? "Found" : "Not Found") << std::endl;
  std::cout << "5 " << (singlyLinkedList.findNode(5) ? "Found" : "Not Found") << std::endl;

  std::cout << "Deleting node with value 7" << std::endl;
  singlyLinkedList.deleteNode(7);
  std::cout << "The size of the linked list is " << singlyLinkedList.size() << std::endl;
  singlyLinkedList.display();

  std::cout << "Deleting node with value 4" << std::endl;
  singlyLinkedList.deleteNode(4);
  std::cout << "The size of the linked list is " << singlyLinkedList.size() << std::endl;
  singlyLinkedList.display();

  singlyLinkedList.addNode(11);
  singlyLinkedList.addNode(21);
  std::cout << "The size of the linked list is " << singlyLinkedList.size() << std::endl;
  singlyLinkedList.display();

  std::cout << "Deleting node with value 9" << std::endl;
  singlyLinkedList.deleteNode(9);
  std::cout << "The size of the linked list is " << singlyLinkedList.size() << std::endl;
  singlyLinkedList.display();

  return 0;
}