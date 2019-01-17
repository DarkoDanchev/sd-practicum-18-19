#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;


priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;
int N;
void firstTwoElements(){
  int n1,n2;
  cin >> n1;

  maxHeap.push(n1);
  cout << fixed << setprecision(1) << (double)n1 << " ";
  if(N==1)
    return;

  cin >> n2;
  if(n2>maxHeap.top()){
    minHeap.push(n2);
  }else{
    maxHeap.push(n2);
    int temp = maxHeap.top();
    maxHeap.pop();
    minHeap.push(temp);
  }
  cout << fixed << setprecision(1) << ((double)minHeap.top() + maxHeap.top())/2 << " ";

}
void printMedian(){
  if(maxHeap.size()>minHeap.size()){
    cout << fixed << setprecision(1) << (double)maxHeap.top() << " ";
  }else if(minHeap.size()>maxHeap.size()){
    cout << fixed << setprecision(1) << (double)minHeap.top() << " ";
  }else{
    cout << fixed << setprecision(1) << ((double)maxHeap.top()+minHeap.top())/2 << " ";
  }
}
void solve(){
  cin >> N;
  firstTwoElements();
  for(int i=2;i<N;i++){
      int current;
      cin >> current;
      if(current>maxHeap.top()){
        minHeap.push(current);
      }else{
        maxHeap.push(current);
      }
      if(minHeap.size() - maxHeap.size()==2){
        int tmp = minHeap.top();
        minHeap.pop();
        maxHeap.push(tmp);
      }else if(maxHeap.size() - minHeap.size() == 2){
        int tmp = maxHeap.top();
        maxHeap.pop();
        minHeap.push(tmp);
      }
      printMedian();
  }
}

int main(){
  solve();
  return 0;
}
