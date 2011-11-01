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
	Square antSquare = Helper::getSquare(gridPtr, inAnt->getLocation());
	antSquare.antPtr = inAnt;
	ants.insert(inAnt);
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
	ants.erase(inAnt);

	Square antSquare = Helper::getSquare(gridPtr, inAnt->getLocation());
	antSquare.antPtr.reset();
}

Grid *AntManager::getGrid() {
	return gridPtr;
}

void AntManager::nextTurn(int moveNo) {
}

AntManager::~AntManager() {
}
