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
#include <vector>

#define BUCKET_VECTOR_T std::vector<Bucket<T> >

template <typename T>
class BucketMaster {
protected:
  int rows;
  int cols;
  int bucketSize;
  int xBucketCount, yBucketCount;
  int totalBucketCount;
  std::vector<T> buckets;
public:
  BucketMaster(int inRows, int inCols, int inBucketSize);
  virtual ~BucketMaster();
};

#endif /* BUCKETMASTER_H_ */
