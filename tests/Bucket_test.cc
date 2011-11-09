/*
 * Bucket_test.cc
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */
#include "gtest/gtest.h"
#include "Bucket.h"

class BucketTest : public testing::Test {

  protected:
    Bucket<int> bucket;

  virtual void SetUp() {
    bucket = Bucket<int>();
  }

   virtual void TearDown() {

   }

};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the default c'tor.

TEST_F(BucketTest, ShouldConstructCorrectly) {
  EXPECT_EQ(0, bucket.getBucketNo());
  EXPECT_EQ(0, bucket.size());

}

TEST_F(BucketTest, ShouldReceiveItem) {
  bucket.add(1);
  EXPECT_EQ(1, bucket.size());
}

TEST_F(BucketTest, ShouldRemoveItem) {
  bucket.add(1);
  bucket.remove(1);
  EXPECT_EQ(0, bucket.size());
}


