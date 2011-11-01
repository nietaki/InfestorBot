/*
 * Helper.h
 *
 *  Created on: Nov 1, 2011
 *      Author: nietaki
 */

#ifndef HELPER_H_
#define HELPER_H_

#include "Square.h"
#include "State.h"

class Helper {
	private:
		Helper();
	public:
		virtual ~Helper();
		static Square& getSquare(Grid* inGrid, const Location& inLocation);
		static int getTurnNo();
};

#endif /* HELPER_H_ */
