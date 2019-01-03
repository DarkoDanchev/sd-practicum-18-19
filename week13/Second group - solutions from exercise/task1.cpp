#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<char> graph[256];
char word[1000];

void construct()
{
  cin >> N >> M;

  char first, second;
  for(int i = 0; i < M; i++)
  {
    cin >> first >> second;
    graph[first].push_back(second);
  }
  cin >> word;
}

bool searchWord(int index)
{
  if(word[index + 1] == '\0')
  {
    return true;
  }

  for(int i = 0; i < graph[word[index]].size(); i++)
  {
    if(graph[word[index]][i] == word[index + 1])
    {
      return searchWord(index + 1);
    }
  }

  return false;
}

int main()
{
  construct();
  cout << boolalpha << searchWord(0) << endl;

  return 0;
}
