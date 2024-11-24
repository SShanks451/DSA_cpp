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

void PreOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " ";
  PreOrder(root->left);
  PreOrder(root->right);
}

void InOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  InOrder(root->left);
  cout << root->data << " ";
  InOrder(root->right);
}

void PostOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  PostOrder(root->left);
  PostOrder(root->right);
  cout << root->data << " ";
}

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

  cout << "Preorder Traversal: ";
  PreOrder(root);

  cout << "\nInorder Traversal: ";
  InOrder(root);

  cout << "\nPostorder Traversal: ";
  PostOrder(root);

  return 0;
}