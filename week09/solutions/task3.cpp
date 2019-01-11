#include <iostream>
#include <string.h>
#include "tree_templ.cpp"

using namespace std;

template<typename T>
bool isLeaf(node<T>* vertex)
{
  return !vertex->Left && !vertex->Right;
}

int convertToInteger(char* str)
{
  int number = 0;
  int length = strlen(str);
  for (int i = 0; i < length; i++)
  {
    number = number * 10 + (str[i] - '0');
  }

  return number;
}

int evaluateTree(node<char*>* root)
{
  if (isLeaf(root))
  {
    return convertToInteger(root->inf);
  }

  if (strcmp(root->inf, "+") == 0)
  {
    return evaluateTree(root->Left) + evaluateTree(root->Right);
  }

  if (strcmp(root->inf, "-") == 0)
  {
    return evaluateTree(root->Left) - evaluateTree(root->Right);
  }

  if (strcmp(root->inf, "*") == 0)
  {
    return evaluateTree(root->Left) * evaluateTree(root->Right);
  }
}

int main()
{
  tree<char*> t1;
  t1.Create3("1", tree<char*>(), tree<char*>());

  tree<char*> t31;
  t31.Create3("3", tree<char*>(), tree<char*>());

  tree<char*> t32;
  t32.Create3("3", tree<char*>(), tree<char*>());

  tree<char*> t7;
  t7.Create3("7", tree<char*>(), tree<char*>());

  tree<char*> t9;
  t9.Create3("9", tree<char*>(), tree<char*>());

  tree<char*> t4;
  t4.Create3("+", t7, t9);

  tree<char*> t3;
  t3.Create3("*", t32, t4);

  tree<char*> t2;
  t2.Create3("-", t1, t31);

  tree<char*> wholeTree;
  wholeTree.Create3("+", t2, t3);

  cout << evaluateTree(wholeTree.getRoot()) << endl;

  return 0;
}
