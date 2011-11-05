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
		static AntManager* _instance;

	public:
		AntManager(State* inState);
//		static AntManager *instance();

		//setup is always a pain ;)

		/**
		 * returns a reference to the smart pointer in the given location
		 */
		AntPtr& getAnt(Location inLoc);

		void ensureAnt(Location inLoc);
		void remove(AntPtr inAnt);
		void remove(Location inLoc);
		void makeMove(Location fromLoc, int direction);
		AntSet* getAnts();

		/**
		 * is invoked at the beginning of every turn, after the situation has been parsed, before making any move
		 */
		void nextTurn(int moveNo);

		//TODO and Buckets and the accessors

		virtual ~AntManager();
};

#endif /* ANTMANAGER_H_ */
