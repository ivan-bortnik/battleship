#include <iostream>

#include "typeDef.h"
#include "functions.h"

using namespace std;

int main()
{
	Player player;
	Player opponent;

	initializeGrid(player.grid);
	initializeGrid(opponent.grid);

	player.grid[3][3].ship = CARRIER;

	displayGrid(player, opponent);

	Coordinate test;

	cout << checkCoordinate("e5", test) << endl;
}
