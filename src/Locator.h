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

template <typename U>
class LocationListener;

template <typename T>
class Locator {
	private:
		T* tracked_item;
		Location loc;

		std::set<LocationListener<T>*>  locationListeners;
	public:
		Locator(T* inTrackedItem) : tracked_item(inTrackedItem) {

		}
		virtual ~Locator(){
			//TODO unregister any listeners? if not, copy the inscription to the listener
		}
		Location getLocation(){
			return loc;
		}
		void setLocation(Location inLocation){
			Location from, to;
			from = loc;
			loc = inLocation;
			notifyListeners(from);
		}
		/* location listeners */

		bool addListener(LocationListener<T>* inListener){
			return locationListeners.insert(inListener).second;
		}

		bool removeListener(LocationListener<T>* inListener){
			return (locationListeners.erase(inListener) != 0);
		}

	protected:
		/*
		 * the "to" location is the current location already
		 */


		void notifyListeners(Location from){

			typename std::set<LocationListener < T > * > ::iterator  it;
			for(it = locationListeners.begin(); it != locationListeners.end(); it++){
				(*it)->changedLocation(tracked_item, from, getLocation());
			}
		}

};

#endif /* LOCATOR_H_ */