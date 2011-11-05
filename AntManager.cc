/*
 * AntManager.cc
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#include "AntManager.h"

AntManager* AntManager::_instance = NULL;

AntManager::AntManager(State* inState) {
	state = inState;

	bug = Bugger::getBug();
	antGrid = AntGrid (state->rows, std::vector<boost::shared_ptr<Ant> > (state->cols, boost::shared_ptr<Ant>()));
}

//AntManager *AntManager::instance() {
//	if(! AntManager::_instance){
//		AntManager::_instance = new AntManager();
//	}
//	return AntManager::_instance;
//}


AntSet *AntManager::getAnts() {
	return &ants;
}

void AntManager::ensureAnt(Location inLocation) {
	//TODO: add ensureAnt once AntPtrs are where they should be
//	Square antSquare = state->getSquare(inAnt->getLocation());
//	antSquare.antPtr = inAnt;
//	ants.insert(inAnt);
//
//	(*bug) << "Ant " << inAnt << " added to " << inAnt->getLocation() << std::endl;
//	(*bug) << "and the square was " << &antSquare << std::endl;

}



void AntManager::remove(Location inLocation){
	Square antSquare = state->getSquare(inLocation);
	if(antSquare.antPtr){
		//calls the other remove, everything is handled there
		remove(antSquare.antPtr);
	}else{
		(*bug) << "AntManager::remove(Location) wanted to remove a non-existent Ant \n";
	}

}

void AntManager::remove(AntPtr inAnt) {

	Square antSquare = state->getSquare(inAnt->getLocation());
	antSquare.antPtr.reset();

	ants.erase(inAnt);
}

void AntManager::makeMove(Location fromLocation, int direction) {
	//FIXME makeMove isnt current anymore
	//let's get all the needed objects
	State* state = state;
	Location toLocation = state->getLocation(fromLocation, direction);
	Square fromSquare = state->getSquare(fromLocation);
	Square toSquare = state->getSquare(toLocation);
	AntPtr movingAnt = fromSquare.antPtr;
	//change Ant's location

	(*bug) << "MakeMove:" << std::endl;
	(*bug) << movingAnt << std::endl;
	(*bug) << fromLocation << std::endl;
	(*bug) << "and the square is " << &fromSquare << std::endl;

	movingAnt->setLocation(toLocation);

	//move ant on the Grid
	fromSquare.antPtr.reset();
	toSquare.antPtr = movingAnt;

	//mark Ant's last move
	movingAnt->hasMovedOn(state->turn);

	state->makeMove(fromLocation, direction);
}



//might be useful, don't delete
/**
 * tells the AntManager the state for next move has been parsed and he can prepare for
 * the Bot making moves
 *
 * in our current case, ensuring ants read in by the state
 */
void AntManager::nextTurn(int moveNo) {
	std::vector<Location>::iterator it;
	for(it = state->myAnts.begin(); it != state->myAnts.end(); it++){
		ensureAnt(*it);
	}

}


AntManager::~AntManager() {
}
