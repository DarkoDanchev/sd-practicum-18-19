#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
int v1, v2;
vector<int> graph[1024];
bool used[1024] = { false };
bool commonVertexBelongs = false;
bool stopSearching = false;

void input()
{
  cin >> n >> m;
  cin >> v1 >> v2;

  int firstVertex, secondVertex;
  for (int i = 0; i < m; i++)
  {
    cin >> firstVertex >> secondVertex;
    graph[firstVertex - 1].push_back(secondVertex - 1);
  }
}

void dfs(int i, int commonVertex)
{
  used[i] = true;

  if (i == v2 - 1)
  {
    if (!commonVertexBelongs)
    {
      stopSearching = true;
    }

    return;
  }

  for (int j = 0; j < graph[i].size(); j++)
  {
    if (!used[graph[i][j]])
    {
      if (graph[i][j] == commonVertex)
      {
        commonVertexBelongs = true;
      }

      dfs(graph[i][j], commonVertex);

      if (stopSearching)
      {
        return;
      }

      if (graph[i][j] == commonVertex)
      {
        commonVertexBelongs = false;
      }

      used[graph[i][j]] = false;
    }
  }
}

void solve()
{
  for (int i = 0; i < n; i++)
  {
    if (i != v1 - 1 && i != v2 - 1)
    {
      dfs(v1 - 1, i);
      if (!stopSearching)
      {
        cout << "Vertex " << i + 1 << " belongs to every path from vertex " << v1 << " to vertex " << v2 << endl;
        return;
      }

      stopSearching = false;
      memset(used, false, sizeof(used));
    }
  }

  cout << "There is no vertex that belongs to every path from vertex " << v1 << " to vertex " << v2 << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
