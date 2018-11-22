#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> deq;
int discardedCards[64];
int discardedCardsSize = 0;

void printAnswer()
{
  cout << "Discarded cards: ";
  if (discardedCardsSize > 0)
  {
    for (int i = 0; i < discardedCardsSize - 1; i++)
    {
      cout << discardedCards[i] << ", ";
    }

    cout << discardedCards[discardedCardsSize - 1] << endl;
  }

  else
  {
    cout << endl;
  }

  cout << "Remaining card: " << deq.front() << endl;
}

void solve()
{

  for (int i = 0; i < n; i++)
  {
    deq.push_front(i + 1);
  }

  while (deq.size() > 1)
  {
    discardedCards[discardedCardsSize++] = deq.back();
    deq.pop_back();

    deq.push_front(deq.back());
    deq.pop_back();
  }

  printAnswer();
}

int main()
{
  cin >> n;
  solve();

  return 0;
}
