#include <iostream>
#include "tree_templ.cpp"

using namespace std;

int findSubtreeSize(node<int>* root)
{
  if (root == NULL)
  {
    return 0;
  }

  return 1 + findSubtreeSize(root->Left) + findSubtreeSize(root->Right);
}

int findSum(node<int>* numberTreeRoot, node<char>* operationsTreeRoot)
{
  if (numberTreeRoot == NULL)
  {
    return 0;
  }

  int currentValue = 0;
  if (operationsTreeRoot->inf == '+')
  {
    currentValue = numberTreeRoot->inf + findSubtreeSize(numberTreeRoot);
  }

  else if (operationsTreeRoot->inf == '-')
  {
    currentValue = numberTreeRoot->inf - findSubtreeSize(numberTreeRoot);
  }

  else
  {
    currentValue = numberTreeRoot->inf * findSubtreeSize(numberTreeRoot);
  }

  return currentValue + findSum(numberTreeRoot->Left, operationsTreeRoot->Left) + findSum(numberTreeRoot->Right, operationsTreeRoot->Right);

}

int main()
{
  tree<int> numberTree;
  numberTree.Create();

  tree<char> operationsTree;
  operationsTree.Create();

  cout << findSum(numberTree.getRoot(), operationsTree.getRoot())<< endl;

  return 0;
}
