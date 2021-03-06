#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[1024];
bool used[1024] = { false };

void input()
{
  cin >> n >> m;
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
  used[i] = true;

  for (int j = 0; j < graph[i].size(); j++)
  {
    if (!used[graph[i][j]])
    {
      dfs(graph[i][j]);
    }
  }
}

void solve()
{
  int connectedComponentsCount = 0;
  for (int i = 0; i < n; i++)
  {
    if (!used[i])
    {
      dfs(i);
      connectedComponentsCount++;
    }
  }

  if (connectedComponentsCount == 1)
  {
    cout << "Graph is connected." << endl;
    return;
  }

  cout << "Graph is not connected and has " << connectedComponentsCount << " components." << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
