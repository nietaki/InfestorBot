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
  Location l = Location(5, 54);
  int added = manager->ensureAnt(l);
  EXPECT_EQ(added, AntManager::SUCCESS);
  AntPtr gotAnt = manager->getAnt(l);
  ASSERT_TRUE(gotAnt) << "didn't get the placed ant";
}

TEST_F(AntManagerTest, ShouldRespectfullyDeclineAntOutOfRangeInEnsureAnt) {
  int added = manager->ensureAnt(Location(1000, 54));
  EXPECT_EQ(AntManager::ANT_LOCATION_INVALID, added);
}

TEST_F(AntManagerTest, ShouldEndureRemovingAbsentAntByLocation) {
  Location location = Location(4, 54);
  manager->ensureAnt(location);
  int removed = manager->removeAnt(Location(5, 54));
  EXPECT_EQ(AntManager::ANT_ABSENT, removed);
}

TEST_F(AntManagerTest, ShouldEndureRemoveAntByLocation) {
  Location location = Location(4, 54);
  manager->ensureAnt(location);
  int removed = manager->removeAnt(location);
  EXPECT_EQ(AntManager::SUCCESS, removed);
}

TEST_F(AntManagerTest, ShouldEndureRemoveAntByPtr) {
  Location location = Location(4, 54);
  manager->ensureAnt(location);
  AntPtr ptr = manager->getAnt(location);
  int removed = manager->removeAnt(ptr);
  EXPECT_EQ(AntManager::SUCCESS, removed);
}

TEST_F(AntManagerTest, ShouldEndureRemovingAbsentAntByPtr) {
  Location location = Location(4, 54);
  manager->ensureAnt(location);
  AntPtr ptr = manager->getAnt(location);
  int removed1 = manager->removeAnt(ptr);
  int removed2 = manager->removeAnt(ptr);
  EXPECT_EQ(AntManager::ANT_ABSENT, removed2);
}

TEST_F(AntManagerTest, ShouldEndureRemovingAntFromWrongLocation) {
  Location location = Location(1000, 54);
  int removed = manager->removeAnt(location);
  EXPECT_EQ(AntManager::ANT_LOCATION_INVALID, removed);
}

TEST_F(AntManagerTest, ShouldGetEmptyNonExistantAnt) {
  Location location = Location(10, 54);
  AntPtr ptr = manager->getAnt(location);
  EXPECT_FALSE(ptr);
}

TEST_F(AntManagerTest, ShouldMakeCorrectAntMove) {
  Location location = Location(10, 54);
  int ensured = manager->ensureAnt(location);
  int moved = manager->makeMove(location, NORTH);
  EXPECT_EQ(AntManager::SUCCESS, moved);
}

TEST_F(AntManagerTest, ShouldEndureMovingInexistentAnt) {
  Location location = Location(10, 54);
  int moved = manager->makeMove(location, NORTH);
  EXPECT_EQ(AntManager::ANT_ABSENT, moved);
}

TEST_F(AntManagerTest, ShouldEndureMovingInAWrongDirection) {
  Location location = Location(10, 54);
  int ensured = manager->ensureAnt(location);
  int moved = manager->makeMove(location, 4);
  EXPECT_EQ(AntManager::DIRECTION_INVALID, moved);
}

TEST_F(AntManagerTest, ShouldEndureMovingToWater) {
//  for(int i=0; i<state->rows; i++){
//    for(int j=0; j<state->cols; j++){
//        state->grid[i][j].isWater = true;
//    }
//  }

  state->grid[5][5].isWater = true;
  Location location = Location(4, 5);
  int ensured = manager->ensureAnt(location);
  int moved = manager->makeMove(location, SOUTH);
  EXPECT_EQ(AntManager::TARGET_LOCATION_INACCESSIBLE, moved);
}

TEST_F(AntManagerTest, ShouldNotMoveOnAnotherAnt) {

  Location location = Location(4, 5);
  Location location2 = Location(5, 5);
  manager->ensureAnt(location);
  manager->ensureAnt(location2);
  int moved = manager->makeMove(location, SOUTH);
  EXPECT_EQ(AntManager::TARGET_LOCATION_OCCUPIED, moved);
}









