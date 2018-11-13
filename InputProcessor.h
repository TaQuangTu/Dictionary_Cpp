#ifndef STRING
#include<string>
#define STRING
#endif
#include <utility>
using namespace std;
//for inserting word and relative definition into tree
class InputProcesser   
{
public:
	static pair<string, string> split(string line)
	{
        //a line have form as: keyword definition
		string word;
		string definition;
		int i = 0;
		//get keyword from line
		for (; i < line.size()&&line[i]!=':'; i++)
		{
			word += (char)line[i];
		}
		//get definition, it is remaining characters from line
		i++;
		for (; i < line.size(); i++)
		{
			definition += line[i];
		}
		return make_pair(word,definition);
	}
};