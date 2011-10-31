/*
 * Ant.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef ANT_H_
#define ANT_H_

#include "Locator.h"
#include "boost/shared_ptr.hpp"

class Ant;
typedef boost::shared_ptr<Locator<Ant> >  AntLocatorPtr;
typedef boost::shared_ptr<Ant >  AntPtr;

//TODO check if this makes sense
class Ant{
	private:
		const static int OWNER_ME = 0;
		int owner;
		int kill_count;
		AntLocatorPtr locator;
//		Ant();
		Ant(int inOwner);
		void setLocator(boost::shared_ptr<Locator<Ant> >);

		//TODO Strategy strat;

	public:
		static boost::shared_ptr<Ant> makeAnt(int inOwner);
		virtual ~Ant();

		bool isMine() const;
		int getOwner() const;
		void setOwner(int playerNo);

		Location getLocation() const;
		void setLocation(Location inLocation);
		Locator<Ant>& getLocator() const;
};

#endif /* ANT_H_ */
