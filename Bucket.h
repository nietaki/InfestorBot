/*
 * Bucket.h
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */

#ifndef BUCKET_H_
#define BUCKET_H_

#include <list>

template <typename T>
class BucketMaster; //yes, this is also neccessary

template <typename T>
class Bucket {
    friend class BucketMaster<T>;
  protected:
    int bucketNo;
    std::list<T> itemList;
  public:
    Bucket(int no=0):bucketNo(no){

    }
    virtual ~Bucket(){

    }

    int getBucketNo(){
      return bucketNo;
    }

    void add(T newItem){
      itemList.push_front(newItem);
    }

    void remove(T removedItem){

    }

    int size(){
      return itemList.size();
    }


};





#endif /* BUCKET_H_ */
