/*
 * Bucketable.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef BUCKETABLE_H_
#define BUCKETABLE_H_

#include "Location.h"
#include "BucketableLocationListener.h"
#include <set>

class BucketableLocationListener;

class Bucketable {
	private:
		Location loc;
		std::set<BucketableLocationListener*> locationListeners;
	public:
		Bucketable();
		virtual ~Bucketable();
		Location getLocation();
		void setLocation(Location inLocation);

		/* location listeners */

		bool addLocationListener(BucketableLocationListener* inListener);
		bool removeLocationListener(BucketableLocationListener* inListener);

	private:
		void notifyListeners(Location from);

};

#endif /* BUCKETABLE_H_ */
