#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct Client
{
  Client()
  {
    accountId = -1;
    strcpy(firstName, "blank");
    strcpy(lastName, "blank");
    balance = 0.0;
  }

  int accountId;
  char firstName[128];
  char lastName[128];
  double balance;
};

int n;

istream& operator>>(istream& in, Client &client)
{
  in >> client.accountId >> client.firstName >> client.lastName  >> client.balance;

  return in;
}

void inputAndCreateFile()
{
  cin >> n;

  ofstream fout;
  fout.open("students.bin", ios::binary);

  Client client;
  for (int i = 0; i < n; i++)
  {
    cin >> client;
    fout.write((const char*)(&client), sizeof(client));
  }

  fout.close();
}

void appendClient(const Client &client)
{
  ofstream fout;
  fout.open("students.bin", ios::app);

  fout.write((const char*)(&client), sizeof(client));

  fout.close();
}

Client findClientByAccountId(int accountId)
{
  ifstream fin;
  fin.open("students.bin", ios::binary);

  Client client;
  while (fin.read((char*)(&client), sizeof(client)))
  {
    if (client.accountId == accountId)
    {
      return client;
    }
  }

  fin.close();

  return Client();
}

void changeClientBalance(int accountId, int newBalance)
{
  fstream file;
  file.open("students.bin", ios::in | ios::out | ios::binary);

  Client client;
  for (int i = 0; i < n; i++)
  {
    file.read((char*)(&client), sizeof(client));
    if (client.accountId == accountId)
    {
      file.seekp(i * sizeof(Client));
      client.balance = newBalance;
      file.write((const char*)(&client), sizeof(client));
      return;
    }
  }

  cerr << "Error ! There is no client with id " << accountId << " !" << endl;
}

void replaceClientByRowNumber(const Client &client, int rowNumber)
{
  ofstream fout;
  fout.open("students.bin", ios::binary);

  fout.seekp((rowNumber - 1) * sizeof(Client));
  fout.write((const char*)(&client), sizeof(client));

  fout.close();
}

int main()
{
  inputAndCreateFile();

  return 0;
}
