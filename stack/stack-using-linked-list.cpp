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

int main()
{

  return 0;
}