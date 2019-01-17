#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int n;
priority_queue<int> firstHalf;
priority_queue<int, vector<int>, greater<int>> secondHalf;

void printMedian(const priority_queue<int> &firstHalf, const priority_queue<int, vector<int>, greater<int>> &secondHalf)
{
  if (firstHalf.size() > secondHalf.size())
  {
    cout << fixed << setprecision(1) << (double)(firstHalf.top()) << endl;
  }

  else if (firstHalf.size() == secondHalf.size())
  {
    cout << fixed << setprecision(1) << ((double)(firstHalf.top()) + secondHalf.top()) / 2 << endl;
  }

  else
  {
    cout << fixed << setprecision(1) << (double)(secondHalf.top()) << endl;
  }
}

void enterAndProcessFirstTwoElements()
{
  int element;
  cin >> element;

  firstHalf.push(element);

  cout << fixed << setprecision(1) << (double)(element) << endl;

  if (n == 1)
  {
    return;
  }

  cin >> element;

  if (firstHalf.top() >= element)
  {
    firstHalf.push(element);

    int firstHalfTop = firstHalf.top();
    firstHalf.pop();

    secondHalf.push(firstHalfTop);
  }

  else
  {
    secondHalf.push(element);
  }

  printMedian(firstHalf, secondHalf);
}

void solve()
{
  cin >> n;

  enterAndProcessFirstTwoElements();

  int element;
  for (int i = 2; i < n; i++)
  {
    cin >> element;

    if (firstHalf.top() >= element)
    {
      firstHalf.push(element);
    }

    else
    {
      secondHalf.push(element);
    }

    if (firstHalf.size() - secondHalf.size() == 2)
    {
      int firstHalfTop = firstHalf.top();
      firstHalf.pop();

      secondHalf.push(firstHalfTop);
    }

    else if (secondHalf.size() - firstHalf.size() == 2)
    {
      int secondHalfTop = secondHalf.top();
      secondHalf.pop();

      firstHalf.push(secondHalfTop);
    }

    printMedian(firstHalf, secondHalf);
  }
}

int main()
{
  solve();

  return 0;
}
