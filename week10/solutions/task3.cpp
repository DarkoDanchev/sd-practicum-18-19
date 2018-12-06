#include <iostream>
#include "tree_templ.cpp"

using namespace std;

template<typename T>
bool isTreeMirroredAndSymmetrical(node<T>* root1, node<T>* root2)
{
  if (root1 == NULL && root2 == NULL)
  {
    return true;
  }

  if (root1 == NULL || root2 == NULL)
  {
    return false;
  }

  return root1->inf == root2->inf && isTreeMirroredAndSymmetrical(root1->Left, root2->Right) && isTreeMirroredAndSymmetrical(root1->Right, root2->Left);
}

int main()
{
  tree<int> tr;
  tr.Create();

  cout << boolalpha << isTreeMirroredAndSymmetrical(tr.getRoot(), tr.getRoot()) << endl;

  return 0;
}
