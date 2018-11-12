#include"Trie.h"
#include<fstream>
#include<unordered_map>
#include<string>
#include"SentenceProcessor.h"
#include<iostream>
using namespace std;
class DictionaryTree
{
private:
	Trie trie;
	unordered_map<string, string> hashTable;
	void loadData()
	{
		fstream file;
		file.open("word_definition.txt");
		string line;
		while (getline(file, line, '\n'))
		{
			pair<string, string> wordAndDefinition = SP::split(line);
			string word = wordAndDefinition.first;
			string definition = wordAndDefinition.second;
			trie.insert(word);
			hashTable[word] = definition;
		}
	}
public:
	DictionaryTree()
	{
		loadData();
	}
	void seach(string keyWordPrefix)
	{
		vector<string> relativeKeyWords= trie.getAllWordWithPrefix(keyWordPrefix);
		if (relativeKeyWords.size() == 0)
		{
			cout << "No result match the prefix\n";
			return;
		}
		for (int i = 0; i < relativeKeyWords.size(); i++)
		{
			string keyword = relativeKeyWords[i];
			cout << keyword << ": ";
			cout << hashTable[keyword] << endl;
		}
	}
};