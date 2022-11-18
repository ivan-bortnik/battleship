#include <iostream>
#include <string>

#include "functions.h"
#include "typeDef.h"

using namespace std;

void initializeGrid(Cell aGrid[][SIZE])
{
	for (int iRow = 0; iRow < SIZE; iRow++)
	{
		for (int iCol = 0; iCol < SIZE; iCol++)
		{
			aGrid[iRow][iCol].state = UNSHOT;
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
			cout << (char) aPlayer.grid[iRow][iCol].state << " ";
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
	// Parse coordinates
	int col = (int) aPlace[0] - 'a';
	int row = stoi(aPlace.substr(1, 1));

	// Check coordinates
	if (col < 0 || col >= SIZE) { return false; }
	if (row < 0 || row >= SIZE) { return false; }
	return true;
}

