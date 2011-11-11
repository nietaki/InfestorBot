#ifndef LOCATION_H_
#define LOCATION_H_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Bugger.h"
/*
 constants
 */
const int TDIRECTIONS = 4;
const char CDIRECTIONS[4] = { 'N', 'E', 'S', 'W' };
const int DIRECTIONS[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }; //{N, E, S, W}

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

bool isCorrectDirection(int d);

/*
 struct for representing locations in the grid.
 */
struct Location {
		int row, col;

		Location();

		Location(int r, int c);

		Location getBordering(int dir);
		void dieIfOutOfBounds(int rows, int cols, const char* msg) const;
};

std::ostream& operator<<(std::ostream &os, const Location &loc);

#endif //LOCATION_H_
