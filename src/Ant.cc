/*
 * Ant.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include <boost/weak_ptr.hpp>
//#include <boost/e>
#include "Ant.h"
#include "Helper.h"




//before Ant is complete you have to set the location
Ant::Ant(int inOwner, Location startingLocation) : owner(inOwner), kill_count(0), location(startingLocation) {
	last_turn_moved = 0;
}

Ant::~Ant() {
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



bool Ant::hasMoved() const {
	return (last_turn_moved >= Helper::getTurnNo());
}

void Ant::setLocation(Location inLocation) {
	location = inLocation;
}



Location Ant::getLocation() const {
	return location;
}








