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

civil civ;
juridic jur;

vector<string> collect(vector<string> tmp)
{
	cout << "Name: ";
	cin >> civ.name; tmp.push_back(civ.name);
	cout << "Cpf: ";
	cin >> civ.cpf; tmp.push_back(civ.cpf);
	cout << "Address: ";
	cin >> civ.address; tmp.push_back(civ.address);
	cout << "Mail: ";
	cin >> civ.mail; tmp.push_back(civ.mail);
	cout << "State: ";
	cin >> civ.state; tmp.push_back(civ.state);
	

	return tmp;

}

vector<string> collect2(vector<string> tmp)
{
	
	cout << "Name: ";
	cin >> jur.name; tmp.push_back(jur.name);
	cout << "Cnpj: ";
	cin >> jur.cnpj; tmp.push_back(jur.cnpj);
	cout << "Address: ";
	cin >> jur.address; tmp.push_back(jur.address);
	cout << "Mail: ";
	cin >> jur.mail; tmp.push_back(jur.mail);
	cout << "Inscricao Estadual: ";
	cin >> jur.ie; tmp.push_back(jur.ie);
	cout << "Razao Social: ";
	cin >> jur.rs; tmp.push_back(jur.rs);

	return tmp;
}

//funtion to insert elements
void insert(string filename)
{

	int option;

	cout << "Digite o tipo de pessoa que deseja inserir: ";
	cin >> option;

	ofstream file(filename, fstream::app);
	
	while(option != 1 && option != 2)
	{
		if(option == 3) break;
		cout << "option invalida, digite novamente ";
		cin >> option;
	}

	if(option == 1)
	{
		file << endl << ";1" << endl;
		vector<string> tmp;
			
		vector<string> mula = collect(tmp);		

		for (int i = 0; i < mula.size(); ++i)
		{
			file << mula.at(i) << endl;
		}
	}
	
	if(option == 2)
	{
		file << endl << ";2" << endl;
		vector<string> tmp;
			
		vector<string> mula = collect2(tmp);		

		for (int i = 0; i < mula.size(); ++i)
		{
			file << mula.at(i) << endl;
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
		if(tmp != ";1" && tmp != ";2")
		{
			cout << tmp << endl;
		}
	}

	file.close();
}
