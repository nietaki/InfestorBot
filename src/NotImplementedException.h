/*
 * NotImplementedException.h
 *
 *  Created on: Oct 30, 2011
 *      Author: nietaki
 */

#ifndef NOTIMPLEMENTEDEXCEPTION_H_
#define NOTIMPLEMENTEDEXCEPTION_H_
using namespace std;

#include <exception>

class NotImplementedException : public exception {
	public:
		NotImplementedException();
		virtual const char* what() const throw();
};

#endif /* NOTIMPLEMENTEDEXCEPTION_H_ */
