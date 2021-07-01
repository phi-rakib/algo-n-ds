#include <iostream>
using namespace std;

class BST {
  public:
    int data;
    BST *left, *right;
    BST();
};

BST::BST() {
  data = 0;
  left = right = NULL;
}

int main()
{
  
  return 0;
}