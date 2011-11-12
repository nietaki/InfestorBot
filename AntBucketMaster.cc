/*
 * AntBucketMaster.cc
 *
 *  Created on: Nov 12, 2011
 *      Author: nietaki
 */

#include "AntBucketMaster.h"


AntBucketMaster::AntBucketMaster(int inRows, int inCols, int inBucketSize) :
                BucketMaster<boost::shared_ptr<Ant> >( inRows,  inCols,  inBucketSize){

}

AntBucketMaster::~AntBucketMaster() {

}

AntListPtr AntBucketMaster::getClosestAntsFromSingleBucket(Location inLoc, int max_count) {
  AntListPtr list = AntListPtr(new AntList());


  return list;
}


