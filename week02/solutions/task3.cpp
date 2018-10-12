#include <iostream>
#include <fstream>

using namespace std;

void input()
{
  ofstream fout;
  fout.open("students.txt");

  for (int i = 0; i < 6; i++)
  {
    char name[128];
    int facultyNumber;
    double mark;
    cin >> name >> facultyNumber >> mark;
    fout << name << ' ' << facultyNumber << ' ' << mark << endl;
  }

  fout.close();
}

void solve()
{
  fstream file;
  file.open("students.txt", ios::in|ios::out);

  char name[128];
  int facultyNumber;
  double mark;
  cin >> name >> facultyNumber >> mark;

  for (int i = 0; i < 2; i++)
  {
    char line[256];
    file.getline(line, 256);
  }

  file << name << ' ' << facultyNumber << ' ' << mark << endl;

  cin >> name >> facultyNumber >> mark;
  file.seekp(0);
  file << name << ' ' << facultyNumber << ' ' << mark << endl;

  cin >> name >> facultyNumber >> mark;
  file.seekp(0, ios::end);
  file << name << ' ' << facultyNumber << ' ' << mark << endl;

  file.close();
}

int main()
{
  input();
  solve();

  return 0;
}
