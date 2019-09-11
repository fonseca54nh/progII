#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> generate(vector<int> vec)
{
	for (int i = 0; i < 300000; ++i)
	{
		int a = rand();
		vec.push_back(a);
	}

	return vec;
}

int main()
{
	vector<int> a, tmp; //= generate(a);

	a = generate(tmp);

	int j = 0, i;

	auto tempoInicial = chrono::system_clock::now();

	for(j = 1; j < a.size(); ++j)
	{
		int key = a.at(j);
		i = j - 1;
		
		while((i >= 0) && (a.at(i) < key))
		{
			a.at(i + 1) = a.at(i);
			i = i -1;
		}
		
		a.at(i + 1) = key;
	}

	for(int i = 0; i < a.size(); ++i)
	{
		cout << a.at(i) << " ";
	}
	
	auto tempoFinal = chrono::system_clock::now();

	chrono::duration<double> elapsedSeconds = tempoFinal - tempoInicial;

	cout << "Tempo decorrido: " << elapsedSeconds.count() << endl;
}
