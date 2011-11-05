#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <stdint.h>
#include <set>
#include <cstdlib>
#include <list>

//#include "Ant.h"
#include "Timer.h"
#include "Bugger.h"
#include "Square.h"
#include "Location.h"
#include "AntManager.h"



/*
 struct to store current state information
 */
struct State {
	public:
		/*
		 Variables
		 */
		static State* _instance;
		int rows, cols, turn, turns, noPlayers;
		double attackradius2, spawnradius2, viewradius2;
		double attackradius, spawnradius, viewradius;
		double loadtime, turntime;
		std::vector<double> scores;

		//my variables
//		BucketableSet myAnts, foeAnts;


		bool gameover;
		int64_t seed;

		Grid grid;
		std::vector<Location> myAnts, enemyAnts, myHills, enemyHills, food;


		Timer timer;
		Bug* bug;

		/*
		 Functions
		 */
	private:
		//State(State const& ){ };
		//State& operator=(State const& ){ };


	public:

//		static State* instance();
		State();
		~State();

		void setup();
		void reset();

		void makeMove(const Location &loc, int direction);
		Square &getSquare(const Location& inLocation);
		double distance(const Location &loc1, const Location &loc2);
		Location getLocation(const Location &startLoc, int direction);

//		void updateVisionInformation();
};

std::ostream& operator<<(std::ostream &os, const State &state);
std::istream& operator>>(std::istream &is, State &state);

#endif //STATE_H_
