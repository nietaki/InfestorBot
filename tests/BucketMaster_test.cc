/*
 * BucketMaster_test.cc
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */

#include "gtest/gtest.h"
#include "BucketMaster.h"

class BucketMasterShould : public testing::Test {

  protected:

  virtual void SetUp() {

  }


   virtual void TearDown() {
   }

};

TEST_F(BucketMasterShould, ConstructCorrectly) {
  BucketMaster<int> bm = BucketMaster<int>(50, 100, 10);
}

TEST_F(BucketMasterShould, HaveTheRightBucketCountWhenDivisible) {
  BucketMaster<int> bm = BucketMaster<int>(50, 100, 10);
  EXPECT_EQ(5, bm.getYBucketCount());
  EXPECT_EQ(10, bm.getXBucketCount());
  EXPECT_EQ(50, bm.getBucketCount());
}

TEST_F(BucketMasterShould, HaveTheRightBucketCountWhenIndivisible) {
  BucketMaster<int> bm = BucketMaster<int>(59, 101, 10);
  EXPECT_EQ(6, bm.getYBucketCount());
  EXPECT_EQ(11, bm.getXBucketCount());
  EXPECT_EQ(66, bm.getBucketCount());
}

TEST_F(BucketMasterShould, ReturnCorrectBucketNoInTrivialCase) {
  BucketMaster<int> bm = BucketMaster<int>(59, 101, 10);

  EXPECT_EQ(0, bm.getBucketNo(Location(2, 2)));
  EXPECT_EQ(2, bm.getBucketNo(Location(4, 23)));
  EXPECT_EQ(25, bm.getBucketNo(Location(24, 35))); //11*2 + 4 - 1
}

TEST_F(BucketMasterShould, ReturnCorrectBucketNoInNonTrivialCase) {
  BucketMaster<int> bm = BucketMaster<int>(59, 101, 10);

  ASSERT_EQ(0, bm.getBucketNo(Location(0, 0)));
  EXPECT_EQ(0, bm.getBucketNo(Location(9, 9)));
  EXPECT_EQ(1, bm.getBucketNo(Location(9, 10)));
  EXPECT_EQ(65, bm.getBucketNo(Location(58, 100)));
}

TEST_F(BucketMasterShould, ReturnCorrectBucket) {
  BucketMaster<int> bm = BucketMaster<int>(59, 101, 10);
  Bucket<int>& b = bm.getBucket(Location(4, 23));
  EXPECT_EQ(2, b.getBucketNo());
}

TEST_F(BucketMasterShould, DieOnOutOfBoundsBucketLocation) {
  BucketMaster<int> bm = BucketMaster<int>(59, 101, 10);

  ASSERT_DEATH(bm.getBucketNo(Location(61, 2)), "") << "BucketMaster should always receive normalized locations";
}

TEST_F(BucketMasterShould, ReturnCorrectBucketNoByXY) {
  BucketMaster<int> bm = BucketMaster<int>(50, 100, 10);

  EXPECT_EQ(0, bm.getBucketNoByXY(0, 0));
  EXPECT_EQ(13, bm.getBucketNoByXY(3, 1));

}

TEST_F(BucketMasterShould, GetXYByNo) {
  BucketMaster<int> bm = BucketMaster<int>(100, 100, 10);

  int no = 23;
  EXPECT_EQ(2, bm.getYByNo(no));
  EXPECT_EQ(3, bm.getXByNo(no));

}

TEST_F(BucketMasterShould, GetTrivialNeighbouringBucketNo) {
  BucketMaster<int> bm = BucketMaster<int>(100, 100, 10);
  int startingBucketNo = 33;
  EXPECT_EQ(23, bm.getNeighbouringBucketNoByXY(3, 3, NORTH));
  EXPECT_EQ(24, bm.getNeighbouringBucketNoByXY(3, 3, NORTH_EAST));
  EXPECT_EQ(34, bm.getNeighbouringBucketNoByXY(3, 3, EAST));
  EXPECT_EQ(44, bm.getNeighbouringBucketNoByXY(3, 3, SOUTH_EAST));
  EXPECT_EQ(43, bm.getNeighbouringBucketNoByXY(3, 3, SOUTH));
  EXPECT_EQ(42, bm.getNeighbouringBucketNoByXY(3, 3, SOUTH_WEST));
  EXPECT_EQ(32, bm.getNeighbouringBucketNoByXY(3, 3, WEST));
  EXPECT_EQ(22, bm.getNeighbouringBucketNoByXY(3, 3, NORTH_WEST));

}


TEST_F(BucketMasterShould, GetOverflowNeighbouringBucketNo) {
  BucketMaster<int> bm = BucketMaster<int>(100, 100, 10);
  int startingBucketNo = 33;
  EXPECT_EQ(4, bm.getNeighbouringBucketNoByXY(4, 9, SOUTH));
  EXPECT_EQ(40, bm.getNeighbouringBucketNoByXY(9, 4, EAST));

}

TEST_F(BucketMasterShould, GetUnderflowNeighbouringBucketNo) {
  BucketMaster<int> bm = BucketMaster<int>(100, 100, 10);
  int startingBucketNo = 33;
  EXPECT_EQ(94, bm.getNeighbouringBucketNoByXY(4, 0, NORTH));
  EXPECT_EQ(49, bm.getNeighbouringBucketNoByXY(0, 4, WEST));

}
