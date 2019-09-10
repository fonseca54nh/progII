#include "tree.cpp"

//quantidade de bits:
//quantidade de bits compactado
//percentual de compactacao

bool sortdesc(const pair<size_t,size_t> &a, const pair<size_t,size_t> &b)
{
	return (a.second > b.second);
}

int size(string filename)
{
	ifstream file(filename, ios::binary);
	const auto begin = file.tellg();
	file.seekg(0, ios::end);
	const auto end = file.tellg();
	const auto fsize = end - begin;

	return fsize;
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "Error, execution requires <exec> <file.txt> as input" << endl;
		return 1;
	}

	vector<pair<size_t, size_t> > freq(256);

	for(size_t i = 0; i < 256; ++i)
	{
		freq.at(i).first = i;
		freq.at(i).second = 0;
	}

	char ch;

	ifstream file(argv[1]);

	sort(freq.begin(), freq.end(), sortdesc);

	for (size_t i = 0; i < 256; ++i)
	{
		cout << "Character " << i << " Frequency: " << freq.at(i).second << endl;
	}


	cout << "Vector size is: " << freq.size() << endl;

	cout << "O tamanho do arquivo descompactado eh: " << size("lorem.txt") << endl;

	return 0;
}
