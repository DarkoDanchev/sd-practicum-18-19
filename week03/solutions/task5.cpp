#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  ifstream fin;
  fin.open("arr_file.bin", ios::binary);

  fin.seekg(6 * sizeof(int));
  int seventhElement;
  fin.read((char*)(&seventhElement), sizeof(seventhElement));
  cout << seventhElement << endl;

  fin.seekg(sizeof(int));
  int secondElement;
  fin.read((char*)(&secondElement), sizeof(secondElement));
  cout << secondElement << endl;

  fin.seekg(0);
  int arr[10];
  fin.read((char*)arr, 10 * sizeof(int));
  for (int i = 0; i < 9; i++)
  {
    cout << arr[i] << ' ';
  }

  cout << arr[9] << endl;

  fin.close();
}

int main()
{
  solve();

  return 0;
}
