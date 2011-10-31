/*
 * LocatedManager.h
 *
 *  Created on: Oct 31, 2011
 *      Author: nietaki
 */

#ifndef LOCATEDMANAGER_H_
#define LOCATEDMANAGER_H_

#include <set>
#include <list>
#include "LocationListener.h"
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

template <typename T>
class LocatedManager : public LocationListener<T> {

		typedef std::list<int> intlist;
		typedef intlist::iterator it1;
		std::list<int>::iterator it2;

		typedef std::set<T> someset;
		typedef typename someset::iterator somesetiterator; //compile error
		typename someset::iterator theiterator; //compile error


		typedef std::set<boost::shared_ptr<T> >  myset;
		typedef typename myset::iterator myiterator; //compile error

	protected:

	public:


		LocatedManager() {

		}

		virtual ~LocatedManager() {

		}
};

#endif /* LOCATEDMANAGER_H_ */
