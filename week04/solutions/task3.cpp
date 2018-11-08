#include <iostream>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

int firstNumberLength, secondNumberLength;
char firstNumber[131072], secondNumber[131072];
stack<char> result;

void swapIfNeeded()
{
  if (secondNumberLength > firstNumberLength)
  {
    char temporary[131072] = { '\0' };
    strcpy(temporary, firstNumber);
    strcpy(firstNumber, secondNumber);
    strcpy(secondNumber, temporary);
    swap(firstNumberLength, secondNumberLength);
  }
}

void input()
{
  cin >> firstNumber;
  firstNumberLength = strlen(firstNumber);
  reverse(firstNumber, firstNumber + firstNumberLength);

  cin >> secondNumber;
  secondNumberLength = strlen(secondNumber);
  reverse(secondNumber, secondNumber + secondNumberLength);

  swapIfNeeded();
}

void solve()
{
  int index = 0;
  int additional = 0;
  for (int i = 0; i < firstNumberLength; i++)
  {
    int currentSum;
    if (index < secondNumberLength)
    {
      currentSum = (firstNumber[i] - '0') + (secondNumber[index++] - '0') + additional;
    }

    else
    {
      currentSum = (firstNumber[i] - '0') + additional;
    }

    if (currentSum > 9)
    {
      additional = 1;
      currentSum %= 10;
    }

    else
    {
      additional = 0;
    }

    result.push(currentSum + '0');
  }

  if (additional == 1)
  {
    result.push('1');
  }

  while (!result.empty())
  {
    cout << result.top();
    result.pop();
  }

  cout << endl;
}

int main()
{
  input();
  solve();

  return 0;
}
