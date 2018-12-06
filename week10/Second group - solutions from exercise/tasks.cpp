#include <iostream>
#include <vector>
#include "tree_templ.cpp"

using namespace std;

vector<int> vertices;

// First solution to task 1
//void extractVertices(node<int>* root)
//{
//  if (root == NULL)
//  {
//    return;
//  }
//
//  extractVertices(root->Left);
//  vertices.push_back(root->inf);
//  extractVertices(root->Right);
//}
//
//bool isBinarySearchTree()
//{
//  int n = vertices.size();
//  for (int i = 0; i < n - 1; i++)
//  {
//    if (vertices[i] > vertices[i + 1])
//    {
//      return false;
//    }
//  }
//
//  return true;
//}

// Second solution to task 1
bool isGreaterOrEqual(int firstNumber,int secondNumber)
{
  return firstNumber >= secondNumber;
}

bool isLess(int firstNumber, int secondNumber)
{
  return firstNumber < secondNumber;
}

bool isSubtreeBST(node<int>* root, int parentValue,
                  bool (*equalOrder)(int, int))
{
  if (root == NULL)
  {
    return true;
  }

  return equalOrder(parentValue, root->inf) &&
         isSubtreeBST(root->Left, parentValue, equalOrder) &&
         isSubtreeBST(root->Right, parentValue, equalOrder);
}

bool isBinarySearchTree(node<int>* root)
{
  if (root == NULL)
  {
    return true;
  }

  return isSubtreeBST(root->Left, root->inf, isGreaterOrEqual) &&
         isSubtreeBST(root->Right, root->inf, isLess) &&
         isBinarySearchTree(root->Left) &&
         isBinarySearchTree(root->Right);
}

// task 2
int getVerticesCount(node<int>* root)
{
  if(root == nullptr)
    return 0;

  return 1 + getVerticesCount(root->Left) + getVerticesCount(root->Right);
}

int calculation(const tree<int> &tr1, const tree<char> &tr2)
{
  if(tr1.getRoot() == nullptr)
    return 0;

  int sum = 0;
  switch(tr2.getRoot()->inf)
  {
    case '+': sum += tr1.getRoot()->inf + getVerticesCount(tr1.getRoot()); break;
    case '-': sum += tr1.getRoot()->inf - getVerticesCount(tr1.getRoot()); break;
    case '*': sum += tr1.getRoot()->inf * getVerticesCount(tr1.getRoot()); break;
  }

  return sum + calculation(tr1.LeftTree(), tr2.LeftTree())
             + calculation(tr1.RightTree(), tr2.RightTree());
}

// task 3
vector<int> lettf;
vector<int> righht;

void getVerticesLKD(node<int>* root)
{
  if(root == nullptr)
    return;
  getVerticesLKD(root->Left);
  lettf.push_back(root->inf);
  getVerticesLKD(root->Right);
}

void getVerticesDKL(node<int>* root)
{
  if(root == nullptr)
    return;
  getVerticesDKL(root->Right);
  righht.push_back(root->inf);
  getVerticesDKL(root->Left);
}

bool isSimetric(tree<int> &tr)
{
  getVerticesDKL(tr.RightTree().getRoot());
  getVerticesLKD(tr.LeftTree().getRoot());
  int n = lettf.size();
  for(int i = 0; i < n; i++)
  {
    if(lettf[i] != righht[i])
    {
      return false;
    }
  }
  return true;
}

// Second solution to task 3
bool isTreeSymmetric(node<int>* root1, node<int>* root2)
{
  if (root1 == NULL && root2 == NULL)
  {
    return true;
  }

  if (root1 == NULL || root2 == NULL)
  {
    return false;
  }

  return root1->inf == root2->inf &&
         isTreeSymmetric(root1->Left, root2->Right) &&
         isTreeSymmetric(root1->Right, root2->Left);
}

int main()
{
  tree<int> tr4;
  tr4.Create3(4, tree<int>(), tree<int>());

  tree<int> tr7;
  tr7.Create3(7, tree<int>(), tree<int>());

  tree<int> tr0;
  tr0.Create3(0, tree<int>(), tree<int>());

  tree<int> tr1;
  tr1.Create3(1, tr1, tree<int>());

  tree<int> tr3;
  tr3.Create3(3, tr1, tr4);

  tree<int> tr5;
  tr5.Create3(5, tr3, tr7);


  //tree<char> trop;
  tree<int> trnum;

  //trop.Create();
  trnum.Create();

  // extractVertices(tr5.getRoot()); // This line is from the first solution to task 1.
  //cout << boolalpha << isBinarySearchTree(tr5.getRoot()) << endl;
  //cout << calculation(trnum, trop) << endl;
  // cout << boolalpha << isSimetric(trnum) << endl;
  cout << boolalpha << isTreeSymmetric(trnum.getRoot(), trnum.getRoot()) << endl;

  return 0;
}
