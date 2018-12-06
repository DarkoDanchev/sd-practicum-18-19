#include <iostream>
#include "tree_templ.cpp"

using namespace std;

bool isLessOrEqual(int firstNumber, int secondNumber)
{
  return firstNumber <= secondNumber;
}

bool isGreater(int firstNumber, int secondNumber)
{
  return firstNumber > secondNumber;
}

bool isSubtreeBST(node<int>* root, int parentValue, bool (*correctOrder)(int, int))
{
  if (root == NULL)
  {
    return true;
  }

  return correctOrder(parentValue, root->inf) &&
         isSubtreeBST(root->Left, parentValue, correctOrder) &&
         isSubtreeBST(root->Right, parentValue, correctOrder);
}

bool isBinarySearchTree(node<int>* root)
{
  if (root == NULL)
  {
    return true;
  }

  return isSubtreeBST(root->Left, root->inf, isGreater) &&
         isSubtreeBST(root->Right, root->inf, isLessOrEqual) &&
         isBinarySearchTree(root->Left) &&
         isBinarySearchTree(root->Right);
}

int main()
{
  tree<int> tr;
  tr.Create();

  cout << boolalpha << isBinarySearchTree(tr.getRoot()) << endl;

  return 0;
}
