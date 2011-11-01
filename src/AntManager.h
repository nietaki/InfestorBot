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

typedef std::vector<std::vector<Square> > Grid;
typedef std::set<boost::shared_ptr<Ant> > AntSet;

class AntManager {

	private:
		AntManager();
		AntSet movedAnts, waitingAnts;
		Grid* gridPtr;


	public:
		static boost::shared_ptr<AntManager> _instance;
		static AntManager instance();

		//setup is always a pain ;)
		void setGrid(Grid *inGrid);

		void add(boost::shared_ptr<Ant> inAnt);
		void remove(boost::shared_ptr<Ant> inAnt);

		Grid& getGrid();
		AntSet& getMovedAnts();
		AntSet& getWaitingAnts();

		void nextMove();

		//TODO and Buckets
		//TODO set and Buckets accessors

		virtual ~AntManager();
};

#endif /* ANTMANAGER_H_ */
