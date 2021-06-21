#include <iostream>
using namespace std;

struct node {
  int value;
  node *next;
};

node *top = NULL;

void push(int value)
{
  node *tmp = new node();
  tmp->value = value;
  tmp->next = top;
  top = tmp;
}

int peek() {
  int value = top->value;
  return value;
}

int size() {
  node *tmp = top;
  int count = 0;
  while (tmp != NULL) {
    tmp = tmp->next;
    count++;
  }
  return count;
}

bool empty() {
  return top == NULL;
}

int pop() {
  int value = top->value;
  top = top->next;
  return value;
}

int main()
{
  cout << "Stack is " << (empty() ? "Empty" : "Not Empty") << endl;

  push(4);
  cout << "Top of the stack is " << peek() << endl;
  cout << "Size of the stack is " << size() << endl;
  
  push(6);
  cout << "Top of the stack is " << peek() << endl;
  cout << "Size of the stack is " << size() << endl;
  
  push(9);
  cout << "Top of the stack is " << peek() << endl;
  cout << "Size of the stack is " << size() << endl;

  cout << "Stack is " << (empty() ? "Empty" : "Not Empty") << endl;

  return 0;
}