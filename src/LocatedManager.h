/*
 * LocatedManager.h
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#ifndef LOCATEDMANAGER_H_
#define LOCATEDMANAGER_H_

#include <set>
#include "LocationListener.h"

template <typename T>
class LocatedManager : public LocationListener<T> {
	protected:
		T member;
	public:
		LocatedManager() {

		}

		virtual ~LocatedManager() {

		}
};

#endif /* LOCATEDMANAGER_H_ */
