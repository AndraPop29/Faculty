#pragma once
#include<cassert>
#include "repo.h"
using namespace std;

void testAll() {
	repo r("players.txt");
	assert(r.nrNat("ROU") == 1);
	assert(r.nrNat("FRA") == 1);
	assert(r.nrNat("WWW") == 0);
}
