#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class person 
{
	int nasc;
	vector<string> address, name, mail;
};

class civil: public person
{
	int cpf;
	vector<string> state;
};

class juridic: public person
{
	int cnpj, ie;
	vector<string> rs;
};

void print(char); 

