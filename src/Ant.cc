/*
 * Ant.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include <boost/weak_ptr.hpp>
//#include <boost/e>
#include "Ant.h"



//before Ant is complete you have to set the location
Ant::Ant(int inOwner) : kill_count(0), owner(inOwner) {
//	locator = AntLocatorPtr(new Locator<Ant>(this));
	// locator is set later
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

boost::shared_ptr<Ant> Ant::makeAnt(int inOwner) {
	boost::shared_ptr<Ant> newAnt (new Ant(inOwner));

}



void Ant::setLocation(Location inLocation) {
	location = inLocation;
}



Location Ant::getLocation() const {
	return location;
}

//Locator<Ant>& Ant::getLocator() const {
//	return *locator;
//}






