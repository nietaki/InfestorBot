#include "gtest/gtest.h"
#include "State.h"
#include "AntManager.h"

// To use a test fixture, derive a class from testing::Test.
class AntManagerTest : public testing::Test {
  protected:
    State* state;
    AntManager* manager;
  // virtual void SetUp() will be called before each test is run.  You
  // should define it if you need to initialize the varaibles.
  // Otherwise, this can be skipped.
  virtual void SetUp() {
    state = State::getSampleState(25, 100);
  }

  // virtual void TearDown() will be called after each test is run.
  // You should define it if there is cleanup work to do.  Otherwise,
  // you don't have to provide it.
  //
   virtual void TearDown() {
     delete state;
     delete manager;
   }

};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the default c'tor.
TEST_F(AntManagerTest, DefaultConstructor) {
  // You can access data in the test fixture here.
  EXPECT_EQ(0, 0);
}
