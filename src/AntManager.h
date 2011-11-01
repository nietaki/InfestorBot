/*
 * AntManager.h
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#ifndef ANTMANAGER_H_
#define ANTMANAGER_H_

#include <boost/shared_ptr.hpp>
#include <set>
#include <vector>

#include "Ant.h"
#include "Square.h"


typedef std::set<boost::shared_ptr<Ant> > AntSet;

class AntManager {

	private:
		AntManager();
		AntSet ants;
		Grid* gridPtr;

		static AntManager* _instance;



	public:

		static AntManager *instance();

		//setup is always a pain ;)
		void setGrid(Grid *inGrid);

		void add(AntPtr inAnt);
		void remove(AntPtr inAnt);
		void remove(Location inLocation);

		void makeMove(Location fromLocation, int direction);
		Grid* getGrid();
		AntSet* getAnts();

		/**
		 * is invoked at the beginning of every turn, after the situation has been parsed, before making any move
		 */
		void nextTurn(int moveNo);

		//TODO and Buckets and the accessors

		virtual ~AntManager();
};

#endif /* ANTMANAGER_H_ */
