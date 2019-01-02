#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int startVertex, endVertex;
vector<int> graph[1024];
int pred[1024] = { -1 };
bool used[1024] = { false };
bool foundPath = false;

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

void bfs(int i)
{
  queue<int> q;
  q.push(i);
  used[i] = true;

  while (!q.empty())
  {
    int topVertex = q.front();
    q.pop();

    for (int j = 0; j < graph[topVertex].size(); j++)
    {
      if (!used[graph[topVertex][j]])
      {
        used[graph[topVertex][j]] = true;
        q.push(graph[topVertex][j]);
        pred[graph[topVertex][j]] = topVertex;

        if (graph[topVertex][j] == endVertex - 1)
        {
          foundPath = true;
          return;
        }
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
  bfs(startVertex - 1);

  if (!foundPath)
  {
    cout << "There is no path between vertex " << startVertex << " and vertex " << endVertex << endl;

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
4 3
1 3
1 2
2 4
3 4

4 5
1 4
1 2
1 4
1 3
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

7 8
1 6
1 2
1 4
2 4
4 5
2 3
3 6
5 7
7 6
*/
