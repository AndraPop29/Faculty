#include "ui.h"
#include<iostream>
#include<string>
#include <conio.h>

using namespace std;

void ui::printMenu()
{
	cout << endl;
	cout << "Welcome to Andra's dog shelter! :)" << endl;
	cout << "Are you a customer or the administrator of the database?" << endl;
	cout << "1. Administrator mode"<<endl;
	cout << "2. User mode"<<endl;
	cout << "0. Exit"<<endl;
}

void ui::printAdminMenu()
{
	cout << "Keep in mind that each dog has a unique name :D" << endl;
	cout << "Possible commands: " << endl;
	cout << "1 - Display all dogs" << endl;
	cout << "2 - Add a dog" << endl;
	cout << "3 - Remove a dog" << endl;
	cout << "4 - Update dog info" << endl;

	cout << "0 - Back" << endl;

}

void ui::printUserMenu()
{
	cout << "1 - See all the dogs in the database " << endl;
	cout << "2 - See all the dogs of a given breed, having an age less than a given number" << endl;
	cout << "3 - View your adoption list"<<endl;
	cout << "0 - Back" << endl;

	
}
void ui::printAdoptionMenu()
{
	cout << "1 - Adopt this dog " << endl;
	cout << "2 - View next " << endl;
	//cout << "3 - View the adoption list" << endl;
	cout << "0 - Back" << endl;
}
void ui::addPetToRepo()
{
	cout << "Enter the name of the dog: ";
	std::string name;
	getline(cin, name);
	
	cout << " Enter the breed of the dog: ";
	std::string breed;
	getline(cin, breed);

	cout << "Enter the age of the dog: ";
	int age;
	cin >> age;

	cout << "Photo link: ";
	std::string photo;
	//getline(cin, photo);
	cin >> photo;
	int val=this->con.addPetToRepo(name, breed, age, photo);
	if (val == 0)
		cout << "There already exists a dog with that exact name!" << endl;
	else
		cout << "The dog has been added!" << endl;
}

void ui::displayAllPets()
{
	dynVector<pet> v = this->con.getRepo().getPets();
	pet* pets = v.getAllElems();
	if (pets == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no dogs in the repository"<<endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		pet p = pets[i];
		cout << p.getName()<<", "<<p.getBreed()<<", "<<p.getAge()<<" years old "<<endl;

	}

}

void ui::deletePet()
{
	cout << "Enter the name of the dog: ";
	std::string name;
	getline(cin, name);
	int r=this->con.deletePetFromRepo(name);
	if (r == 0)
		cout << "The dog isn't in the shelter. " << endl;
	else
		cout << "The dog has been removed from the database" << endl;
}
void ui::updatePet()
{
	cout << "The name of the pet is: ";
	std::string name;
	cin >> name;
	int val=this->con.deletePetFromRepo(name);
	if (val != 0)
	{
		cout << "Give the new information: " << endl;
		cout << " breed: ";
		std::string breed;
		cin >> breed;
		//getline(cin, breed);

		cout << "Age: ";
		int age;
		cin >> age;

		cout << "Photo link: ";
		std::string photo;
		//getline(cin, photo);
		cin >> photo;

		this->con.addPetToRepo(name, breed, age, photo);
	}
	else
		cout << "No dog with that name in the database!" << endl;

}
void ui::addDogsToCat()
{
	dynVector<pet> v = this->con.getRepo().getPets();
	pet* pets = v.getAllElems();
	if (pets == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no dogs in the repository" << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		pet p = pets[i];
		this->con.addPetToCat(p);

	}
}
int ui::viewDogs()
{
	
	if (this->con.getCat().isEmpty())
	{
		cout << "No dogs, come back later!" << endl;
		return 0;
	}


	this->con.openCat();
	pet p = this->con.getCat().getCurrentDog();
	cout << "Now showing: " << p.getName() << " - " << p.getBreed() << " , " << p.getAge() << " years old" << endl;
}
void ui::adoptDog()
{
	pet p = this->con.getCat().getCurrentDog();
	this->con.addToList(p);
	this->con.deletePetFromRepo(p.getName());
	//this->con.getCat().clear();
	//this->addDogsToCat();
	//this->viewDogs();
}
void ui::viewAdoptList()
{
	dynVector<pet> list = this->con.getCat().getList();
	if (list.getSize() == 0)
		cout << "No dogs adopted..yet" << endl;
	for (int i = 0; i < list.getSize(); i++)
		cout << list[i].getName() << " " << list[i].getBreed() << " " << list[i].getAge()<<endl;
}
int ui::nextDog()
{
	if (this->con.getCat().isEmpty())
	{
		cout << "No dogs"<<endl;
		return 0;
	}
	this->con.nextPet();
	pet p = this->con.getCat().getCurrentDog();
	cout << "Now showing: " << p.getName() << " - " << p.getBreed() << " , " << p.getAge() << " years old" << endl;

}

int ui::filterDogs()
{
	std::string b;
	int a;
	if (this->con.getRepo().getRepoSize()==0)
	{
		cout << "No dogs, come back later!"<<endl;
		
	}
	else
	{
		cout << "Give breed: "<<endl;
		std::getline(std::cin, b);
		cout << "Give age: " << endl;
		cin >> a;
		if (b == "")
	
			this->addDogsToCat();
		else
		{
			int val = this->con.filterD(b, a);
			if (!val)
				return 0;
		}
		system("cls");
		this->viewDogs();

	}
	return 1;

}
void ui::adoptionMenu()
{
	
	int com;
		while (true)
		{

			this->printAdoptionMenu();
			cout << "What would you like to do? ";
			cin >> com;
			cin.ignore();
			system("cls");
			if (com == 0)
			{
				this->con.clearCat();
				system("cls");
				break;
			}
			
			

			if (com == 1)
			{
				//adopt dog
				this->adoptDog();
				break;
			}
			if (com == 2)
			{
				//go to next dog
				this->nextDog();
			
			}
			
			
		}
}

void ui::run()
{
	while (true)
	{
		ui::printMenu();
		int command;
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		//repository management
		if (command == 1)
		{
			while (true)
			{
				system("cls");
				ui::printAdminMenu();
				int cmd;
				this->con.sortPets();
				cout << "Input command: ";
				cin >> cmd;
				cin.ignore();
				if (cmd == 0)
					break;
				switch (cmd)
				{
				case 1:
					system("cls");
					
					this->displayAllPets();
					_getch();
					break;
				case 2:
					this->addPetToRepo();
					break;
				case 3:
					this->deletePet();
					break;
				case 4:
					this->updatePet();


				}


			}

		}
		//user menu
		if (command == 2)
		{
			
			while (true)
			{
				
				//system("cls");
				ui::printUserMenu();
				//while (true)
				//{
					int com;
					cout << "Give command: ";
					cin >> com;
					cin.ignore();
					if (com == 0)
					{
						system("cls");
						break;
					}
					//int val = this->filterDogs();
					switch (com)
					{
					case 1:
						system("cls");
						this->con.clearCat();
						this->addDogsToCat();
						this->viewDogs();
						this->adoptionMenu();
						break;
					
					case 2:
						system("cls");
						this->con.clearCat();
						if (this->filterDogs() != 0)
							this->adoptionMenu();
						else
							cout << "No dogs match the filter criteria!"<<endl;
						break;
					case 3:
						this->viewAdoptList();
						
					}
					//system("cls");
					
					
				//}
			}
		}
	}
}