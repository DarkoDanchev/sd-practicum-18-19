#include <iostream>
#include "LList.cpp"

using namespace std;

void input(int &n, int &x, LList<int> &l)
{
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    int number;
    cin >> number;
    l.toEnd(number);
  }
}

bool containsElement(LList<int> &l, int x)
{
  l.iterStart();
  elem_link1<int>* it = l.iter();

  while (it)
  {
    if (it->inf == x)
    {
      return true;
    }

    it = it->link;
  }

  return false;
}

bool containsDifferentElements(LList<int> &l)
{
  l.iterStart();
  elem_link1<int>* searchedElement = l.iter();
  elem_link1<int>* it;

  while (searchedElement)
  {
    it = searchedElement->link;
    while (it)
    {
      if (it->inf == searchedElement->inf)
      {
        return false;
      }

      it = it->link;
    }

    searchedElement = l.iter();
  }

  return true;
}

void reverseList(LList<int> &l)
{
  int n = l.length();
  if (n < 2)
  {
    return;
  }

  if (n == 2)
  {
    l.Start->link = NULL;
    l.End->link = l.Start;
    swap(l.Start, l.End);

    return;
  }

  elem_link1<int>* previous = l.Start;
  elem_link1<int>* current = previous->link;
  elem_link1<int>* next = current->link;

  previous->link = NULL;

  while (next)
  {
    current->link = previous;
    previous = current;
    current = next;
    next = next->link;
  }

  current->link = previous;

  swap(l.Start, l.End);
}

bool isLess(int firstELement, int secondElement)
{
  return firstELement < secondElement;
}

bool isGreater(int firstElement, int secondElement)
{
  return firstElement > secondElement;
}

bool equalOrder(bool (*comparator)(int, int), LList<int> &l)
{
  l.iterStart();
  elem_link1<int>* it = l.iter();

  while (it->link)
  {
    if (comparator(it->inf, it->link->inf))
    {
      return false;
    }

    it = l.iter();
  }

  return true;
}

bool increasingOrDecreasingOrder(LList<int> &l)
{
  return l.length() == 0 || equalOrder(isGreater, l) || equalOrder(isLess, l);
}

void sortElements(LList<int> &l, bool (*comparator)(int, int))
{
  l.iterStart();
  elem_link1<int>* it = l.iter();

  while (it)
  {
    elem_link1<int>* it1 = it->link;
    elem_link1<int>* smallestElement = it;
    while (it1)
    {
      if (comparator(smallestElement->inf, it1->inf))
      {
        swap(smallestElement->inf, it1->inf);
      }

      it1 = it1->link;
    }

    it = l.iter();
  }
}

bool isMember(int element, LList<int> l)
{
  l.iterStart();
  elem_link1<int>* it = l.iter();

  while (it)
  {
    if (it->inf == element)
    {
      return true;
    }

    it = it->link;
  }

  return false;
}

LList<int> findIntersection(LList<int> &firstList, LList<int> &secondList)
{
  LList<int> result;

  firstList.iterStart();
  elem_link1<int>* it = firstList.iter();

  while (it)
  {
    if (isMember(it->inf, secondList))
    {
      result.toEnd(it->inf);
    }

    it = it->link;
  }

  return result;
}

LList<int> findDifference(LList<int> &firstList, LList<int> &secondList)
{
  LList<int> result;

  firstList.iterStart();
  elem_link1<int>* it = firstList.iter();

  while (it)
  {
    if (!isMember(it->inf, secondList))
    {
      result.toEnd(it->inf);
    }

    it = it->link;
  }

  return result;
}

LList<int> findUnion(LList<int> &firstList, LList<int> &secondList)
{
  LList<int> result;

  firstList.iterStart();
  elem_link1<int>* it = firstList.iter();

  while (it)
  {
    if (!isMember(it->inf, result))
    {
      result.toEnd(it->inf);
    }

    it = it->link;
  }

  secondList.iterStart();
  it = secondList.iter();

  while (it)
  {
    if (!isMember(it->inf, result))
    {
      result.toEnd(it->inf);
    }

    it = it->link;
  }

  return result;
}

int main()
{
  return 0;
}
