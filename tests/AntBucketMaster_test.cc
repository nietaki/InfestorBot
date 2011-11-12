/*
 * BucketMaster_test.cc
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */

#include "gtest/gtest.h"
#include "AntBucketMaster.h"

class AntBucketMasterShould : public testing::Test {

  protected:

  virtual void SetUp() {

  }


   virtual void TearDown() {
   }

};

TEST_F(AntBucketMasterShould, ConstructCorrectly) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
}

TEST_F(AntBucketMasterShould, ReturnEmptyClosestList) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
  AntListPtr abp = abm.getClosestAntsFromSingleBucket(Location(5, 5), 10);

  EXPECT_TRUE( abp->empty() );
}
