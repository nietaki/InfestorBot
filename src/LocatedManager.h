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
	public:
		typedef typename boost::shared_ptr<T> ItemPtr;
		typedef typename std::set<boost::shared_ptr<T> > LocatedSet;
		typedef typename LocatedSet::const_iterator iterator;
	protected:
		LocatedSet items_set;


	public:
		iterator add(ItemPtr inPtr) {
			//TODO fill method body
		}

		bool remove(ItemPtr inPtr) {
			return false;
			//TODO fill method body
		}

		iterator begin() const {
			return items_set.begin();
		}

		iterator end() const {
			return items_set.begin();
		}

		iterator find(const ItemPtr& x) const{
			return items_set.find(x);
		}


		virtual int changedLocation(boost::weak_ptr<T>& inTrackedObject, Location from, Location to){
			iterator object_iterator = items_set.find(inTrackedObject);
			if (object_iterator = items_set.end()) {

			}
			throw NotImplementedException();
		}


		LocatedManager() {

		}

		virtual ~LocatedManager() {

		}
};

#endif /* LOCATEDMANAGER_H_ */
