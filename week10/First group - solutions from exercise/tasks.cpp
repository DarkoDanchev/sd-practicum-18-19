#include <iostream>
#include "tree_templ.cpp"
#include <deque>
#include <cassert>

using namespace std;

// task 1
bool isLessOrEqual(int firstNumber, int secondNumber)
{
  return firstNumber <= secondNumber;
}

bool isGreater(int firstNumber, int secondNumber)
{
  return firstNumber > secondNumber;
}

bool isSubtreeBST(node<int>* root, int parentValue,
                  bool (*correctOrder)(int, int))
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

// task 2
template<typename T>
int GetNodeCount(node<T>* root)
{
  if(root==nullptr)
  {
    return 0;
  }
  return 1 + GetNodeCount(root->Left) + GetNodeCount(root->Right);
}

double GetSum(node<double>* NumberTreeRoot, node<char>* OperationTreeRoot)
{
  if(NumberTreeRoot==nullptr || OperationTreeRoot==nullptr)
  {
    return 0;
  }

  double CurrentNumber = NumberTreeRoot->inf;
  char Operation = OperationTreeRoot->inf;
  int NodeCount = GetNodeCount(NumberTreeRoot);

  double Sum = 0;

  switch(Operation)
  {
    case '+':
    {
        Sum = CurrentNumber + NodeCount;
        break;
    }
    case '-':
    {
        Sum = CurrentNumber - NodeCount;
        break;
    }
    case '*':
    {
        Sum = CurrentNumber * NodeCount;
        break;
    }
    case '/':
    {
        assert(NodeCount!=0);
        Sum = CurrentNumber / NodeCount;
        break;
    }
    default:
    {
        cout<<"Invalid operation: "<<Operation<<endl;
        assert(false);
    }
  }

  return Sum + GetSum(NumberTreeRoot->Left,OperationTreeRoot->Left) +
               GetSum(NumberTreeRoot->Right,OperationTreeRoot->Right);
}

// task 3
bool areSymmetricalTrees(node<int>* leftTree, node<int>* rightTree)
{
  if(!leftTree && !rightTree)
  {
    return true;
  }

  if(!leftTree || !rightTree)
  {
    return false;
  }

  return leftTree->inf == rightTree->inf &&
  areSymmetricalTrees(leftTree->Left, rightTree->Right) &&
  areSymmetricalTrees(leftTree->Right, rightTree->Left);
}

bool isMirroringTree(node<int>* root)
{
  if(!root)
  {
    return true;
  }
  return areSymmetricalTrees(root->Left, root->Right);
}

// task 4
void getLevel(deque<int>& d, node<int>* root, int level)
{
  if (!root)
    return;
  if (level == 0)
  {
    d.push_back(root->inf);
    return;
  }
  getLevel(d, root->Left, level - 1);
  getLevel(d, root->Right, level - 1);
}

bool isPalindrome(node<int>* root, int level)
{
  if (!root)
    return true;

  deque<int> d; getLevel(d, root, level);

  while (d.size() > 1)
  {
    if (d.front() != d.back())
      return false;

    d.pop_front();
    d.pop_back();
  }

  return true;
}

int main()
{
  tree<int> tr44;
  tr44.Create3(4, tree<int>(), tree<int>());

  tree<int> tr1;
  tr1.Create3(1, tree<int>(), tree<int>());

  tree<int> tr4;
  tr4.Create3(4, tree<int>(), tree<int>());

  tree<int> tr2;
  tr2.Create3(2, tr1, tr4);

  tree<int> tr7;
  tr7.Create3(7, tree<int>(), tree<int>());

  tree<int> tr3;
  tr3.Create3(3, tr2, tr44);

  tree<int> tr5;
  tr5.Create3(5, tr3, tr7);

  cout << boolalpha << isBinarySearchTree(tr5.getRoot()) << endl;

  cout << boolalpha << isMirroringTree(tr5.getRoot()) << endl;

  tree<int> tr;
  tr.Create();
  cout << boolalpha << isMirroringTree(tr.getRoot()) << endl;

  return 0;
}
