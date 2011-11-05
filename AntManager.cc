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

void AntManager::ensureAnt(AntPtr inAnt) {
	Square antSquare = state->getSquare(inAnt->getLocation());
	antSquare.antPtr = inAnt;
	ants.insert(inAnt);

	(*bug) << "Ant " << inAnt << " added to " << inAnt->getLocation() << std::endl;
	(*bug) << "and the square was " << &antSquare << std::endl;

}

void AntManager::setGrid(Grid *inGrid) {
	gridPtr = inGrid;
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

Grid *AntManager::getGrid() {
	return gridPtr;
}

void AntManager::makeMove(Location fromLocation, int direction) {
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
 */
void AntManager::nextTurn(int moveNo) {
}

/*
 This function will update update the lastSeen value for any squares currently
 visible by one of your live ants.

 BE VERY CAREFUL IF YOU ARE GOING TO TRY AND MAKE THIS FUNCTION MORE EFFICIENT,
 THE OBVIOUS WAY OF TRYING TO IMPROVE IT BREAKS USING THE EUCLIDEAN METRIC, FOR
 A CORRECT MORE EFFICIENT IMPLEMENTATION, TAKE A LOOK AT THE GET_VISION FUNCTION
 IN ANTS.PY ON THE CONTESTS GITHUB PAGE.
 */
void AntManager::updateVisionInformation() {
	std::queue<Location> locQueue;
	Location sLoc, cLoc, nLoc;

	AntSet::const_iterator it;
	for(it = ants.begin(); it != ants.end(); it++){
		sLoc = (*it)->getLocation();
		locQueue.push(sLoc);

		std::vector<std::vector<bool> > visited(state->rows, std::vector<bool>(state->cols, 0));
		state->grid[sLoc.row][sLoc.col].isVisible = 1;
		visited[sLoc.row][sLoc.col] = 1;

		while (!locQueue.empty()) {
			cLoc = locQueue.front();
			locQueue.pop();

			for (int d = 0; d < TDIRECTIONS; d++) {
				nLoc = state->getLocation(cLoc, d);

				if (!visited[nLoc.row][nLoc.col] && state->distance(sLoc, nLoc) <= state->viewradius) {
					state->grid[nLoc.row][nLoc.col].isVisible = 1;
					locQueue.push(nLoc);
				}
				visited[nLoc.row][nLoc.col] = 1;
			}
		}
	}
};

AntManager::~AntManager() {
}
