#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  char wantedSymbol;
  cin >> wantedSymbol;

  ifstream fin;
  fin.open("file.txt");

  int row = 0;
  int column = 0;
  char symbol;
  while (fin.get(symbol))
  {
    if (symbol == wantedSymbol)
    {
      cout << row << ' ' << column << endl;
    }

    column++;

    if (symbol == '\n')
    {
      row++;
      column = 0;
    }
  }

  fin.close();
}

int main()
{
  solve();

  return 0;
}
