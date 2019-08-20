#include "pessoa.hpp"

//oreder to insert civil 
//name 
//cpf
//address
//mail
//state
//
//
//order to inser juridic
//name
//cnpj
//addres
//mail
//ie
//rs

string name, address, state, mail, rs;
int cpf, cnpj, ie;

//functions to collet the data from the user input
void inputCivil(vector<civil> civ)
{
	
	cout << "Digite abaixo os itens requisitados.";

	cout << "Nome: ";
	cin >> name;	civ::name.push_back(name);
	cout << "Cpf: ";
	cin >> cpf;	civ.cpf.push_back(cpf);
	cout << "Endereco: ";
	cin >> address;	civ.address.push_back(address);
	cout << "Email: ";
	cin >> mail;	civ.mail.push_back(mail);
	cout << "Estado Civil: ";
	cin >> state;	civ.state.push_back(state);
}

void inputJuri(vector<juridic> jur)
{

	cout << "Digite abaixo os itens requisitados.";

	cout << "Nome: ";
	cin >> name;	jur.name.push_back(name);
	cout << "Cpf: ";
	cin >> cnpj;	jur.cnpj.push_back(cnpj);
	cout << "Endereco: ";
	cin >> address; jur.address.push_back(address);
	cout << "Email: ";
	cin >> mail;	jur.mail.push_back(mail);
	cout << "Inscricao Estadual: ";
	cin >> ie;	jur.ie.push_back(ie);
	cout << "Razao Social: ";
	cin >> rs;	jur.rs.push_back(rs);
}

//funtion to insert elements
void insert(vector<string> person, const char *filename)
{

	int option;

	cout << "Digite o tipo de pessoa que deseja inserir: ";
	cin >> option;

	ofstream file(filename);
	file.open(filename, ios_base::app);

	while(option != 1 && option != 2)
	{
		if(option == 3) break;
		cout << "option invalida, digite novamente ";
		cin >> option;
	}
	
	//call here the function that inserts the vector containing the classes

	if(option == 1)
	{
	
		inputCivil(vector<string> civil);
			
		file << endl << ";1" << endl;
		
		for(int i = 0; i < civil.size(); ++i)
		{
			file << person.at(i) << endl; 
		}
	}
	
	if(option == 2)
	{
		inputJuri(vector<string> juridic);
		
		file << endl << ";2" << endl;

		for(int i = 0; i < juridic.size(); ++i)
		{
			file << person.at(i) << endl; 
		}
	}
}

//function to print elements in order
void print(string filename)
{

	ifstream file(filename);

	string tmp; 

	
	while(getline(file, tmp))
	{
		if(tmp != ";")
		{
			cout << tmp << endl;
		}
	}

	file.close();
}
