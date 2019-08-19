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



//funtion to insert elements
void insert(vector<string> person)
{

	int opcao;

	cout << "Digite o tipo de pessoa que deseja inserir: ";
	cin >> opcao;

	ofstream file(filename);
	file.open(filename, ios_base::app);

	while(option != 1 && option != 2)
	{
		if(opcao == 3) break;
		cout << "opcao invalida, digite novamente ";
		cin >> opcao;
	}

	if(option == 1)
	{

		file << endl << 1 << endl;
		
		for(int i = 0; i < person.size(); ++i)
		{
			file << person.at(i) << endl; 
		}
	}
	
	if(option == 2)
	{
		file << endl << 2 << endl;

		for(int i = 0; i < person.size(); ++i)
		{
			file << person.at(i) << endl; 
		}
	}
}

//function to print elements in order
void print(vector<string> filename)
{

	ifstream file(filename);

	string tmp; 

	while(getline(file, tmp))
	{
		cout << tmp << endl;
	}

	file.close();
}
