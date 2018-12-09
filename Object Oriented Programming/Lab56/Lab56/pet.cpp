
#include <Windows.h>
#include <shellapi.h>
#include <conio.h>
#include <stdlib.h>

#include "pet.h"

pet::pet(): name(""), breed(""), age(0), photo("") {}

pet::pet(const std::string& name, const std::string& breed, int age, const std::string& photo)
{
	this->name = name;
	this->breed = breed;
	this->age = age;
	this->photo = photo;
}

void pet::view()
{

	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str() , NULL, SW_SHOWMAXIMIZED);
	
}
