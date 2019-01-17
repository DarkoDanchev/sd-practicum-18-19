#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100004];
priority_queue<int> pq;

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
}

void printProduct()
{
  if (pq.size() < 3)
  {
    cout << -1 << endl;
    return;
  }

  int first, second, third;
  first = pq.top();
  pq.pop();

  second = pq.top();
  pq.pop();

  third = pq.top();
  pq.pop();

  cout << first * second * third << endl;

  pq.push(first);
  pq.push(second);
  pq.push(third);
}

void solve()
{
  for (int i = 0; i < n; i++)
  {
    pq.push(arr[i]);
    printProduct();
  }
}

int main()
{
  input();
  solve();

  return 0;
}
