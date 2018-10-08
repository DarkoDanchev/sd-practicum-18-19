#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  ifstream fin("input.txt");

  int result = 0;
  char symbol;
  while (fin.get(symbol))
  {
    if (symbol >= '0' && symbol <= '9')
    {
      result = result * 10 + (symbol - '0');
    }
  }

  fin.close();

  cout << result << endl;
}

int main()
{
  solve();

  return 0;
}
