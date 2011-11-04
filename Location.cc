/*
 * Location.cc
 *
 *  Created on: Nov 1, 2011
 *      Author: nietaki
 */
#include "Location.h"

Location::Location() {
	row = col = 0;
};

Location::Location(int r, int c) {
	row = r;
	col = c;
};

Location Location::getBordering(int dir){
	return Location(row + DIRECTIONS[dir][0], col + DIRECTIONS[dir][1]);
}


std::ostream& operator<<(std::ostream &os, const Location &loc) {
	os << "Location: (" << loc.row << ", " << loc.col << ")" << std::endl;
	return os;
}

