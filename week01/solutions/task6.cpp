#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

struct Point
{
  double x, y;
};

Point points[4];

void input()
{
  ifstream fin("input.txt");

  for (int i = 0; i < 4; i++)
  {
    fin >> points[i].x >> points[i].y;
  }

  fin.close();
}

bool areDoublesEqual(double firstNumber, double secondNumber, double epsilon = 0.0000001)
{
  return fabs(firstNumber - secondNumber) < epsilon;
}

double calculateRectangleArea()
{
  double xLength = 0.0;
  double yLength = 0.0;
  for (int i = 1; i < 4; i++)
  {
    if (areDoublesEqual(points[i].x, points[0].x))
    {
      yLength = fabs(points[i].y - points[0].y);
    }

    if (areDoublesEqual(points[i].y, points[0].y))
    {
      xLength = fabs(points[i].x - points[0].x);
    }
  }

  return xLength * yLength;
}

int main()
{
  input();
  cout << calculateRectangleArea() << endl;

  return 0;
}
