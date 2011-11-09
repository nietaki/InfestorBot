#ifndef SQUARE_H_
#define SQUARE_H_

#include <vector>
#include <boost/shared_ptr.hpp>
#include <vector>

#include "Ant.h"
class Square;
typedef std::vector<std::vector<Square> > Grid;


/*
 struct for representing a square in the grid.
 */
struct Square {
		bool isVisible, isWater, isHill, isFood;
		int ant, hillPlayer;
		std::vector<int> deadAnts;
//		AntPtr antPtr;

		Square();

		//resets the information for the square except water information
		void reset();
		bool isAccessible();
};

#endif //SQUARE_H_
