#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

char word[128];
string content = "";

void input()
{
  cin >> word;
  int wordLength = strlen(word);

  ifstream fin;
  fin.open("file.txt");

  char symbol;
  while (fin.get(symbol))
  {
    content += symbol;
  }

  fin.close();
}

void censure(string &content, int i, int wordLength)
{
  while (wordLength > 0)
  {
    content[i] = '*';
    i--;
    wordLength--;
  }
}

void writeContentToFile()
{
  ofstream fout;
  fout.open("file.txt");
  fout << content << endl;
  fout.close();
}

void solve()
{
  int wordLength = strlen(word);
  int index = 0;
  int contentLength = content.length();
  for (int i = 0; i < contentLength; i++)
  {
    if (content[i] == word[index])
    {
      index++;

      if (index == wordLength)
      {
        censure(content, i, wordLength);
        index = 0;
      }
    }

    else
    {
      if (index > 0)
      {
        index = 0;
        i--;
      }
    }
  }

  writeContentToFile();
}

int main()
{
  input();
  solve();

  return 0;
}
