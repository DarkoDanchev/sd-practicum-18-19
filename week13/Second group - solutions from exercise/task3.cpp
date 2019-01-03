#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1000];
bool used[1000] = { false };
int M, N;
int vertex;

void construct()
{
  cin >> N >> M;

  cin >> vertex;

  int first, second;
  for(int i = 0; i < M; i++)
  {
    cin >> first >> second;
    graph[first - 1].push_back(second - 1);
  }
}

void dfs(int current)
{
  used[current] = true;

  for(int i = 0; i < graph[current].size(); i++)
  {
    if(used[graph[current][i]] == false)
    {
      dfs(graph[current][i]);
    }
  }
}

void printUnreachableFrom(int vertex)
{
  dfs(vertex - 1);
  cout << "Unreachable nodes from " << vertex << ": ";
  for(int i = 0; i < N; i++)
  {
    if(used[i] == false)
    {
      cout << i + 1 << " ";
    }
  }
}

int main()
{
  construct();
  printUnreachableFrom(vertex);
  return 0;
}
/**
5 5
2
1 2
1 3
3 4
4 2
2 5
*/
/**
5 5
1
1 2
1 3
3 4
4 2
2 5
*/
