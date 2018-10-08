#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  ifstream fin;
  fin.open("file.txt");

  int sizeInBytes = 0;
  char symbol;
  while (fin.get(symbol))
  {
    sizeInBytes++;
  }

  fin.close();

  cout << sizeInBytes << endl;
}

int main()
{
  solve();

  return 0;
}
