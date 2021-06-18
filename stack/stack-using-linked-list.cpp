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

int main()
{
  push(4);
  cout << "Top of the stack is " << peek() << endl;
  
  push(6);
  cout << "Top of the stack is " << peek() << endl;
  
  push(9);
  cout << "Top of the stack is " << peek() << endl;

  return 0;
}