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
#include "Location.h"
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
  std::vector<Bucket<T> > buckets;
public:
  BucketMaster(int inRows, int inCols, int inBucketSize):
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
      it->bucketNo = i;
      i++;
                        //they need to know their number I guess
                        //or do they? :S
    }

  }
  virtual ~BucketMaster(){

  }

  int getBucketCount(){
    return buckets.size();
  }

  int getXBucketCount(){
    return xBucketCount;
  }

  int getYBucketCount(){
    return yBucketCount;
  }

  int getBucketX(const Location& inLoc){
    return inLoc.col / bucketSize;
  }

  int getBucketY(const Location& inLoc){
    return inLoc.row / bucketSize;
  }


  int getBucketNo(const Location& inLoc){
    inLoc.dieIfOutOfBounds(rows, cols, "BucketMaster.getBucketNo()");
    int y = getBucketY(inLoc);
    int x = getBucketX(inLoc);

    int bucketNo = y*xBucketCount + x;

  }

  Bucket<T>& getBucket(const Location& inLoc){
    return buckets[getBucketNo(inLoc)];
  }

  int getBucketNoByXY(int x, int y){
    return xBucketCount * y + x;
  }

  int getXByNo(int no){
    return no % xBucketCount;
  }

  int getYByNo(int no){
    return no / xBucketCount;
  }

  int getNeighbouringBucketNoByXY(int X, int Y, int dir){

    int destX = (X + DIRECTIONS[dir][1]);
    destX = (destX + xBucketCount) % xBucketCount;
    int destY = (Y + DIRECTIONS[dir][0]);
    destY = (destY + yBucketCount) % yBucketCount;

    return getBucketNoByXY(destX, destY);
  }

};

#endif /* BUCKETMASTER_H_ */
