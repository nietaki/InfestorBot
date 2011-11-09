/*
 * AntManager.h
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#ifndef ANTMANAGER_H_
#define ANTMANAGER_H_

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <set>
#include <vector>

#include "Ant.h"
#include "Square.h"
#include "State.h"
#include "Bugger.h"

class State;

class AntManager {

	private:
		AntSet ants;
		Bug* bug;
		State* state;
		AntGrid antGrid;

	public:
		static const int ANT_PRESENT = 5;
		static const int ANT_ABSENT = 4;
		static const int ANT_LOCATION_INVALID = 7;
		static const int DIRECTION_INVALID = 8;
		static const int TARGET_LOCATION_INACCESSIBLE = 9;
		static const int SUCCESS = 0;

		AntManager(State* inState);
		/**
		 * returns a reference to the smart pointer in the given location
		 */
		AntPtr getAnt(Location inLoc);
		AntPtr& getAntRef(Location inLoc);

		int ensureAnt(Location inLoc);
		int removeAnt(AntPtr inAnt);
		int removeAnt(Location inLoc);
		int makeMove(Location fromLoc, int direction);
		AntSet* getAnts();

		/**
		 * is invoked at the beginning of every turn, after the situation has been parsed, before making any move
		 */
		int nextTurn(int moveNo);

		//TODO and Buckets and the accessors

		virtual ~AntManager();
};

#endif /* ANTMANAGER_H_ */
