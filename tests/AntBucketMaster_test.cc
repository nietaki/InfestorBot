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
  AntListPtr abp = abm.getClosestAntsFromSingleAutoBucket(Location(5, 5), 10);

  EXPECT_TRUE( abp->empty() );
}

TEST_F(AntBucketMasterShould, AddAndReturnAntByLocation) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
  Location antLocation(15,15);
  AntPtr ap = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation, ap);

  AntListPtr alp = abm.getClosestAntsFromSingleAutoBucket(Location(15, 14), 1);

  EXPECT_EQ(ap, (*alp->begin()) );
}

TEST_F(AntBucketMasterShould, ReturnOneAntByLocationWhenNoMoreAvailable) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
  Location antLocation(15,15);
  AntPtr ap = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation, ap);

  AntListPtr alp = abm.getClosestAntsFromSingleAutoBucket(Location(15, 14), 10);

  EXPECT_EQ(ap, (*alp->begin()) );
  EXPECT_EQ(1, alp->size() );
}

TEST_F(AntBucketMasterShould, ReturnAllAntsByLocationWhenNoMoreAvailable) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
  Location antLocation(15,15);
  AntPtr ap = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation, ap);

  Location antLocation2(16,16);
  AntPtr ap2 = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation2, ap2);

  AntListPtr alp = abm.getClosestAntsFromSingleAutoBucket(Location(15, 14), 10);

  EXPECT_EQ(2, alp->size() );
}

TEST_F(AntBucketMasterShould, ReturnNoMoreThanTheRequiredAmountOfAnts) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
  Location antLocation(15,15);
  AntPtr ap = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation, ap);

  Location antLocation2(16,16);
  AntPtr ap2 = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation2, ap2);

  Location antLocation3(17,17);
  AntPtr ap3 = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation3, ap3);

  AntListPtr alp = abm.getClosestAntsFromSingleAutoBucket(Location(15, 14), 2);

  EXPECT_EQ(2, alp->size() );
}

TEST_F(AntBucketMasterShould, ShouldReturnSortedAnts) {
  AntBucketMaster abm = AntBucketMaster(100, 100, 10);
  Location antLocation(15,15);
  AntPtr ap = Ant::makeAnt(0, antLocation);
  abm.addAnt(antLocation, ap);

  Location antLocation2(16,16);
  AntPtr ap2 = Ant::makeAnt(0, antLocation2);
  abm.addAnt(antLocation2, ap2);

  Location antLocation3(17,17);
  AntPtr ap3 = Ant::makeAnt(0, antLocation3);
  abm.addAnt(antLocation3, ap3);

  Location target = Location(15, 14);
  AntListPtr alp = abm.getClosestAntsFromSingleAutoBucket(target, 3);
  AntPtr first, second, third;
  first = alp->front();
  alp->pop_front();
  second = alp->front();
  alp->pop_front();
  third = alp->front();
  /**
   *     <3 SŁONKO
   *
   *     ^\_(^^,)_/^
   *
   *    d-_-b
   *
   */
  EXPECT_EQ(1, target.taxiDistance(third->getLocation(), 100, 100));
  EXPECT_EQ(3, target.taxiDistance(second->getLocation(), 100, 100));
  EXPECT_EQ(5, target.taxiDistance(first->getLocation(), 100, 100));
  EXPECT_TRUE(target.taxiDistance(first->getLocation(), 100, 100)
                        >
              target.taxiDistance(second->getLocation(), 100, 100));
  EXPECT_TRUE(target.taxiDistance(second->getLocation(), 100, 100)
                        >
              target.taxiDistance(third->getLocation(), 100, 100));
}


