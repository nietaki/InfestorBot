/*
 * LocationListener.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "Location.h"
#include "LocationListener.h"
#include "NotImplementedException.h"

LocationListener::LocationListener() {

}

LocationListener::~LocationListener() {



}

int LocationListener::changedLocation(Locator *inBucketable, Location from, Location to){
	throw NotImplementedException();
}


