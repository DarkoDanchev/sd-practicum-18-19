#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  ofstream fout;
  fout.open("students.txt");

  char studentName[128];
  int facultyNumber;
  double mark;
  while (cin >> studentName >> facultyNumber >> mark)
  {
    fout << studentName << ' ' << facultyNumber << ' ' << mark << endl;
  }

  fout.close();
}

int main()
{
  solve();

  return 0;
}
