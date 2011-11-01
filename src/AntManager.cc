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

AntSet *AntManager::getMovedAnts() {
	return &movedAnts;
}

AntSet *AntManager::getWaitingAnts() {
	return &waitingAnts;
}

void AntManager::add(AntPtr inAnt) {
	waitingAnts.insert(inAnt);
	//TODO (*gridPtr)[0][0].antPtr = inAnt;

	//TODO adding to waitingAnts
}

void AntManager::setGrid(Grid *inGrid) {
	gridPtr = inGrid;
}


void AntManager::remove(AntPtr inAnt) {
	//TODO removing an ant;
}

Grid *AntManager::getGrid() {
	return gridPtr;
}

void AntManager::nextMove() {
	//TODO rotating the moved ants and waiting ants
}

AntManager::~AntManager() {
}
