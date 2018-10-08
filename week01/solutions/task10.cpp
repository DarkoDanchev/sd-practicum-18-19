#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void solve()
{
  ifstream fin("input.txt");

  char name[128];
  int number;

  fin >> name >> number;

  char resultName[128];
  strcpy(resultName, name);
  int biggestNumber = number;

  while (fin >> name >> number)
  {
    if (number > biggestNumber)
    {
      biggestNumber = number;
      strcpy(resultName, name);
    }
  }

  fin.close();

  cout << resultName << endl;
}

int main()
{
  solve();

  return 0;
}
