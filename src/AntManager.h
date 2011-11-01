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
		AntSet movedAnts, waitingAnts;
		Grid* gridPtr;

		static AntManager* _instance;



	public:

		static AntManager *instance();

		//setup is always a pain ;)
		void setGrid(Grid *inGrid);

		void add(AntPtr inAnt);
		void remove(AntPtr inAnt);
		void remove(Location inLocation);

		Grid* getGrid();
		AntSet* getMovedAnts();
		AntSet* getWaitingAnts();

		void nextMove(int moveNo);

		//TODO and Buckets and the accessors

		virtual ~AntManager();
};

#endif /* ANTMANAGER_H_ */
