#include <iostream>

using namespace std;

int n, arr[100000004];

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
}

int binarySearch(int left, int right, int middle)
{
  while (arr[middle] != middle && left <= right)
  {
    if (middle > arr[middle])
    {
      left = middle + 1;
    }

    else
    {
      right = middle - 1;
    }

    middle = (left + right) / 2;
  }

  if (arr[middle] == middle)
  {
    return middle;
  }

  return -1;
}

int main()
{
  input();
  cout << binarySearch(0, n - 1, (n - 1) / 2) << endl;

  return 0;
}
