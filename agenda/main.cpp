#include "pessoa.hpp"

int main()
{
	string filename = "banco";
	
	menu();

	cin >> option;

	while(option > 7 && option < 1)
	{
		cout << "Opcao invalida! Selecione novamente: ";
		cin >> option;
		menu();
	}

	switch(option)
	{
		case 1:
			insert(filename);
		break;
		
		case 2:
			insert(filename);
		break;
		
		case3: 
			remove(filename);
		break;

		case 4:
			search(filename);
		break;

		case 5:
			print(filename);
		break;

		case 6:
			//group print
		break;

		case 7:
		break;
		

	}	
	
	return 0;
}
