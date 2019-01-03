#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> graph[16];
bool used[16];
int M, N;
int startVertex, lastVertex;
int minPathWeight = INT_MAX;
int pred[16] = { -1 };
int optimalPath[16] = { -1 };
void construct()
{
  cin >> N >> M;
  cin >> startVertex >> lastVertex;
  int first, second, weight;
  for(int i = 0; i < M; i++)
  {
    cin >> first >> second >> weight;
    graph[first - 1].push_back(make_pair(second - 1, weight));
  }
}

void copyPath()
{
  for(int i = 0; i < 16; i++)
  {
    optimalPath[i] = pred[i];
  }
}

void optimalPathWeight(int currentVertex, int pathWeight)
{
  used[currentVertex] = true;
  if(currentVertex == lastVertex - 1)
  {
    if(minPathWeight > pathWeight)
    {
      minPathWeight = pathWeight;
      copyPath();
    }
    return;
  }

  for(int i = 0; i < graph[currentVertex].size(); i++)
  {
    int successor = graph[currentVertex][i].first;
    int edgeWeight = graph[currentVertex][i].second;
    if(used[successor] == false)
    {
      pred[successor] = currentVertex;
      optimalPathWeight(successor, pathWeight + edgeWeight);
      used[successor] = false;
    }
  }
}

void printPath(int last)
{
  if(optimalPath[last] != -1)
  {
    printPath(optimalPath[last]);
  }

  cout << last + 1 << " ";
}

int main()
{
  construct();
  optimalPathWeight(startVertex - 1, 0);

  cout << minPathWeight << endl;
  printPath(lastVertex - 1);
  cout << endl;

  return 0;
}
/*
5 5
1 5
1 2 30
1 3 2
3 4 3
4 2 7
2 5 2
*/
