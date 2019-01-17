#include<iostream>
#include <queue>
using namespace std;

int n;

void solve() {
  priority_queue<int> maxHeap;
  cin >> n;
  int num;
  int i;
  for (i = 0; i < n / 2 + 1; i++) {
    cin >> num;
    maxHeap.push(num);
  }
  for (; i < n; i++) {
    cin >> num;
    maxHeap.push(num);
    maxHeap.pop();
  }
  if (n % 2 == 0) {
    int n1, n2;
    n1 = maxHeap.top();
    maxHeap.pop();
    n2 = maxHeap.top();
    cout << (double)(n1 + n2) / 2 << endl;
    return;
  }
  cout << maxHeap.top() << endl;
}

int main(){
  solve();
  return 0;
}
