#include "User.h"

User::User() :name(""), id(-1) {}

User::User(string name, int id)
{
	this->name = name;
	this->id = id;
}


User::~User()
{
}
