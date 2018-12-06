#include <iostream>
#include <vector>
#include "tree_templ.cpp"

using namespace std;

int k;
vector<int> vertices;

void extractVerticesFromLevelK(node<int>* root, int level)
{
  if (root == NULL)
  {
    return;
  }

  if (level == k)
  {
    vertices.push_back(root->inf);
    return;
  }

  extractVerticesFromLevelK(root->Left, level + 1);
  extractVerticesFromLevelK(root->Right, level + 1);
}

bool isPalindrome()
{
  for (int i = 0; i < vertices.size() / 2; i++)
  {
    if (vertices[i] != vertices[vertices.size() - i - 1])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  cin >> k;

  tree<int> tr;
  tr.Create();

  extractVerticesFromLevelK(tr.getRoot(), 0);
  cout << boolalpha << isPalindrome() << endl;

  return 0;
}
