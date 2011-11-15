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

AntListPtr AntBucketMaster::getClosestAntsFromSingleAutoBucket(Location inLoc, int max_count){
  return getClosestAntsFromSingleBucket(inLoc, getBucket(inLoc), max_count);

}
  //this list will have the closest Ants at the end
AntListPtr AntBucketMaster::getClosestAntsFromSingleBucket(Location inLoc, const AntBucket& inBucket, int max_count) {
  //this list will have the closest Ants at the end
  AntListPtr retList = AntListPtr(new AntList());
  AntBucket::iterator it;

  for(it = inBucket.begin(); it != inBucket.end(); it++){
    AntPtr currentAnt = *it;
    AntList::iterator lit;
    lit = retList->begin();
    while(lit != retList->end()){
      //this has to be internal so that we don't get nullpointer problems
      //if the expressions are evaluated in a different order than provided
      if (currentAnt->getLocation().taxiDistance(inLoc, cols, rows)
                                                  <
                            (*lit)->getLocation().taxiDistance(inLoc, cols, rows)){
        lit++;
      }else{
        break;
      }
    }

    retList->insert(lit, currentAnt);

    //removing all the
    while(retList->size() > max_count){
      retList->pop_front();
    }
  }
  return retList;
}



AntListPtr AntBucketMaster::getClosestAnts(Location inLoc, int max_count) {
  //TODO: I guess merging and sorting multiple lists when searching multiple Buckets is reasonable
  AntBucket& midBucket = getBucket(inLoc);
  AntListPtr retList = getClosestAntsFromSingleBucket(inLoc, midBucket , max_count);
  if(retList->size() >= max_count){
    return retList;
  }

  AntBucket& curBucket = midBucket;
  //we we need some more Ants
  int sidelen = 1;
  const int loop_directions[4] = {SOUTH_EAST, SOUTH_WEST, NORTH_WEST, NORTH_EAST};
  while (retList->size() < max_count){
    curBucket = getNeighbouringBucket(curBucket, NORTH);

    for(int dirno=0; dirno < 4; dirno++){
      for(int step=1; step <= sidelen; step++){
        curBucket = getNeighbouringBucket(curBucket, loop_directions[dirno]);
        AntListPtr tmpList = getClosestAntsFromSingleBucket(inLoc, curBucket, max_count); //potential optimisation in max_bucket manipulation
        retList->merge(*tmpList);
      }
    }
    sidelen++;
  }

  //TODO: sort
  //retList->sort();
  //FIXME: the comparator should be a functor. Problem solved. C++ rox.
  //how about a nice while loop with an increasing counter with a tiny special case for the inLoc Bucket itself?
}


void AntBucketMaster::addAnt(Location inLoc, AntPtr inAnt) {
  AntBucket& b = getBucket(inLoc);
  b.add(inAnt);
}




