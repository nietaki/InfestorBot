/*
 * AntBucketMaster.cc
 *
 *  Created on: Nov 12, 2011
 *      Author: nietaki
 */

#include "AntBucketMaster.h"

AntBucketMaster::AntBucketMaster(int inRows, int inCols, int inBucketSize) :
                BucketMaster<boost::shared_ptr<Ant> >( inRows,  inCols,  inBucketSize){
  // TODO Auto-generated constructor stub

}

AntBucketMaster::~AntBucketMaster() {
  // TODO Auto-generated destructor stub
}
