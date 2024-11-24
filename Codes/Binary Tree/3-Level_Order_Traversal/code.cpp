#include <iostream>
#include <vector>
#include <queue>
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

vector<int> levelOrder(Node *root)
{
  queue<Node *> q;
  q.push(root);
  vector<int> ans;
  Node *temp;

  while (!q.empty())
  {
    temp = q.front();
    q.pop();
    ans.push_back(temp->data);
    if (temp->left)
    {
      q.push(temp->left);
    }
    if (temp->right)
    {
      q.push(temp->right);
    }
  }

  return ans;
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

  vector<int> finalAns = levelOrder(root);
  for (int i = 0; i < finalAns.size(); i++)
  {
    cout << finalAns[i] << " ";
  }

  return 0;
}