/*
 * Location.cc
 *
 *  Created on: Nov 1, 2011
 *      Author: nietaki
 */
#include "Location.h"

bool isCorrectDirection(int d){
  return (d >= 0 && d< TDIRECTIONS);
}

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

void Location::dieIfOutOfBounds(int rows, int cols, const char* msg) const {
  if(this->col >= cols || this->row >= rows){
    (* Bugger::getBug()) << "received Location out of bounds: " << (*this) << "for the dimensions (rows, cols): (" << rows << ", " << cols << std::endl;
    (* Bugger::getBug()) << "the location of this unforgivable accident is: " << msg  << std::endl;
    exit(1);
  }
}

int Location::taxiDistance(const Location& other, int cols, int rows) {
  int dist = 0;
  int d1 = abs(col - other.col);
  dist += std::min(d1, cols - d1);

  int d2 = abs(row - other.row);
  dist += std::min(d2, rows - d1);
  return dist;
}





