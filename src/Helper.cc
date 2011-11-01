/*
 * Helper.cc
 *
 *  Created on: Nov 1, 2011
 *      Author: nietaki
 */

#include "Helper.h"

Helper::Helper() {

}

Helper::~Helper() {
}

int Helper::getTurnNo() {
	return State::instance()->turn;
}




