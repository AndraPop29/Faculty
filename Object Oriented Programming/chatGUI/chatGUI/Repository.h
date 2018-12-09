#pragma once
#include<vector>
#include "Message.h"
#include "User.h"
#include "Observable.h"
using namespace std;

class Repository: public Observable
{
private:
	vector<Message> messages;
	vector<User> users;
	string filename;
public:
	
	Repository(string filename="messages.txt");
	void readFromFile();
	void writeToFile();
	void addMessage(Message mes);
	void clearMessages();
	string getName(int id);
	vector<Message> getMessages() { return messages; }
	vector<User> getUsers() { return users; }
	~Repository();
};

