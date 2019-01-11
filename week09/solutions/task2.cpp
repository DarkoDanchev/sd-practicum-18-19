#include <iostream>
#include <string.h>
#include "tree_templ.cpp"

using namespace std;

bool isLeaf(node<char>* vertex)
{
  return !vertex->Left && !vertex->Right;
}

bool subtreeContainsWord(node<char>* root, char* word, int index)
{
  if (root == NULL)
  {
    if (index == strlen(word))
    {
      return true;
    }

    return false;
  }

  if (index == strlen(word))
  {
    return false;
  }

  if (index == strlen(word) - 1)
  {
    if (root->inf == word[index])
    {
      return isLeaf(root);
    }
  }

  return root->inf == word[index] && (subtreeContainsWord(root->Left, word, index + 1) || subtreeContainsWord(root->Right, word, index + 1));
}

bool treeContainsWord(node<char>* root, char* word, int index)
{
  if (root == NULL)
  {
    return false;
  }

  return subtreeContainsWord(root, word, index) || treeContainsWord(root->Left, word, index) || treeContainsWord(root->Right, word, index);
}

int main()
{
  tree<char> t6;
  t6.Create3('f', tree<char>(), tree<char>());

  tree<char> t4;
  t4.Create3('d', tree<char>(), tree<char>());

  tree<char> t5;
  t5.Create3('e', tree<char>(), tree<char>());

  tree<char> t3;
  t3.Create3('c', t6, t4);

  tree<char> t2;
  t2.Create3('b', tree<char>(), t5);

  tree<char> t1;
  t1.Create3('a', t3, t2);

   cout << boolalpha << treeContainsWord(t1.getRoot(), "acd", 0) << endl; // subtreeContainsWord(t1.getRoot(), "acd:") << endl;

  return 0;
}
