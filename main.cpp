#include"DictionaryTree.h"
using namespace std;
int main()
{
	DictionaryTree dic;
	string prefix="start";
	while (prefix!="exit")
	{
		cout << "===================_TYPE_KEYWORD_(TYPE_exit_TO_CLOSE)_======================\n";
		cout << "Tao moi may nhap: ";
		cin >> prefix;
		if (prefix != "exit")
		{
			dic.seach(prefix);
		}
	}
	return 0;
}