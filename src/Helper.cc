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
	waitingAnts.insert(inAnt);
	Square antSquare = Helper::getSquare(gridPtr, inAnt->getLocation());
	antSquare.ant = inAnt->getOwner();
	antSquare.antPtr = inAnt;
	waitingAnts.insert(inAnt);}

Square & Helper::getSquare(Grid *inGrid, const Location& inLocation) {
	return (*inGrid)[inLocation.col][inLocation.row];
}


