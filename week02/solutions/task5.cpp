#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

char word[1024];

void censure(fstream &file, int wordLength)
{
  file.seekp(file.tellp() - wordLength);
  for (int i = 0; i < wordLength; i++)
  {
    file << '*';
  }
}

void solve()
{
  fstream file;
  file.open("file.txt");

  int index = 0;
  int wordLength = strlen(word);
  char symbol;
  while (file.get(symbol))
  {
    if (symbol == word[index])
    {
      index++;
      if (index == wordLength)
      {
        censure(file, wordLength);
        index = 0;
      }
    }

    else
    {
      if (index > 0)
      {
        index = 0;
        file.putback(symbol);
      }
    }
  }
}

int main()
{
  cin >> word;
  solve();

  return 0;
}
