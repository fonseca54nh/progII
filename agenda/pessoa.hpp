#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int option;

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

void menu();
void print(string); 
void insert(string);
void search(string);
void remove(string);



