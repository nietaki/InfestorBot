/*
 * Ant.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "Ant.h"

Ant::Ant() : kill_count(0), owner(-1) {
	kill_count = 0;
	owner = -1;
}

//before Ant is complete you have to set the location
Ant::Ant(int inOwner) : kill_count(0), owner(inOwner)  {
}

Ant::~Ant() {
}

int Ant::getOwner() {
	return owner;
}

void Ant::setOwner(int playerNo) {
	owner = playerNo;
}

bool Ant::isMine() {
	return (owner == Ant::OWNER_ME);
}


