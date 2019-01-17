#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;

void solve() {
  int n;
  cin >> n;

  int i = 0;
  int x;
  for ( ; i < n/2 + 1; i++) {
      cin >> x;
      maxHeap.push(x);
  }

  for ( ; i < n; i++) {
      cin >> x;
      maxHeap.push(x);
      maxHeap.pop();
  }

  if (n % 2 != 0) {
    cout << fixed << setprecision(1) <<  (double)maxHeap.top() << endl;
  } else {
    int x = maxHeap.top();
    maxHeap.pop();
    cout << fixed << setprecision(1) <<  (double)(maxHeap.top() + x) / 2 << endl;
  }
}

int main() {
  solve();

  return 0;
}
