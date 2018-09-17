#pragma once
#include "repo.h"
#include<string>

class conException
{
public:
	conException(std::string message)
	{
		this->message = message;
	}
	std::string getMessage() const
	{
		return this->message;
	}
private:
	std::string message;
};
class controller
{
private:
	repo repository;
	

public:
	controller(const repo& r) : repository(r){}
	//default constructor for controller
	repo getRepo() const { return repository; }
	//getter for the repository
	
	void addPlayer(const std::string& name, const std::string& nat, const std::string& team, int goals);
