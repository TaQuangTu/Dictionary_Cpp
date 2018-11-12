#ifndef VECTO
#include<vector>
#define VECTOR
#endif
using namespace std;
class TrieNode
{
private:
	bool isEnd;
	TrieNode* links[26];
public:
	TrieNode()
	{
		isEnd = false;
		for (int i = 0; i < 26; i++)
		{
			links[i] = NULL;
		}
	}
	TrieNode* get(int i)
	{
		return links[i];
	}
	bool containsKey(char ch)
	{
		return links[ch - 'a'] != NULL;
	}
	void put(char ch)
	{
		links[ch - 'a'] = new TrieNode();
	}
	void setEnd()
	{
		isEnd = true;
	}
	bool endOfWord()
	{
		return isEnd;
	}
	TrieNode* get(char ch)
	{
		return links[ch - 'a'];
	}
};
class Trie {
	TrieNode* mRoot;
	vector<string> getWords(TrieNode*startNode, vector<string>& results, string startWord)
	{
		for (int i = 0; i < 26; i++)
		{
			TrieNode* nextNode = startNode->get((int)i);
			if (nextNode != NULL)
			{
				string temp = startWord + char(i + (int)('a'));
				if (nextNode->endOfWord())
				{
					results.push_back(temp);
				}
				getWords(nextNode, results, temp);
			}
		}
		return results;
	}
public:
	Trie()
	{
		mRoot = new TrieNode();
	}
	/** Inserts a word into the trie. */
	void insert(string word)
	{
		TrieNode* tempNode = mRoot;
		for (int i = 0; i < word.size(); i++)
		{
			if (!tempNode->containsKey(word[i]))
			{
				tempNode->put(word[i]);
			}
			tempNode = tempNode->get(word[i]);
		}
		tempNode->setEnd();
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* tempNode = mRoot;
		for (int i = 0; i < word.size(); i++)
		{
			if (!tempNode->containsKey(word[i]))
			{
				return false;
			}
			tempNode = tempNode->get(word[i]);
		}
		if (tempNode->endOfWord()) return true;
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string word) {
		TrieNode* tempNode = mRoot;
		for (int i = 0; i < word.size(); i++)
		{
			if (!tempNode->containsKey(word[i]))
			{
				return false;
			}
			tempNode = tempNode->get(word[i]);
		}
		return true;
	}
	vector<string> getAllWordWithPrefix(string prefix)
	{
		vector<string> results;
		TrieNode* tempNode = mRoot;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (!tempNode->containsKey(prefix[i]))
			{
				return results; // return empty vector
			}
			tempNode = tempNode->get(prefix[i]);
		}
		if (tempNode->endOfWord())
		{
			results.push_back(prefix);
		}
		return getWords(tempNode,results,prefix);
	}
};
