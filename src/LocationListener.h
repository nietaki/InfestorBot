/*
 * LocationListener.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef LOCATIONLISTENER_H_
#define LOCATIONLISTENER_H_
#include "Locator.h"

using namespace std;

class Locator; //forward declaration

class LocationListener {
	public:
		LocationListener();
		virtual ~LocationListener();
		virtual int changedLocation(Locator* inBucketable, Location from, Location to);
};


#endif /* LOCATIONLISTENER_H_ */
