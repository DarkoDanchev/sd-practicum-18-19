#include <iostream>
#include <fstream>

using namespace std;

void solve()
{
  int arr[] = { 1, 2, 7, 10, 9, 3, 5, 6, 4, 8 };

  ofstream fout;
  fout.open("arr_file.bin", ios::binary);

  fout.write((const char*)(arr), 10 * sizeof(int));
  fout.close();
}

int main()
{
  solve();

  return 0;
}
