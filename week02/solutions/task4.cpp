#include <iostream>
#include<string.h>
#include <fstream>

using namespace std;

const int initialStudentsCount = 6;

struct Student
{
  int facultyNumber;
  double mark;
  char name[128];
};

istream& operator>>(istream &cin, Student &student)
{
  cin >> student.name >> student.facultyNumber >> student.mark;
  return cin;
}

ofstream& operator<<(ofstream &fout, const Student &student)
{
  fout << student.name << ' ' << student.facultyNumber << ' ' << student.mark;
  return fout;
}

fstream& operator<<(fstream &file, const Student &student)
{
  file << student.name << ' ' << student.facultyNumber << ' ' << student.mark;
  return file;
}

void input()
{
  ofstream fout;
  fout.open("students.txt");

  Student student;
  for (int i = 0; i < initialStudentsCount; i++) {
    cin >> student;
    fout << student << endl;
  }

  fout.close();
}

void solve()
{
  fstream file;
  file.open("students.txt");

  char initialStudents[16][256];
  int index = 0;
  while (file.getline(initialStudents[index], 256))
  {
    index++;
  }

  if (index != initialStudentsCount)
  {
    cerr << "Error ! There are not " << initialStudentsCount << " students in the file !" << endl;
    exit(1);
  }

  file.clear();

  cout << "Enter information for a student which is going to be written in the middle of the file: ";
  Student studentInTheMiddle;
  cin >> studentInTheMiddle;

  cout << "Enter information for a student which is going to be written in the beginning of the file: ";
  Student studentInTheBeginning;
  cin >> studentInTheBeginning;

  cout << "Enter information for a student which is going to be written in the end of the file: ";
  Student studentInTheEnd;
  cin >> studentInTheEnd;

  file.seekp(0);

  file << studentInTheBeginning << endl;

  for (int i = 0; i < 3; i++)
  {
    file << initialStudents[i] << endl;
  }

  file << studentInTheMiddle << endl;

  for (int i = 3; i < initialStudentsCount; i++)
  {
    file << initialStudents[i] << endl;
  }

  file << studentInTheEnd << endl;

  file.close();
}

int main()
{
  input();
  solve();

  return 0;
}
