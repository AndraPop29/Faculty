
#include "abstractmap.h"
#include"DynVector.h"
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include "Tests.h"
#include "Hashtable.h"

using namespace std;

typedef string TKey;
typedef string TValue;


typedef struct mapE {
	TKey c;
	TValue v;
}mapE;

DynamicVector<mapE> vec;

/*
Description:
Function verifies if 2 keys are formed by the same letters by comparing keys(for abc the key is: a1b1c1 and for bca:b1c1a1)
Input:key1, key2
Output:1-if the keys are permtations=>the corresponding words are anagrams
		0-if the keys aren't permutations=>the corresponding words aren't anagrams
*/
int valid(TKey key1, TKey key2)
{
	int i, j;
	string s1 = "";
	string s2 = "";
	int ok = 0;
	for (i = 0; i < key1.size(); i += 2)
	{
		s1 = key1[i] + key1[i + 1];
		for (j = 0; j < key2.size(); j += 2)
		{
			s2 = key2[j] + key2[j + 1];

			if (s1 == s2)
			{
				ok = 1;
				break;
			}
		}
		if (!ok)
			return 0;
		s1 = "";
		s2 = "";
		ok = 0;
	}
	return 1;
}
void tiparesteDictionar(const Hashtable& d) {
	Iterator it = d.iterator();
	while (it.valid()) {
		TElem e = it.element();
		cout << '(' << e.c << ',' << e.v << ')' << endl;
		it.next();
	}
}
/*
Description:
Function for searching the dynamic vector for anagrams of the read word(el.v)
Input:the map element(key of form: LetterNrOfAppearances...; value:the word)
Output:a list of anagrams represented with a dynamic vector
*/
DynamicVector<mapE> search(mapE el)
{
	DynamicVector<mapE> anagrams;
	//mapE* elem = elems.getAllElems();
	//if (elem == NULL)
		//return 0;

	for (int i = 0; i < vec.getSize(); i++)
	{

		mapE e = vec[i];
		if (e.c.size() == el.c.size() && valid(e.c, el.c))
		{
			
			anagrams.put(e);
		}
	}
	return anagrams;

}
/*
Description: 
Adds an element of type mapE to the dynamic vector if the key doesn't exist
Input: TKey c, TValue v
Output: 1, if successful
		0,if not
*/
int addToV(TKey c, TValue v)
{
	mapE e;
	e.c = c;
	e.v = v;
	for (int i = 0; i < vec.getSize(); i++)
		if (vec[i].c == c)
			return 0;
	vec.put(e);
	return 1;

}
int main() {
	Tests<mapE> t;
	t.testAll();

	string input;
	vector<string> words;
	Hashtable d;
	cout << "Give the word for which you want to find anagrams: " << endl;
	cin >> input;
	if (input.size() < 3)
	{
		cout << "The word must have at least 3 letters" << endl;
		return 0;
	}
	ifstream f("new.txt");

	if (!f.is_open())
	{
		cout << "File could not be opened!" << endl;
		return 0;
	}
	string word;
	while (f >> word)
		words.push_back(word);
	f.close();
	
	cout << endl;
	string s;
	int cmd;
	cout << "Would you like to use 1.dynamic vector or 2.hashtable representation?" << endl;
	cin >> cmd;
	if (cmd == 1)
	{
		for (int i = 0; i < words.size(); i++)//parse through the words from the file
		{
			s = "";
			for (int k = 0; k < words[i].size(); k++)//for each letter of a word
			{
				int c = 1;//number of appearences in the word

				char l = words[i][k];

				for (int j = k + 1; j < words[i].size(); j++)//count the appearences
				{

					if (words[i][j] == l)
						c++;
				}
				stringstream ss;
				ss << c;
				string str = ss.str();
				s = s + l + str;//key=key+letter+nrOfAppearences

			}
			addToV(s, words[i]);//add the key and value to the vector if it doesn't already contain the key
		}

		mapE e;
		//same operation for finding the key for the read word
		e.v = input;
		s = "";
		for (int k = 0; k < input.size(); k++)
		{
			int c = 1;

			char l = input[k];

			for (int j = k + 1; j < input.size(); j++)
			{

				if (input[j] == l)
					c++;
			}
			stringstream ss;
			ss << c;
			string str = ss.str();
			s = s + l + str;

		}

		e.c = s;
		DynamicVector<mapE> anagrams = search(e);

		cout << "The anagrams are: " << endl;
		for (int i = 0; i < anagrams.getSize(); i++)
		{

			mapE e = anagrams[i];
			cout << e.v << endl;

		}
	}
	//HASHTABLE
	else
	{
		for (int i = 0; i < words.size(); i++)
		{
			s = "";
			for (int k = 0; k < words[i].size(); k++)
			{
				int c = 1;

				char l = words[i][k];

				for (int j = k + 1; j < words[i].size(); j++)
				{
					//cout << words[i][j]<<endl;
					if (words[i][j] == l)
						c++;
				}
				stringstream ss;
				ss << c;
				string str = ss.str();
				s = s + l + str;
				//cout << "string: " << s << endl;
			}
			d.add(s, words[i]);
		}

		s = "";
		for (int k = 0; k < input.size(); k++)
		{
			int c = 1;

			char l = input[k];

			for (int j = k + 1; j < input.size(); j++)
			{

				if (input[j] == l)
					c++;
			}
			stringstream ss;
			ss << c;
			string str = ss.str();
			s = s + l + str;

		}
		

		//cout << "The anagrams for the word are: \n";
		//d.anagrams(s);
		tiparesteDictionar(d);
		system("pause");
	}
	system("pause");
	return 0;
}