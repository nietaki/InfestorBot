/*
 * AntManager.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef ANTMANAGER_H_
#define ANTMANAGER_H_
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "Ant.h"


class AntManager : public LocationListener<Ant> {
	protected:
		set<AntPtr > ant_set;
		set<Locator<Ant> > notifying;
		//TODO buckets
	public:
		AntManager() {

		}
		virtual ~AntManager() {

		}
		bool add(AntPtr inAnt) {
			pair<set<int>::iterator,bool> inserted = ant_set.insert(inAnt);

		}
		bool remove(AntPtr inAnt){

		}
};

#endif /* ANTMANAGER_H_ */
