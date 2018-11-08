#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int infixLength = 0, postfixLength = 0;
char infixExpression[1024], postfixExpression[2048];
int priorities[256];
stack<char> operators;

void input()
{
  cin.getline(infixExpression, 1024);
  infixLength = strlen(infixExpression);
}

void setPriorities()
{
  priorities['('] = 0;
  priorities[')'] = 1;
  priorities['+'] = 2;
  priorities['-'] = 2;
  priorities['*'] = 3;
  priorities['/'] = 3;
  priorities['^'] = 4;
}

bool isDigit(char symbol)
{
  return symbol >= '0' && symbol <= '9';
}

void addOperand(int &index)
{
  while (index < infixLength && isDigit(infixExpression[index]))
  {
    postfixExpression[postfixLength] = infixExpression[index];
    index++;
    postfixLength++;
  }

  postfixExpression[postfixLength] = ' '; // That way we separate operands.
  postfixLength++;
}


void findPostfixExpression()
{
  setPriorities();

  for (int i = 0; i < infixLength; i++)
  {
    if (isDigit(infixExpression[i]))
    {
      addOperand(i);
      i--;
    }

    else if (infixExpression[i] == '(')
    {
      operators.push(infixExpression[i]);
    }

    else
    {
      while (!operators.empty() && priorities[operators.top()] >= priorities[infixExpression[i]])
      {
        postfixExpression[postfixLength] = operators.top();
        postfixLength++;
        operators.pop();
      }

      if (infixExpression[i] == ')')
      {
        operators.pop();
      }

      else
      {
        operators.push(infixExpression[i]);
      }
    }
  }

  while (!operators.empty())
  {
    postfixExpression[postfixLength] = operators.top();
    postfixLength++;
    operators.pop();
  }
}

void printPostfixExpression()
{
  int length = 0;
  char trimedPostfixExpression[1024] = { '\0' };
  for (int i = 0; i < postfixLength; i++)
  {
    if (postfixExpression[i] != ' ')
    {
      trimedPostfixExpression[length] = postfixExpression[i];
      length++;
    }
  }

  cout << trimedPostfixExpression << endl;
}

int extractNumber(int &index)
{
  int number = 0;
  while (index < postfixLength && isDigit(postfixExpression[index]))
  {
    number = number * 10 + (postfixExpression[index] - '0');
    index++;
  }

  return number;
}

int power(int base, int exponent)
{
  int result = 1;
  for (int i = 0; i < exponent; i++)
  {
    result *= base;
  }

  return result;
}

int doTheOperation(int firstNumber, int secondNmber, char operation)
{
  switch (operation)
  {
    case '+': return firstNumber + secondNmber;
    case '-': return firstNumber - secondNmber;
    case '*': return firstNumber * secondNmber;
    case '/': return firstNumber / secondNmber;
    case '^': return power(firstNumber, secondNmber);
  }
}

int evaluatePostfixExpression()
{
  stack<int> numbers;

  for (int i = 0; i < postfixLength; i++)
  {
    if (isDigit(postfixExpression[i]))
    {
      int number = extractNumber(i);
      numbers.push(number);
    }

    else
    {
      int firstNumber = numbers.top();
      numbers.pop();

      int secondNumber = numbers.top();
      numbers.pop();

      int result = doTheOperation(secondNumber, firstNumber, postfixExpression[i]);
      numbers.push(result);
    }
  }

  return numbers.top();
}

int main()
{
  input();

  findPostfixExpression();
  printPostfixExpression();

  cout << evaluatePostfixExpression() << endl;

  return 0;
}
