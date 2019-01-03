#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
char word[32];
int wordSize = 0;
vector<int> graph[32];
bool foundWord = false;

void input()
{
  cin >> n >> m;
  cin >> word;
  wordSize = strlen(word);
  for (int i = 0; i < m; i++)
  {
    char firstVertex;
    char secondVertex;
    cin >> firstVertex >> secondVertex;

    graph[firstVertex - 'a'].push_back(secondVertex - 'a');
  }
}

void dfs(int i, int index)
{
  if (index == wordSize)
  {
    foundWord = true;
    return;
  }

  for (int j = 0; j < graph[i].size(); j++)
  {
    if (graph[i][j] == word[index] - 'a')
    {
      dfs(graph[i][j], index + 1);
    }
  }
}

int main()
{

  input();
  dfs(word[0] - 'a', 1);

  cout << boolalpha << foundWord << endl;

  return 0;
}
