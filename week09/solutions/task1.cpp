#include <iostream>
#include "tree_templ.cpp"

using namespace std;

template<typename T>
bool containsElement(node<T>* root, T element)
{
  if (root == NULL)
  {
    return false;
  }

  return root->inf == element || containsElement(root->Left, element) || containsElement(root->Right, element);
}

int main()
{
  tree<int> t6;
  t6.Create3(6, tree<int>(), tree<int>());

  tree<int> t4;
  t4.Create3(4, tree<int>(), tree<int>());

  tree<int> t5;
  t5.Create3(5, tree<int>(), tree<int>());

  tree<int> t3;
  t3.Create3(3, t6, t4);

  tree<int> t2;
  t2.Create3(2, tree<int>(), t5);

  tree<int> t1;
  t1.Create3(1, t3, t2);

  cout << boolalpha << containsElement(t1.getRoot(), 6) << endl;

  return 0;
}
