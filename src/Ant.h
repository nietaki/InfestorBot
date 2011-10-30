/*
 * Ant.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef ANT_H_
#define ANT_H_

#include "Bucketable.h"

class Ant: public Bucketable {
	private:
		const static int OWNER_ME = 0;
		int owner;
		int kill_count;//TODO set to 0
		//Strategy strat;

	public:
		Ant();
		Ant(int inOwner);
		virtual ~Ant();

		bool isMine();
		int getOwner();
		void setOwner(int playerNo);
};

#endif /* ANT_H_ */
