/*
 * Bugger.cc
 *
 *  Created on: Nov 5, 2011
 *      Author: nietaki
 */

#include "Bugger.h"
Bug* Bugger::_bug = NULL;

Bugger::Bugger() {

}

Bug* Bugger::getBug() {
	if(! Bugger::_bug){
		Bugger::_bug = new Bug();
		Bugger::_bug->open("./debug2.txt");
		(* Bugger::_bug) << "The one and only Bug object has been created" << std::endl;

	}

	return Bugger::_bug;
}

Bugger::~Bugger() {
}
