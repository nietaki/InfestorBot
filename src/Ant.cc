/*
 * Ant.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "Ant.h"

Ant::Ant() : kill_count(0), owner(-1) {
	locator = AntLocatorPtr(new Locator<Ant>(this));
//	= new Locator<Ant>;

}

//before Ant is complete you have to set the location
Ant::Ant(int inOwner) : kill_count(0), owner(inOwner) {
	locator = AntLocatorPtr(new Locator<Ant>(this));
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

void Ant::setLocation(Location inLocation) {
	locator->setLocation(inLocation);
}



Location Ant::getLocation() {
	return locator->getLocation();
}

Locator<Ant>& Ant::getLocator() {
	return *locator;
}






