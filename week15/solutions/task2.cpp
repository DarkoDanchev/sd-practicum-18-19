#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> firstHalf;

void solve()
{
  cin >> n;

  int element;
  int i;
  for (i = 0; i < n / 2 + 1; i++)
  {
    cin >> element;
    firstHalf.push(element);
  }

  for (; i < n; i++)
  {
    cin >> element;

    firstHalf.push(element);
    firstHalf.pop();
  }

  if ((n & 1) == 0)
  {
    int topElement = firstHalf.top();
    firstHalf.pop();
    cout << ((double)(topElement) + firstHalf.top()) / 2 << endl;
    return;
  }

  cout << firstHalf.top() << endl;
}

int main()
{
  solve();

  return 0;
}
