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

AntSet *AntManager::getMovedAnts() {
	return &movedAnts;
}

AntSet *AntManager::getWaitingAnts() {
	return &waitingAnts;
}

void AntManager::add(AntPtr inAnt) {
	waitingAnts.insert(inAnt);
	Square antSquare = Helper::getSquare(gridPtr, inAnt->getLocation());
	antSquare.ant = inAnt->getOwner();
	antSquare.antPtr = inAnt;
	waitingAnts.insert(inAnt);
}

void AntManager::setGrid(Grid *inGrid) {
	gridPtr = inGrid;
}


void AntManager::remove(Location inLocation){
	Square antSquare = Helper::getSquare(gridPtr, inLocation);
	if(antSquare.antPtr){
		remove(antSquare.antPtr);
	}
}

void AntManager::remove(AntPtr inAnt) {
	waitingAnts.erase(inAnt);
	movedAnts.erase(inAnt); //FIXME this shouldn't be neccessary

	Square antSquare = Helper::getSquare(gridPtr, inAnt->getLocation());
	antSquare.ant = -1;//no ant
	antSquare.antPtr.reset();
}

Grid *AntManager::getGrid() {
	return gridPtr;
}

void AntManager::nextMove(int moveNo) {
	waitingAnts.swap(movedAnts); //we probably moved most of the ants, let's make this efficient
	waitingAnts.insert(movedAnts.begin(), movedAnts.end());
	//all the ants should be waiting now;
	//TODO update the moveNo in the ants
}

AntManager::~AntManager() {
}
