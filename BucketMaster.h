/*
 * BucketMaster.h
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */

#ifndef BUCKETMASTER_H_
#define BUCKETMASTER_H_

#include <boost/shared_ptr.hpp>
#include "Bucket.h"

template <typename T>
class BucketMaster {
protected:
  int rows;
  int cols;
  int bucketSize;
public:
  BucketMaster(int inRows, int inCols, int inBucketSize);
  virtual ~BucketMaster();
};

#endif /* BUCKETMASTER_H_ */
