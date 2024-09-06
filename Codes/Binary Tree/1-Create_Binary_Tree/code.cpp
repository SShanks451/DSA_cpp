#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *left, *right;

  Node(int value)
  {
    data = value;
    left = right = NULL;
  }
};

Node *BinaryTree()
{
  int x;
  cin >> x;
  if (x == -1)
  {
    return NULL;
  }

  Node *temp = new Node(x);

  cout << "Enter left node of " << x << endl;
  temp->left = BinaryTree();

  cout << "Enter right node of " << x << endl;
  temp->right = BinaryTree();

  return temp;
}

int main()
{
  cout << "Enter root Node: " << endl;

  Node *root;
  root = BinaryTree();

  return 0;
}