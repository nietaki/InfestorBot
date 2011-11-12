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

//TODO check this test
AntListPtr AntBucketMaster::getClosestAntsFromSingleBucket(Location inLoc, int max_count) {
  //this list will have the closest Ants at the end
  AntListPtr list = AntListPtr(new AntList());
  AntBucket& bucket = getBucket(inLoc);
  AntBucket::iterator it;

  for(it = bucket.begin(); it != bucket.end(); it++){
    AntPtr currentAnt = *it;
    AntList::iterator lit;
    lit = list->begin();
    while(lit != list->end() && currentAnt->getLocation().taxiDistance(inLoc, cols, rows)
                                                  <
                            (*lit)->getLocation().taxiDistance(inLoc, cols, rows)){
      lit++;
    }


    list->insert(lit, currentAnt);

    while(list->size() > max_count){
      list->pop_front();
    }
  }



  return list;
}


