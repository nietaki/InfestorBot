/*
 * AntManager.cc
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#include "AntManager.h"

boost::shared_ptr<AntManager> AntManager::_instance;

AntManager::AntManager() {

}

AntManager AntManager::instance() {
	if(AntManager::_instance){
		//this in fact is the idiom used with shared_ptr
		boost::shared_ptr<AntManager> tmp(new AntManager());
		AntManager::_instance = tmp;
	}
}

AntSet & AntManager::getMovedAnts() {
	return movedAnts;
}

AntSet & AntManager::getWaitingAnts() {
	return waitingAnts;
}

void AntManager::add(boost::shared_ptr<Ant> inAnt) {

	//TODO adding to waitingAnts
}

void AntManager::setGrid(Grid *inGrid) {
	gridPtr = inGrid;
}


void AntManager::remove(boost::shared_ptr<Ant> inAnt) {
	//TODO removing an ant;
}

Grid & AntManager::getGrid() {
	return *gridPtr;
}

void AntManager::nextMove() {
	//TODO rotating the moved ants and waiting ants
}

AntManager::~AntManager() {
}
