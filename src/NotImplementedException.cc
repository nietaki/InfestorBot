/*
 * NotImplementedException.cc
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#include "NotImplementedException.h"

NotImplementedException::NotImplementedException() {
}

//NotImplementedException::~NotImplementedException() {
//}

const char* NotImplementedException::what() const throw(){
  return "This feature is not implemented in the class you're calling";
}
