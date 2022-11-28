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


	askPlayerToPlace(player, opponent);
	askPlayerToPlace(player, opponent);

	displayGrid(player, opponent);
}
