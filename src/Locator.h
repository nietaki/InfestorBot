/*
 * Locator.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef LOCATOR_H_
#define LOCATOR_H_

#include "Location.h"
#include "LocationListener.h"
#include <set>

class LocationListener;

class Locator {
	private:
		Location loc;
		std::set<LocationListener*> locationListeners;
	public:
		Locator();
		virtual ~Locator();
		Location getLocation();
		void setLocation(Location inLocation);

		/* location listeners */

		bool addListener(LocationListener* inListener);
		bool removeListener(LocationListener* inListener);

	private:
		void notifyListeners(Location from);

};

#endif /* LOCATOR_H_ */
