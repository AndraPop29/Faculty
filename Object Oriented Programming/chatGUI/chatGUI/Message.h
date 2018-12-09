#pragma once
#include<string>
using namespace std;

class Message
{
private:
	string text;
	int u;
public:
	Message();
	Message(string text, int u);
	int getUser() { return u; }
	string getText() { return text; }
	~Message();
};

