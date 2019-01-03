#include <iostream>
#include <vector>

using namespace std;

int n, m, vertex;
vector<int> graph[1024];
bool used[1024] = { false };

void input()
{
  cin >> n >> m >> vertex;
  for (int j = 0; j < m; j++)
  {
    int firstVertex;
    int secondVertex;
    cin >> firstVertex >> secondVertex;

    graph[firstVertex - 1].push_back(secondVertex - 1);
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
  dfs(vertex - 1);

  cout << "Unreachable vertices from vertex " << vertex << ": ";
  for (int i = 0; i < n; i++)
  {
    if (!used[i])
    {
      cout << i + 1 << ' ';
    }
  }

  cout << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
