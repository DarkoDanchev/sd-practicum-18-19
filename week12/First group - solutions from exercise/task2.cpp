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
    if (!used[graph[i][j]])
      dfs(graph[i][j]);
}

bool checkComponents()
{
  int components = 0;
  for (int i = 0; i < n; i++)
  {
    if (!used[i])
    {
      dfs(i);
      components++;
    }
  }

  if (components == 1)
    cout << "Connected graph" << endl;
  else
    cout << components << " connected components" << endl;
}

int main()
{
  input();
  checkComponents();

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
