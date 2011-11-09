/*
 * Square.cc
 *
 *  Created on: 09-11-2011
 *      Author: jk292749
 */


#include "Square.h"

void Square::reset() {
  isVisible = 0;
  isHill = 0;
  isFood = 0;
  ant = hillPlayer = -1;
  deadAnts.clear();
}

Square::Square() {
  isVisible = isWater = isHill = isFood = 0;
  ant = hillPlayer = -1;
}

bool Square::isAccessible(){
  return !isWater;
}


