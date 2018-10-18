#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
  char name[128];
  int facultyNumber;
  double mark;
};

ostream& operator<<(ostream &out, Student student)
{
  out << student.name << ' ' << student.facultyNumber << ' ' << student.mark;

  return out;
}

void solve()
{
  ifstream fin;
  fin.open("studnets.bin", ios::binary);

  Student student;
  while (fin.read((char*)(&student), sizeof(student)))
  {
    cout << student << endl;
  }

  fin.close();
}

int main()
{
  solve();

  return 0;
}
