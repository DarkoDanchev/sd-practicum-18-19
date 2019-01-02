#include <iostream>
#include <vector>

using namespace std;

int n, m;
int startVertex, endVertex;
vector<int> graph[1024];
bool used[1024] = { false };
bool foundPath = false;
int pred[1024] = { -1 };

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

void solve()
{
  dfs(startVertex - 1);

  if (!foundPath)
  {
    cout << "There is no path from vertex " << startVertex << " to vertex " << endVertex << endl;
    return;
  }

  cout << "Found path from vertex " << startVertex << " to vertex " << endVertex << ": ";
  printPath(endVertex - 1);
  cout << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
/*
5 4
1 5
1 2
2 3
2 4
4 5

6 4
1 6
1 2
2 3
2 4
4 5
*/
