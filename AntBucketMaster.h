/*
 * AntBucketMaster.h
 *
 *  Created on: Nov 12, 2011
 *      Author: nietaki
 */

#ifndef ANTBUCKETMASTER_H_
#define ANTBUCKETMASTER_H_

#include <boost/shared_ptr.hpp>
#include "BucketMaster.h"
#include "Ant.h"

class AntBucketMaster : public BucketMaster<boost::shared_ptr<Ant> > {
  public:
    AntBucketMaster(int inRows, int inCols, int inBucketSize);
    virtual ~AntBucketMaster();
};

#endif /* ANTBUCKETMASTER_H_ */
