/*
 * Bucket.h
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */

#ifndef BUCKET_H_
#define BUCKET_H_

#include <list>
#include <stdlib.h>
#include "Bugger.h"

template <typename T>
class BucketMaster; //yes, this is also neccessary

template <typename T>
class Bucket {
    friend class BucketMaster<T>;
  protected:
    int bucketNo;
    std::list<T> itemList;
    void dieIfEmpty(const char* fromName){
      if(empty()){
        (*Bugger::getBug()) << "you tried to get sth from an empty Bucket in " << fromName << std::endl;
        (*Bugger::getBug()) << "I will DIE now, mmkay?" << std::endl;
        exit(1);
      }
    }
  public:
    typedef typename std::list<T>::const_iterator iterator;
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
      itemList.remove(removedItem);
    }

    int size(){
      return itemList.size();
    }

    bool empty(){
      return itemList.empty();
    }

    T peekAny(){
      dieIfEmpty("peekAny");
      return itemList.front();
    }

    //doesn't give any guarantee, should be called only when the Bucket isn't empty()
    T popAny(){
      dieIfEmpty("popAny");
      T any = itemList.front();
      itemList.pop_front();
      return any;
    }

    //the iterator, note, this is a CONST_iterator
    iterator begin(){
      return itemList.begin();
    }

    iterator end(){
      return itemList.end();
    }
};





#endif /* BUCKET_H_ */
