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

//menu function
void menu()
{
	cout << "1. Inserir pessoa fisica." << endl;
	cout << "2. Inserir pessoa juridica." << endl;
	cout << "3. Remover pessoa. " << endl;
	cout << "4. Pesquisar nome." << endl;
	cout << "5. Visualizar alfabetico. " << endl;
	cout << "6. Visualizar alfabetico por grupo. " << endl;
	cout << "7. Sair. " << endl;
}

//insert funtion for civil
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

//insert function for juridic
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

	ofstream file(filename, fstream::app);

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

//TODO: group search

//search funtion
void search(string filename)
{
	bool flag;
	string find, line;
	cout << "Por quem voce deseja procurar? ";
	cin >> find;
	
	ifstream file(filename);
	while(getline(file, line))
	{
		if(line == find)
		{
			flag = true;	
			cout << line << endl;
		}
	}
	
	if(!flag)
	{
		cout << "Busca sem resultado." << endl;	
	}
	
}

void remove(string filename)
{
	string rem, line;

	cout << "Quem voce deseja remover? ";
	cin >> rem;

	fstream file(filename, ios_base::in | ios_base::out);
	
	while(getline(file, line))
	{
		if(line != rem)
		{
			file << line << endl;
		}

	}		
}



