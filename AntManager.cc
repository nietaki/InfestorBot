/*
 * AntManager.cc
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#include "AntManager.h"


const int AntManager::ANT_PRESENT;
const int AntManager::ANT_ABSENT;
const int AntManager::ANT_LOCATION_INVALID;
const int AntManager::SUCCESS;
const int AntManager::DIRECTION_INVALID;
const int AntManager::TARGET_LOCATION_INVALID;

AntManager::AntManager(State* inState) {

	state = inState;

	bug = Bugger::getBug();
	antGrid = AntGrid (state->rows, std::vector<boost::shared_ptr<Ant> > (state->cols, boost::shared_ptr<Ant>()));
}


AntSet *AntManager::getAnts() {
	return &ants;
}

AntPtr AntManager::getAnt(Location inLoc ) {
	return antGrid[inLoc.row][inLoc.col];
}

AntPtr& AntManager::getAntRef(Location inLoc ) {
	return antGrid[inLoc.row][inLoc.col];
}


int AntManager::ensureAnt(Location inLoc) {
  if(! state->onBoard(inLoc))
    return ANT_LOCATION_INVALID;
	AntPtr& antPtr = getAntRef(inLoc);
	if(!antPtr){
		//if there isn't any ant there yet;
		AntPtr newAnt = Ant::makeAnt(0, inLoc);
		antPtr = newAnt;
		ants.insert(newAnt);
		(*bug) << "Ant " << newAnt << " added to " << newAnt->getLocation() << std::endl;
		return SUCCESS;
	}else{
		(*bug) << "Ant couldn't be added to " << inLoc << " an ant already present" << std::endl;
		return ANT_PRESENT;
	}
}



int AntManager::removeAnt(Location inLoc){
  if(!state->onBoard(inLoc)){
    return ANT_LOCATION_INVALID;
  }
	AntPtr& antPtr = getAntRef(inLoc);
	if(antPtr){
		ants.erase(antPtr);
		antPtr.reset();
		(*bug) << "AntManager::remove(Location) removed Ant at Location " << inLoc << " \n";
		return SUCCESS;
	}else{
		(*bug) << "AntManager::remove(Location) wanted to remove a non-existent Ant at Location " << inLoc << " \n";
		return ANT_ABSENT;
	}

}

int AntManager::removeAnt(AntPtr inAnt) {
	if(inAnt){
		return removeAnt(inAnt->getLocation());
	}else{
	  return ANT_LOCATION_INVALID;
	}
}

int AntManager::makeMove(Location fromLoc, int direction) {
  if(! isCorrectDirection(direction)){
    (*bug) << "makeMove invoked with incorrect direction: " << direction << std::endl;
    return DIRECTION_INVALID;

  }
	//FIXME makeMove isnt current anymore
	//let's get all the needed objects

	//all copies of smart_pointers
	Location toLoc = state->getLocation(fromLoc, direction);

	(*bug) << "MakeMove:" << std::endl;
	(*bug) << "from " << fromLoc << std::endl;
	(*bug) << "to " << toLoc << std::endl;

	AntPtr fromAntPtr = getAnt(fromLoc);
	AntPtr toAntPtr = getAnt(toLoc);

	if(! fromAntPtr){
	  (*bug) << "non-existant Ant in makeMove at " << fromLoc << std::endl;
	  return ANT_ABSENT;
	}

	fromAntPtr->hasMovedOn(state->turn);
	fromAntPtr->setLocation(toLoc);


//	(*bug) << (*fromAntPtr) << std::endl;

	//move ant on the Grid

	//set the moving ant in target location
	getAntRef(toLoc) = fromAntPtr;

	//and remove it from the current one
	getAntRef(fromLoc).reset();
	state->makeMove(fromLoc, direction);

	return SUCCESS;
}



//might be useful, don't delete
/**
 * tells the AntManager the state for next move has been parsed and he can prepare for
 * the Bot making moves
 *
 * in our current case, ensuring ants read in by the state
 */
int AntManager::nextTurn(int moveNo) {
	std::vector<Location>::iterator it;
	for(it = state->myAnts.begin(); it != state->myAnts.end(); it++){
		ensureAnt(*it);
	}
	return 0;
}


AntManager::~AntManager() {
}
