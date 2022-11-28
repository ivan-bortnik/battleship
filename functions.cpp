#include <string>
#include <iostream>

#include "functions.h"
#include "typeDef.h"

using namespace std;

Coordinate parseCoordinate(string place)
{
	int col = (int) place[0] - 'a';
	int row = stoi(place.substr(1, 1));
	
	Coordinate result;
	result.row = row;
	result.col = col;

	return result;
}

void initializeGrid(Cell aGrid[][SIZE])
{
	for (int iRow = 0; iRow < SIZE; iRow++)
	{
		for (int iCol = 0; iCol < SIZE; iCol++)
		{
			aGrid[iRow][iCol].state = UNSHOT;
			aGrid[iRow][iCol].ship = NONE;
		}
	}
}

void displayGrid(Player& aPlayer, Player& anOppenent)
{
	cout << "   ";
	for (int i = 1; i < SIZE - 1; i++)
	{
		cout << (char) (i + 64) << " ";
	}
	cout << "     ";
	for (int i = 1; i < SIZE - 1; i++)
	{
		cout << (char) (i + 64) << " ";
	}
	cout << endl;

	for (int iRow = 1; iRow < SIZE - 1; iRow++)
	{
		cout << iRow << ((iRow < 10) ? " " : "") << " ";
		for (int iCol = 1; iCol < SIZE - 1; iCol++)
		{
			if (aPlayer.grid[iRow][iCol].ship == 0)
			{
				cout << (char) aPlayer.grid[iRow][iCol].state << " ";
			}
			else
			{
				cout << aPlayer.grid[iRow][iCol].ship << " ";
			}
		}

		// TODO: Using a const margin
		cout << "  ";

		cout << iRow << ((iRow < 10) ? " " : "") << " ";
		for (int iCol = 1; iCol < SIZE - 1; iCol++)
		{
			cout << (char) anOppenent.grid[iRow][iCol].state << " ";
		}

		cout << endl;
	}
}

bool checkCoordinate(string aPlace, Coordinate& sommeCoordi)
{
	Coordinate coord;
	coord = parseCoordinate(aPlace);

	// Check coordinates
	if (coord.col < 0 || coord.col >= SIZE) { return false; }
	if (coord.row < 0 || coord.row >= SIZE) { return false; }
	return true;
}

bool placeShip(Cell grid[SIZE][SIZE], Placement place, Ship ship)
{
	int V, H;
	V = (int) (place.dir == 'V');
	H = (int) (place.dir == 'H');

	for (int i = 0; i < ship; i++)
	{
		for (int iRow = -1; iRow < 2; iRow++)
		{
			for (int iCol = -1; iCol < 2; iCol++)
			{
				if (grid[place.coordi.row + iRow][place.coordi.col + iCol].ship != NONE)
				{
					return false;
				}
			}
		}

		place.coordi.row += V;
		place.coordi.col += H;
	}

	for (int i = 0; i < ship; i++)
	{
		grid[place.coordi.row][place.coordi.col].ship = ship;
		// The loop is now going backward and place the ship from end to start
		place.coordi.row -= V;
		place.coordi.col -= H;
	}

	return true;
}

void askPlayerToPlace(Player & aPlayer, Player & anOppenent)
{
	string coordiRaw;
	char dir;

	while (true)
	{
		cout << "COORDINATES: ";
		cin >> coordiRaw;

		cout << "DIRECTION (H/V): ";
		cin >> dir;

		Coordinate coordi = parseCoordinate(coordiRaw);
		Placement place;
		place.coordi = coordi;
		place.dir = dir;

		if (checkCoordinate(coordiRaw, coordi))
		{
			bool sucess = placeShip(aPlayer.grid, place, CARRIER);
			if (sucess)
			{
				break;
			}
		}
	}


}
