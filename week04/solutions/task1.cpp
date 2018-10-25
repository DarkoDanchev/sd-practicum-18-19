#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int n;
char brackets[1024];

void input()
{
  cin >> brackets;
  n = strlen(brackets);
}

bool isClosingBracket(char bracket)
{
  return bracket == ')' || bracket == ']' || bracket == '}' || bracket == '>';
}

bool areBracketsOfSameType(char openingBracket, char closingBracket)
{
  return (openingBracket == '(' && closingBracket == ')') ||
         (openingBracket == '[' && closingBracket == ']') ||
         (openingBracket == '{' && closingBracket == '}') ||
         (openingBracket == '<' && closingBracket == '>');
}

bool areBracketsCorrect()
{
  stack<char> openingBrackets;

  for (int i = 0; i < n; i++)
  {
    if (isClosingBracket(brackets[i]))
    {
      if (openingBrackets.empty())
      {
        return false;
      }

      if (areBracketsOfSameType(openingBrackets.top(), brackets[i]))
      {
        openingBrackets.pop();
      }

      else
      {
        return false;
      }
    }

    else
    {
      openingBrackets.push(brackets[i]);
    }
  }

  return openingBrackets.empty();
}

int main()
{
  input();
  cout << boolalpha << areBracketsCorrect() << endl;

  return 0;
}
