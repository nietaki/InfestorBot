/*
 * Ant.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "Ant.h"
#include "State.h"




//before Ant is complete you have to set the location
Ant::Ant(int inOwner, Location startingLocation) : owner(inOwner), kill_count(0), location(startingLocation) {
	last_turn_moved = 0;
}

Ant::~Ant() {
	(* Bugger::getBug()) << "an Ant destroyed";
}

int Ant::getOwner() const {
	return owner;
}

void Ant::setOwner(int playerNo) {
	owner = playerNo;
}

bool Ant::isMine() const {
	return (owner == Ant::OWNER_ME);
}

boost::shared_ptr<Ant> Ant::makeAnt(int inOwner, Location startingLocation) {
	boost::shared_ptr<Ant> newAnt (new Ant(inOwner, startingLocation));
	return newAnt;
}



bool Ant::hasMovedOn(int turnNo) const {
	return (last_turn_moved >= turnNo);
}

void Ant::setLocation(Location inLocation) {
	location = inLocation;
}



Location Ant::getLocation() const {
	return location;
}








