//Name: Andra Pop
//Group: 913
//Homework: Set 2 - Problem 2
//Find all the anagrams of a given word

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

vector<string> words;
vector<string> anagrams;

//void swap(char *x, char *y)
//{
//	char s;
//	s = *x;
//	*x = *y;
//	*y = s;
//}
void permute(string w, int left, int right)
{
	int i;
	if (left == right)
	{
		for (auto x : words)
			if (x == w)
				anagrams.push_back(x);
				
				
	}
	
	else
	{
		for (i = left; i <= right; i++)
		{
			swap(w[left], w[i]);
			permute(w, left + 1, right);
			swap(w[left], w[i]);
		}
	}
	
}

int main()
{
	
	ifstream f("dictionary.txt");
	
	if (!f.is_open())
	{
		cout << "File could not be opened!" << endl;
		return 0;
	}

	string word;
	while (f >> word)
		words.push_back(word);
	f.close();

	string input;
	cout << "Give the word for which you want to find anagrams: " << endl;
	cin >> input;

	if (input.size() < 3)
	{
		cout << "The word must have at least 3 letters" << endl;
		return 0;
	}

	permute(input, 0, input.size() - 1);
	//for (auto x : anagrams)
		//cout << x << " " << endl;
	if (anagrams.size() > 0)
	{
		cout << "The anagrams of the word " <<input<<" are "<< endl;
		for (auto x: anagrams)
			cout << x << endl;

	}
	else
		cout << "There are no anagrams for the word!" << endl;
	system("pause");
	return 0;

}