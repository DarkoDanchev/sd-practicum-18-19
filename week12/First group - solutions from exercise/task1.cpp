#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m;
int startVertex, endVertex;
vector<int> graph[1024];
bool foundPath = false;
bool used[1024] = { false };
int pred[1024];

void input()
{
  cin >> n >> m;
  cin >> startVertex >> endVertex;
  for (int i = 0; i < m; i++)
  {
    int firstVertex, secondVertex;
    cin >> firstVertex >> secondVertex;
    graph[firstVertex - 1].push_back(secondVertex - 1);
    graph[secondVertex - 1].push_back(firstVertex - 1);
  }
}

void dfs(int i)
{
  if (i == endVertex - 1)
  {
    foundPath = true;
    return;
  }

  used[i] = true;

  for (int j = 0; j < graph[i].size(); j++)
  {
    if (!used[graph[i][j]])
    {
      pred[graph[i][j]] = i;
      dfs(graph[i][j]);
      if (foundPath)
      {
        return;
      }
    }
  }
}

void printPath(int vertex)
{
  if (pred[vertex] != -1)
  {
    printPath(pred[vertex]);
  }

  cout << vertex + 1 << ' ';
}

int main()
{
  input();
  memset(pred, -1, sizeof(pred));
  dfs(startVertex - 1);
  printPath(endVertex - 1);


  cout << boolalpha << foundPath << endl;

  return 0;
}
/*
4 3
1 3
1 2
2 4
3 4

6 6
1 5
1 2
1 4
1 3
2 4
3 4
5 6
*/
