#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

bool isNumberPrime(int number)
{
  for (int i = 2; i * i <= number; i++)
  {
    if (number % i == 0)
    {
      return false;
    }
  }

  return true;
}

void transformCreditCardNumber(char* creditCardNumber)
{
  int width = strlen(creditCardNumber);
  if (width == 12)
  {
    char lastThreeDigits[8] = { '\0' };
    strcpy(lastThreeDigits, creditCardNumber + 9);
    cout << setfill('*') << setw(width) << lastThreeDigits << endl << endl;
  }

  else
  {
    char lastFourDigits[8];
    strcpy(lastFourDigits, creditCardNumber + 10);
    cout << setfill('*') << setw(width) << lastFourDigits << endl << endl;
  }
}

// Second way to solve b)
void transformCreditCardNumber()
{
  string a;
  string b;
  cin>>a;
  if(a.length() == 14){
      for(int i = 0,k = a.length() - 4; i < 4; i++,k++)
      {
          b += a[k];
      }

  }
  else if(a.length() == 12)
  {
      for(int i = 0,k = a.length() - 3; i < 3; i++,k++)
      {
          b += a[k];
      }
  }
  else
  {
      cout<<"Invalid input!"<<endl;
  }
  cout <<setfill ('*') << setw (a.length())<< b << endl;
}

void calculateAndPrintArea(double firstSide, double secondSide)
{
  double area = firstSide * secondSide;
  cout.precision(7);
  cout << area << endl;
  cout << scientific << area << endl;
  cout << fixed << area << endl;
}

void solve()
{
  // а)
  int number;
  cin >> number;
  cout << boolalpha << isNumberPrime(number) << endl << endl;

  // б)
  char creditCardNumber[16];
  cin >> creditCardNumber;
  transformCreditCardNumber(creditCardNumber);

  // Second solution
  transformCreditCardNumber();

  // в)
  double firstSide;
  double secondSide;
  cin >> firstSide >> secondSide;
  calculateAndPrintArea(firstSide, secondSide);
}

int main()
{
  solve();

  return 0;
}
