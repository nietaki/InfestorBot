/*
 * Bucketable.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "Locator.h"

using namespace std;

Locator::Locator() {

}

Locator::~Locator() {
	//no need to destroy the Buckets, they will be destroyed by sbd else
}

void Locator::setLocation(Location inLocation)
{
	Location from, to;
	from = loc;
	loc = inLocation;
	notifyListeners(from);
}

Location Locator::getLocation() {
	return loc;
}

bool Locator::addListener(LocationListener *inListener) {
	return locationListeners.insert(inListener).second;
}

bool Locator::removeListener(LocationListener *inListener) {
	return (locationListeners.erase(inListener) != 0);
}

/*
 * the "to" location is the current location already
 */
void Locator::notifyListeners(Location from)
{
	set<LocationListener*>::iterator it;
	for(it = locationListeners.begin(); it != locationListeners.end(); it++){
		(*it)->changedLocation(this, from, this->getLocation());
	}
}







