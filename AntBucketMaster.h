/*
 * AntBucketMaster.h
 *
 *  Created on: Nov 12, 2011
 *      Author: nietaki
 */

#ifndef ANTBUCKETMASTER_H_
#define ANTBUCKETMASTER_H_

#include <list>
#include <boost/shared_ptr.hpp>
#include "BucketMaster.h"
#include "Ant.h"

typedef std::list<boost::shared_ptr<Ant> >  AntList;
typedef boost::shared_ptr<AntList> AntListPtr;
typedef Bucket<boost::shared_ptr<Ant> > AntBucket;

class AntBucketMaster : public BucketMaster<boost::shared_ptr<Ant> > {
  public:
    AntBucketMaster(int inRows, int inCols, int inBucketSize);
    virtual ~AntBucketMaster();
    AntListPtr getClosestAntsFromSingleBucket(Location inLoc, int max_count);
};

#endif /* ANTBUCKETMASTER_H_ */
