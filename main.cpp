#include"DictionaryTree.h"
using namespace std;
int main()
{
	DictionaryTree dic;
	string prefix="anyWordDifferExit";
	while (prefix!="exit")
	{
		cout << "===================_TYPE_KEYWORD_(TYPE_exit_TO_CLOSE)_======================\n";
		cout << "May muon tim chu gi: ";
		cin >> prefix;
		if (prefix != "exit")
		{
			dic.seach(prefix);
		}
	}
	return 0;
}