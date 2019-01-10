#include <iostream>
using namespace std;

const int MAXN = 1000;
int arr[MAXN];
int n;

void input()
{
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
}

int findMatchingElement()
{
  int left = 0;
  int right = n - 1;
  int mid = (n - 1)/2;

  while(left <= right)
  {
    if(arr[mid] == mid)
    {
      return mid;
    } else if(arr[mid] > mid)
    {
      right = mid - 1;
    } else
    {
      left = mid + 1;
    }

    mid = (left + right) / 2;
  }

  return -1;
}

int main()
{
  input();
  cout << findMatchingElement() << endl;


  return 0;
}
