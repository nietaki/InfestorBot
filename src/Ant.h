/*
 * Ant.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef ANT_H_
#define ANT_H_


#include "boost/shared_ptr.hpp"
#include "Location.h"

class Ant{
	private:
		const static int OWNER_ME = 0;
		int owner;
		int kill_count;
		int last_move_no;
		Location location;

//		Ant();
		Ant(int inOwner, Location startingLocation);

		//TODO Strategy strat;

	public:
		static boost::shared_ptr<Ant> makeAnt(int inOwner, Location startingLocation);
		virtual ~Ant();

		bool isMine() const;
		int getOwner() const;
		void setOwner(int playerNo);

		Location getLocation() const;
		void setLocation(Location inLocation);

};

#endif /* ANT_H_ */
