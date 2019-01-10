#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1024;
const int MAX_M = 100004;
int boatWidth;
int n, m;

vector<pair<int, int>> graph[MAX_N];
bool used[MAX_N] = { false };

void input()
{
  cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    int first,second, weight;
    cin >> first >> second >> weight;
    graph[first - 1].push_back(make_pair(second - 1, weight));
    graph[second - 1].push_back(make_pair(first - 1, weight));
  }
  cin >> boatWidth;
}

void traverseGraph(int start)
{
  queue<int> q;
  q.push(start);
  int current = 0;
  used[start] = true;

  while(!q.empty())
  {
    current = q.front();
    q.pop();

    for(int i = 0; i < graph[current].size(); i++)
    {
      int succ = graph[current][i].first;
      int weight = graph[current][i].second;
      if(used[succ] == false && weight >= boatWidth)
      {
        q.push(succ);
        used[succ] = true;
      }
    }
  }
}

void solve()
{
  int componentsCount = 0;

  for(int i = 0; i < n; i++)
  {
    if(used[i] == false)
    {
        traverseGraph(i);
        componentsCount++;
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
