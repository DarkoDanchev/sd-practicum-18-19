#include <iostream>
#include <vector>
using namespace std;

int n, m, vertex;
const int MAXN = 1024;
vector<int> graph[MAXN];
bool used[MAXN];
void dfs(int i)
{
  used[i] = true;
  for (int j = 0; j < graph[i].size(); j++)
    if (!used[graph[i][j]])
      dfs(graph[i][j]);
}

void input()
{
  cin >> n >> m >> vertex;
  int firstVertex, secondVertex;
  for (int i = 0; i < m; i++)
  {
    cin >> firstVertex >> secondVertex;
    graph[firstVertex - 1].push_back(secondVertex - 1);
  }
}

void solve()
{
  dfs(vertex - 1);

  for (int i = 0; i < n; i++)
    if (!used[i])
      cout << i + 1 << ' ';

  cout << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
