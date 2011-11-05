/*
 * Bugger.h
 *
 *  Created on: Nov 5, 2011
 *      Author: nietaki
 */

#ifndef BUGGER_H_
#define BUGGER_H_

#include "Bug.h"

class Bugger {
	private:
		static Bug* getBug();
		static Bug* _bug;
		Bugger();
	public:
		virtual ~Bugger();
};

#endif /* BUGGER_H_ */
