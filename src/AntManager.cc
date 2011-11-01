/*
 * AntManager.cc
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#include "AntManager.h"
#include "Helper.h"


AntManager* AntManager::_instance = NULL;

AntManager::AntManager() {

}

AntManager *AntManager::instance() {
	if(! AntManager::_instance){
		AntManager::_instance = new AntManager();
	}
	return AntManager::_instance;
}


AntSet *AntManager::getAnts() {
	return &ants;
}

void AntManager::add(AntPtr inAnt) {
	ants.insert(inAnt);
	Square antSquare = State::instance()->getSquare(inAnt->getLocation());
	antSquare.antPtr = inAnt;
	ants.insert(inAnt);
}

void AntManager::setGrid(Grid *inGrid) {
	gridPtr = inGrid;
}


void AntManager::remove(Location inLocation){
	Square antSquare = State::instance()->getSquare(inLocation);
	if(antSquare.antPtr){
		remove(antSquare.antPtr);
	}
}

void AntManager::remove(AntPtr inAnt) {

	Square antSquare = State::instance()->getSquare(inAnt->getLocation());
	antSquare.antPtr.reset();

	ants.erase(inAnt);
}

Grid *AntManager::getGrid() {
	return gridPtr;
}

void AntManager::makeMove(Location fromLocation, int direction) {
	//let's get all the needed objects
	State* state = State::instance();
	Location toLocation = state->getLocation(fromLocation, direction);
	Square fromSquare = state->getSquare(fromLocation);
	Square toSquare = state->getSquare(toLocation);
	AntPtr movingAnt = fromSquare.antPtr;
	//change Ant's location
	movingAnt->setLocation(toLocation);

	return;
	//move ant on the Grid
	fromSquare.antPtr.reset();
	toSquare.antPtr = movingAnt;

	//mark Ant's last move
	movingAnt->hasMoved();

	state->makeMove(fromLocation, direction);
}



//might be useful, don't delete
void AntManager::nextTurn(int moveNo) {
}

AntManager::~AntManager() {
}
