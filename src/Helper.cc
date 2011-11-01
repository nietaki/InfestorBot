/*
 * Helper.cc
 *
 *  Created on: Nov 1, 2011
 *      Author: nietaki
 */

#include "Helper.h"

Helper::Helper() {

}

Helper::~Helper() {
}

Square & Helper::getSquare(Grid *inGrid, const Location& inLocation) {
	return (*inGrid)[inLocation.col][inLocation.row];
}


