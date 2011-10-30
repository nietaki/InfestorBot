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

typedef

class AntManager {
	public:
		AntManager();
		virtual ~AntManager();
		bool add(Ant* inAnt);
		bool remove(Ant* inAnt);
};

#endif /* ANTMANAGER_H_ */
