#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
  char name[128];
  int facultyNumber;
  double mark;
};

istream& operator>>(istream& in, Student &student)
{
  in.getline(student.name, 128);
  in >> student.facultyNumber >> student.mark;
  in.ignore();

  return in;
}

void solve()
{
  ofstream fout;
  fout.open("studnets.bin", ios::binary);

  Student student;
  while (cin >> student)
  {
    fout.write((const char*)(&student), sizeof(student));
  }

  fout.close();
}

int main()
{
  solve();

  return 0;
}
