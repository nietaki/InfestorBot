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
  //this list will have the closest Ants at the end
  AntListPtr list = AntListPtr(new AntList());
  AntBucket& bucket = getBucket(inLoc);
  AntBucket::iterator it;

  for(it = bucket.begin(); it != bucket.end(); it++){
    AntPtr currentAnt = *it;
    AntList::iterator lit;
    lit = list->begin();
    while(lit != list->end()){
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


    list->insert(lit, currentAnt);

    //removing all the
    while(list->size() > max_count){
      list->pop_front();
    }

    //TODO: I guess merging and sorting multiple lists when searching multiple Buckets is reasonable
  }



  return list;
}

void AntBucketMaster::addAnt(Location inLoc, AntPtr inAnt) {
  AntBucket& b = getBucket(inLoc);
  b.add(inAnt);
}




