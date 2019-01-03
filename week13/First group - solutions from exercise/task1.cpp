#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool containsElement(const vector<char>& v, const char& c)
{
  for(int i=0;i<v.size();i++)
  {
    if(c==v[i])
    {
      return true;
    }
  }
  return false;
}

//zad 1 - alternative
const int MAXN = 1024;
vector<int> graph[MAXN];
bool dfs(int i, const char* str)
{
  if (i == str[strlen(str) - 1]-  'a')
    return true;

  for (int j = 0; j < graph[i].size(); j++)
    if (graph[i][j] == str[0] - 'a')
      return dfs(graph[i][j], str + 1);

  return false;
}
void inputChar()
{
  int n, m;
  char str[1000];
  cin >> n >> m >> str;
  char firstVertex, secondVertex;
  for (int i = 0; i < m; i++)
  {
    cin >> firstVertex >> secondVertex;
    graph[firstVertex - 'a'].push_back(secondVertex - 'a');
  }
  cout << boolalpha <<dfs(str[0] - 'a', str + 1) << endl;
}

int main()
{
  /*int nodeCount,edgeCount;
  cin>>nodeCount>>edgeCount;

  char word[1001];
  cin>>word;

  vector<vector<char>> graph;
  for(int i=0;i<256;i++)
  {
    graph.push_back(vector<char>());
  }

  char fromChar,toChar;

  for(int i=0;i<edgeCount;i++)
  {
    //cout<<"i = "<<i<<endl;
    cin>>fromChar>>toChar;
    graph[fromChar].push_back(toChar);
  }

  int length = strlen(word);

  if(graph[word[0]].empty())
  {
    cout<<"case 1"<<endl;
    cout<<"false"<<endl;
    return 0;
  }

  for(int i=0;i<length-1;i++)
  {
    if(!containsElement((graph[word[i]]),(word[i+1])) )
    {
      cout<<"case 2"<<endl;
      cout<<"false"<<endl;
      return 0;
    }
  }

  cout<<"true"<<endl;*/


  inputChar();

  return 0;
}
