#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  ifstream fin;
  fin.open("students.txt");

  char studentName[128];
  int facultyNumber;
  double mark;
  while (fin >> studentName >> facultyNumber >> mark)
  {
    cout << studentName << ' ' << facultyNumber << ' ' << mark << endl;
  }

  fin.close();
}

int main()
{
  solve();

  return 0;
}
