#include <iostream>
#include <fstream>

using namespace std;

bool isWhiteSpaceCharacter(char symbol)
{
  return symbol == ' ' || symbol == '\t' || symbol == '\n';
}

void solve()
{
  ifstream fin;
  fin.open("input.txt");

  int sizeInBytes = 0;
  int newLinesCount = 0;
  int wordsCount = 0;
  char symbol;
  while (fin.get(symbol))
  {
    sizeInBytes++;

    if (symbol == '\n')
    {
      newLinesCount++;
    }

    if (!isWhiteSpaceCharacter(symbol))
    {
      if (fin.peek() == EOF || isWhiteSpaceCharacter(fin.peek()))
      {
        wordsCount++;
      }
    }
  }

  fin.close();

  cout << sizeInBytes << ' ' << wordsCount << ' ' << newLinesCount << endl;
}

int main()
{
  solve();

  return 0;
}
