#include <iostream>

using namespace std;

//task1
T minElem(queue<int> q) {
	int size = q.size();
	T min = q.front();

	for (int i = 0; i < size; i++) {
		T front = q.front();

		if (min > front)
			min = front;

		q.pop();
		q.push(front);
	}

	return min;
}

//task2

void printBinaries(int n) {
	// Правим си опашка от стрингове и добавяме "1"
	queue<string> q;
	q.push("1");

	for (int i = 0; i < n; i++) {
		// Следващите числа в двоичен запис се получават като от текущото
		// най-малко добавим нула и единица най-отзад. Тези две нови числа
		// ги добавяме към опашката.
		string front = q.front();
		q.pop();
		cout << front << endl;

		q.push(front + "0");
		q.push(front + "1");
	}
}

//task 3
queue<int> mergeSortedQueues(queue<int> left, queue<int> right)
{
    queue<int> result;

    while(!left.empty() && !right.empty())
    {
        if(left.front() <= right.front())
        {
            result.push(left.front());
	    left.pop();
        }
        else
        {
            result.push(right.front());
	    right.pop();
        }
    }

    while(!left.empty())
    {
        result.push(left.front());
	left.pop();
    }
    while(!right.empty())
    {
        result.push(right.front());
	right.pop();
    }

    return result;
}

//task4
enum Priority
{
  LOW, MEDIUM, HIGH
};

template<typename T>
class PriorityQueue
{
  private:
  queue<T> low;
  queue<T> medium;
  queue<T> high;

  public:
  void push(T, Priority);
  void pop();
  T top() const;
  bool empty() const;
};

template<typename T>
void PriorityQueue<T>::push(T element, Priority priority)
{
  if (priority == LOW)
  {
    low.push(element);
  }

  else if (priority == MEDIUM)
  {
    medium.push(element);
  }

  else
  {
    high.push(element);
  }
}

template<typename T>
void PriorityQueue<T>::pop()
{
  if (!low.empty())
  {
    low.pop();
  }

  else if (!medium.empty())
  {
    medium.pop();
  }

  else if (!high.empty())
  {
    high.pop();
  }

  else
  {
    cerr << "Error ! Can not pop from empty priority queue !" << endl;
  }
}

template<typename T>
T PriorityQueue<T>::top() const
{
  if (!low.empty())
  {
    return low.front();
  }

  if (!medium.empty())
  {
    return medium.front();
  }

  if (!high.empty())
  {
    return high.front();
  }

  cerr << "Error ! There is no top element in empty priority queue !" << endl;
}

template<typename T>
bool PriorityQueue<T>::empty() const
{
  return low.empty() && medium.empty() && high.empty();
}

//task5
void task5()
{
  int n, minElement = -1;

  cin >> n;

  queue<int> q2, q3, q5;
  q2.push(2);
  q3.push(3);
  q5.push(5);

  for (int i = 0; i < n; i++)
  {
    minElement = min(min(q2.front(), q3.front()), q5.front());

    if (q2.front() == minElement)
      q2.pop();

    if (q3.front() == minElement)
      q3.pop();

    if (q5.front() == minElement)
      q5.pop();

    q2.push(minElement * 2);
    q3.push(minElement * 3);
    q5.push(minElement * 5);
  }

  cout << minElement << endl;
}

int main()
{

    return 0;
}
