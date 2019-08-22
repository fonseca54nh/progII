#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class person 
{
public:
	string address, name, mail, nasc;
};

class civil: public person
{
public:
	string state, cpf;
};

class juridic: public person
{
public:
	string rs, cnpj, ie;
};

void print(string); 
void insert(string);
