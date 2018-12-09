#pragma once

#include<iostream>

class pet {

private:
	std::string name;
	std::string breed;
	int age;
	std::string photo;

public:
	//default constructor
	pet();
	//constructor with parameters
	pet(const std::string& name, const std::string& breed, int age, const std::string& photo);
	//getter for name
	std::string getName() const { return name; }
	//getter for breed
	std::string getBreed() const { return breed; }
	//getter for age
	int getAge() const { return age; }
	//getter for photo
	std::string getPhoto() const { return photo; }

	void view();
};
