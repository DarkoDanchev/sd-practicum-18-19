#include <iostream>
#include <vector>
#include <queue>

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

void bfs(int i)
{
  queue<int> q;
  q.push(i);

  used[i] = true;

  while(!q.empty())
  {
    int curr = q.front();
    q.pop();

    for(int j = 0; j < graph[curr].size(); j++)
    {
      if(!used[graph[curr][j]])
      {
        pred[graph[curr][j]] = curr;
        if(graph[curr][j] == endVertex - 1)
        {
          foundPath = true;
          return;
        }
        used[graph[curr][j]] = true;
        q.push(graph[curr][j]);
      }
    }
  }
}

void printPath(int vertex)
{
  if(pred[vertex] != -1)
  {
    printPath(pred[vertex]);
  }
  cout << vertex + 1 << " ";
}

int main()
{
  input();
  bfs(startVertex - 1);
  printPath(endVertex - 1);

  return 0;
}
/*
5 5
1 5
1 2
2 3
2 4
4 5
2 5
*/
