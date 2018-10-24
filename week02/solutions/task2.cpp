#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  char fileName[128];
  cin >> fileName;

  ofstream fout(fileName, ios::app);
  cout << fout.tellp() << endl;

//  ifstream fin(fileName, ios::ate);
//  cout << fin.tellg() << endl;
//  fin.close();

//  // Second solution
//  ifstream fin(fileName);
//  fin.seekg(0, ios::end);
//  cout << fin.tellg() << endl;
//  fin.close();
}

int main()
{
  solve();

  return 0;
}
