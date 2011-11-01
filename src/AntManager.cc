/*
 * AntManager.cc
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#include "AntManager.h"

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
	Square antSquare = State::instance()->getSquare(inAnt->getLocation());
	antSquare.antPtr = inAnt;
	ants.insert(inAnt);

	State::instance()->bug << "Ant " << inAnt << " added to " << inAnt->getLocation() << std::endl;
	State::instance()->bug << "and the square was " << &antSquare << std::endl;

}

void AntManager::setGrid(Grid *inGrid) {
	gridPtr = inGrid;
}


void AntManager::remove(Location inLocation){
	Square antSquare = State::instance()->getSquare(inLocation);
	if(antSquare.antPtr){
		//calls the other remove, everything is handled there
		remove(antSquare.antPtr);
	}else{
		State::instance()->bug << "AntManager::remove(Location) wanted to remove a non-existent Ant \n";
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

	state->bug << "MakeMove:" << std::endl;
	state->bug << movingAnt << std::endl;
	state->bug << fromLocation << std::endl;
	state->bug << "and the square is " << &fromSquare << std::endl;

	movingAnt->setLocation(toLocation);

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
