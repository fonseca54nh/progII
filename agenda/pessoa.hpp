#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class person 
{
public:
	int nasc;
	vector<string> address, name, mail;
};

class civil: public person
{
public:
	int cpf;
	vector<string> state;
};

class juridic: public person
{
public:
	int cnpj, ie;
	vector<string> rs;
};

void print(string); 

void inputCivil(vector<string>);

void inputJuri(vector<string>);

void insert(vector<string> person, const char *filename);
