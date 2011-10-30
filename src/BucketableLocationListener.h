/*
 * BucketableLocationListener.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef BUCKETABLELOCATIONLISTENER_H_
#define BUCKETABLELOCATIONLISTENER_H_
#include "Bucketable.h"

using namespace std;

class Bucketable; //forward declaration

class BucketableLocationListener {
	public:
		BucketableLocationListener();
		virtual ~BucketableLocationListener();
		virtual int changedLocation(Bucketable* inBucketable, Location from, Location to);
};


#endif /* BUCKETABLELOCATIONLISTENER_H_ */
