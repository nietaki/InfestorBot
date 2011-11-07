#include "Location.h"
#include "gtest/gtest.h"

// To use a test fixture, derive a class from testing::Test.
class QueueTest : public testing::Test {
 protected:
//  Queue<int> q0_;
//  Queue<int> q1_;
//  Queue<int> q2_;

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
TEST_F(QueueTest, DefaultConstructor) {
  // You can access data in the test fixture here.
  EXPECT_EQ(0, 0);
}
