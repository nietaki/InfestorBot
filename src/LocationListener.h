/*
 * LocationListener.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef LOCATIONLISTENER_H_
#define LOCATIONLISTENER_H_

#include <boost/shared_ptr.hpp>
#include <boost/>
#include "Locator.h"
#include "Location.h"
#include "NotImplementedException.h"


using namespace std;

template <typename U>
class Locator; //forward declaration

template <typename T>
class LocationListener {
	public:
		LocationListener(){

		}
		virtual ~LocationListener(){

		}
		virtual int changedLocation(boost::weak_ptr<T> inTrackedObject, Location from, Location to){
			throw NotImplementedException();
		}
};


#endif /* LOCATIONLISTENER_H_ */
