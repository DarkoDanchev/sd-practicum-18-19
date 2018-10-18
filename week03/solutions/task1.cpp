#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  ifstream fin;
  fin.open("input.txt");

  ofstream fout;
  fout.open("output.bin", ios::binary);

  int k;
  while (fin >> k)
  {
    fin.ignore();
    int sum = 0;
    int prod = 1;
    int number;
    for (int i = 0; i < k; i++)
    {
      fin >> number;
      sum += number;
      prod *= number;
    }

    fout.write((const char*)(&sum), sizeof(sum));
    fout.write((const char*)(&prod), sizeof(prod));

    fin.ignore();
  }

  fin.close();
  fout.close();
}

void print()
{
  ifstream fin;
  fin.open("output.bin", ios::binary);

  int sum;
  int prod;
  fin.read((char*)(&sum), sizeof(sum));
  fin.read((char*)(&prod), sizeof(prod));

  while (fin)
  {
    cout << sum << ' ' << prod << endl;

    fin.read((char*)(&sum), sizeof(sum));
    fin.read((char*)(&prod), sizeof(prod));
  }

  fin.close();
}

int main()
{
  solve();
  print();

  return 0;
}
