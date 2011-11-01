/*
 * Helper.cc
 *
 *  Created on: Nov 1, 2011
 *      Author: nietaki
 */

#include "Helper.h"

Helper::Helper() {
	// TODO Auto-generated constructor stub

}

Helper::~Helper() {
	// TODO Auto-generated destructor stub
}

Square & Helper::getSquare(Grid *inGrid, const Location& inLocation) {
	return (*inGrid)[inLocation.col][inLocation.row];
}


