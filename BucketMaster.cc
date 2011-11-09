/*
 * BucketMaster.cc
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */

#include "BucketMaster.h"

template<typename T>
BucketMaster<T>::BucketMaster(int inRows, int inCols, int inBucketSize):
                              rows(inRows),
                              cols(inCols),
                              bucketSize(inBucketSize){
  yBucketCount = rows/bucketSize;
  if(rows % bucketSize){
    yBucketCount++;
  }

  xBucketCount = cols/bucketSize;
  if(cols % bucketSize){
    xBucketCount++;
  }

  totalBucketCount = xBucketCount * yBucketCount;

  buckets = std::vector<Bucket<T> > (totalBucketCount, Bucket<T>(0));
  int i = 0;
  typename BUCKET_VECTOR_T::iterator it; //fucking typename
  for(it = buckets.begin(); it != buckets.end(); it++){
    it->bucketNo = i; //they need to know their number I guess
  }

}

template<typename T>
BucketMaster<T>::~BucketMaster() {
}

