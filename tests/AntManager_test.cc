#include "gtest/gtest.h"
#include "AntManager.h"
//#include "State.h"

// in the your_class_test.cc file:

/* we make one of the protected methods public for testing */
//class TestableAntManager : public AntManager {
//  public:
//    TestableAntManager(State* inState) : AntManager(inState) {
//
//    }
//
//	public: using AntManager::nextTurn; // changes access rights
//};


class AntManagerTest : public testing::Test {

  protected:
    State* state;
    AntManager* manager;

  virtual void SetUp() {
    state = State::getSampleState(25, 100);
    manager = new AntManager(state);

  }


   virtual void TearDown() {
     delete state;
     delete manager;
   }

};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the default c'tor.

TEST_F(AntManagerTest, ShouldConstructCorrectly) {

}

TEST_F(AntManagerTest, ShouldHaveEmptyWorkingState) {
  Square sq = state->getSquare(Location(3, 4));
  EXPECT_FALSE(sq.isFood);
}

TEST_F(AntManagerTest, ShouldPositivelyEnsureNewAnt) {
  int added = manager->ensureAnt(Location(5, 54));
  EXPECT_EQ(added, AntManager::SUCCESS);
}

TEST_F(AntManagerTest, ShouldRespectfullyDeclineAntOutOfRangeInEnsureAnt) {
  int added = manager->ensureAnt(Location(1000, 54));
  EXPECT_EQ(added, AntManager::ANT_LOCATION_INVALID);
}
