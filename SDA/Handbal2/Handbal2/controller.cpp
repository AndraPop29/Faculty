#include "controller.h"
#include<algorithm>


using namespace std;

void controller::addPlayer(const std::string& name, const std::string& nat, const std::string& team, int goals)
{
	
	this->repository.addPlayer(name, nat, team, goals);
}

bool myFunction(player a, player b) {
	//return (a.getTeam().compare(b.getTeam()));
	return (a.getTeam() < b.getTeam());
}

/*
Provides all players in sorted order by team
Input: -
Output: vector of players in sorted order by team
*/
vector<player> controller::sortPlayers() 
{
	vector<player> all = this->repository.getPlayers();
	sort(all.begin(), all.end(), myFunction);
	return all;
}
int controller::nrNat(string nat)
{
	int nr=repository.nrNat(nat);
	return nr;
}
