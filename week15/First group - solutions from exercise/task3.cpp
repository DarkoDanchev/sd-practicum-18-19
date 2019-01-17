#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;

void printResults()
{
    if(maxHeap.size() < 3)
    {
      cout << -1 << endl;
    }
    else
    {
      int first;
      first = maxHeap.top();
      maxHeap.pop();
      int second;
      second = maxHeap.top();
      maxHeap.pop();
      int third;
      third = maxHeap.top();
      maxHeap.pop();
      cout << first * second * third << endl;
      maxHeap.push(first);
      maxHeap.push(second);
      maxHeap.push(third);
    }

}

void solve()
{
  int n;
  cin >> n;
  for( int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    maxHeap.push(x);
    printResults();
  }
}

int main()
{
  solve();
  return 0;
}
