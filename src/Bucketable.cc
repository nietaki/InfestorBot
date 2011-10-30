/*
 * Bucketable.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "Bucketable.h"

using namespace std;

Bucketable::Bucketable() {

}

Bucketable::~Bucketable() {
	//no need to destroy the Buckets, they will be destroyed by sbd else
}

void Bucketable::setLocation(Location inLocation)
{
	Location from, to;
	from = loc;
	loc = inLocation;
	notifyListeners(from);
}

Location Bucketable::getLocation() {
	return loc;
}

bool Bucketable::addLocationListener(BucketableLocationListener *inListener) {
	return locationListeners.insert(inListener).second;
}

bool Bucketable::removeLocationListener(BucketableLocationListener *inListener) {
	return (locationListeners.erase(inListener) != 0);
}

/*
 * the "to" location is the current location already
 */
void Bucketable::notifyListeners(Location from)
{
	set<BucketableLocationListener*>::iterator it;
	for(it = locationListeners.begin(); it != locationListeners.end(); it++){
		(*it)->changedLocation(this, from, this->getLocation());
	}
}







