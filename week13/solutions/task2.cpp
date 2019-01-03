#include <iostream>
#include <vector>

using namespace std;

const int MAXIMAL_PATH_COST = 1000000001;

int n, m, startVertex, endVertex;
vector<pair<int, int>> graph[1024];
int minimalPathCost = MAXIMAL_PATH_COST;
bool used[1024] = { false };

void input()
{
  cin >> n >> m;
  cin >> startVertex >> endVertex;
  for (int i = 0; i < m; i++)
  {
    int firstVertex;
    int secondVertex;
    int distance;
    cin >> firstVertex >> secondVertex >> distance;

    graph[firstVertex - 1].push_back(make_pair(secondVertex - 1, distance));
  }
}

void allDfs(int i, int pathCost)
{
  used[i] = true;

  if (i == endVertex - 1)
  {
    if (minimalPathCost > pathCost)
    {
      minimalPathCost = pathCost;
    }

    return;
  }

  for (int j = 0; j < graph[i].size(); j++)
  {
    int successor = graph[i][j].first;
    int edgeCost = graph[i][j].second;

    if (!used[successor])
    {
      allDfs(successor, pathCost + edgeCost);
      used[successor] = false;
    }
  }
}

void solve()
{
  allDfs(startVertex - 1, 0);

  if (minimalPathCost == MAXIMAL_PATH_COST)
  {
    cout << "There is not path from vertex " << startVertex << " to vertex " << endVertex << endl;
    return;
  }

  cout << "Minimal path cost from vertex " << startVertex << " to vertex " << endVertex << " is " << minimalPathCost << endl;
}

int main()
{

  input();
  solve();

  return 0;
}
