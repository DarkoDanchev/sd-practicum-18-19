#include <iostream>
#include "LList.cpp"

using namespace std;

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
