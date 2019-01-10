#include <iostream>
#include <vector>

using namespace std;

int n, m, boatWidth;
vector<pair<int, int>> graph[1004];
bool used[1004] = { false };

void input()
{
  cin >> n >> m;

  int v1, v2, canalWidth;
  for (int i = 0; i < m; i++)
  {
    cin >> v1 >> v2 >> canalWidth;
    graph[v1 - 1].push_back(make_pair(v2 - 1, canalWidth));
    graph[v2 - 1].push_back(make_pair(v1 - 1, canalWidth));
  }

  cin >> boatWidth;
}

void dfs(int i)
{
  used[i] = true;

  for (int j = 0; j < graph[i].size(); j++)
  {
    int successor = graph[i][j].first;
    int canalWidth = graph[i][j].second;

    if (!used[successor] && boatWidth <= canalWidth)
    {
      dfs(successor);
    }
  }
}

void solve()
{
  int componentsCount = 0;
  for (int i = 0; i < n; i++)
  {
    if (!used[i])
    {
      componentsCount++;
      dfs(i);
    }
  }

  cout << componentsCount - 1 << endl;
}

int main()
{

  input();
  solve();

  return 0;
}
