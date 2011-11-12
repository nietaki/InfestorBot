#include "Location.h"
#include "gtest/gtest.h"

// To use a test fixture, derive a class from testing::Test.
class LocationTest : public testing::Test {
 protected:
//  Queue<int> q0_;
//  Queue<int> q1_;

  Location l;
  // virtual void SetUp() will be called before each test is run.  You
  // should define it if you need to initialize the varaibles.
  // Otherwise, this can be skipped.
  virtual void SetUp() {
//    q1_.Enqueue(1);
//    q2_.Enqueue(2);
//    q2_.Enqueue(3);
  }

  // virtual void TearDown() will be called after each test is run.
  // You should define it if there is cleanup work to do.  Otherwise,
  // you don't have to provide it.
  //
   virtual void TearDown() {
   }

};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the default c'tor.
TEST_F(LocationTest, DefaultConstructor) {
  EXPECT_EQ(0, 0);
}

TEST_F(LocationTest, ShouldReturnCorrectDistanceInTrivialCase){

  Location la(2, 2);
  Location lb(2, 3);
  Location l1(5, 3);
  Location l2(2, 9);
  EXPECT_EQ(1, la.taxiDistance(lb, 100, 100));
  EXPECT_EQ(9, l1.taxiDistance(l2, 100, 100));
  EXPECT_EQ(9, l2.taxiDistance(l1, 100, 100));

}

TEST_F(LocationTest, ShouldReturnCorrectDistanceInNonTrivialCase){

  Location l1(4, 2);
  Location l2(2, 9);
  EXPECT_EQ(5, l1.taxiDistance(l2, 10, 10));
  EXPECT_EQ(5, l2.taxiDistance(l1, 10, 10));

}
