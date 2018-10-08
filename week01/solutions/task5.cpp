#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  if (cin.peek() >= '0' && cin.peek() <= '9')
  {
    int number;
    cin >> number;
    cout << "You entered the number " << number << '.' << endl;
    return;
  }

  string word;
  cin >> word;
  cout << "You entered the word " << word << '.' << endl;
}

int main()
{
  solve();

  return 0;
}
