#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, startVertex, endVertex;
vector<pair<int, int>> graph[16];
bool used[16] = { false };
int minimalPathCost = INT_MAX;

void input()
{
  cin >> n >> m;
  cin >> startVertex >> endVertex;
  int v1, v2, distance;
  for (int i =0; i < m; i++)
  {
    cin >> v1 >> v2 >> distance;
    graph[v1 - 1].push_back(make_pair(v2 - 1, distance));
  }
}

void allDfs(int i, int currentPathLength)
{
  used[i] = true;

  if (i == endVertex - 1)
  {
    if (minimalPathCost > currentPathLength)
    {
      minimalPathCost = currentPathLength;
    }

    return;
  }

  for (int j = 0; j < graph[i].size(); j++)
  {
    int successor = graph[i][j].first;
    int edgeCost = graph[i][j].second;

    if (!used[successor])
    {
      allDfs(successor, currentPathLength + edgeCost);
      used[successor] = false;
    }
  }
}

void solve()
{
  allDfs(startVertex - 1, 0);

  if (minimalPathCost == INT_MAX)
  {
    cout << "There is no path from vertex " << startVertex << " to vertex " << endVertex << endl;
    return;
  }

  cout << minimalPathCost << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
/*
4 4
1 3
1 2 30
1 4 2
4 2 5
2 3 1
*/
