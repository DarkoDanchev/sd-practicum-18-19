#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

int n;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void initialise() {
  int x1;
  cin >> x1;

  maxHeap.push(x1);
  cout << fixed << setprecision(1) << (double)maxHeap.top() << endl;

  if (n == 1) {
    return;
  }

  int x2;
  cin >> x2;
  if (x2 < maxHeap.top()) {
    maxHeap.push(x2);
    minHeap.push(maxHeap.top());
    maxHeap.pop();
  }
  else {
    minHeap.push(x2);
  }

  cout << fixed << setprecision(1) << (double)(maxHeap.top() + minHeap.top()) / 2 << endl;
}

void printMedian() {
  if (maxHeap.size() - minHeap.size() == 1) {
    cout << fixed << setprecision(1) << (double)maxHeap.top() << endl;
  } else if (minHeap.size() - maxHeap.size() == 1) {
    cout << fixed << setprecision(1) << (double)minHeap.top() << endl;
  } else {
    cout << fixed << setprecision(1) << (double)(maxHeap.top() + minHeap.top()) / 2 << endl;
  }
}

void solve() {
  cin >> n;

  initialise();

  int x;
  for (int i = 2; i < n; i++) {
      cin >> x;
      if (x < maxHeap.top()) {
        maxHeap.push(x);
      } else {
        minHeap.push(x);
      }

      if (maxHeap.size() - minHeap.size() == 2) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      } else if (minHeap.size() - maxHeap.size() == 2) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }

      printMedian();
  }
}

int main() {
  solve();

  return 0;
}
