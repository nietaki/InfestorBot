#include "InfestorBot.h"

using namespace std;

//constructor
InfestorBot::InfestorBot() {
	state = new State;
	bug = Bugger::getBug();
};

//plays a single game of Ants.
void InfestorBot::playGame() {
	//reads the game parameters and sets up
	cin >> *state;
	state->setup();
	antManager = new AntManager(state);

	endTurn();


	//continues making moves while the game is not over
	while (cin >> *state) {
		state->updateVisionInformation();
		antManager->nextTurn(state->turn);
		makeMoves();
		endTurn();
	}
}
;

//makes the bots moves for the turn
void InfestorBot::makeMoves() {
	(*bug) << "turn " << state->turn << ":" << endl;
//	state->bug << *state << endl;
//	return;//FIXME


	AntSet *ants = antManager->getAnts();
	AntSet::iterator it;
	for(it=ants->begin(); it != ants->end(); it++){
		AntPtr curAnt = *it;
		if(curAnt){
			(*bug) << "the ant should be ok" << endl;
			for (int d = 0; d < TDIRECTIONS ; d++) {
				Location loc = state->getLocation(curAnt->getLocation(), d);

				if (!state->grid[loc.row][loc.col].isWater && (!antManager->getAntRef(loc))) {
					antManager->makeMove(curAnt->getLocation(), d);
					break;
				}
			}
		}else{
			(*bug) << "iterating over dead Ant" << endl;
		}
	}
	//FIXME no moves picked for now
	//picks out moves for each ant
//	for (int ant = 0; ant < (int) state->myAnts.size(); ant++) {
//		for (int d = 0; d < TDIRECTIONS; d++) {
//			Location loc = state->getLocation(state->myAnts[ant], d);
//
//			if (!state->grid[loc.row][loc.col].isWater) {
//				state->makeMove(state->myAnts[ant], d);
//				break;
//			}
//		}
//	}


	(*bug) << "time taken: " << state->timer.getTime() << "ms" << endl << endl;
}
;

//finishes the turn
void InfestorBot::endTurn() {
	if (state->turn > 0)
		state->reset();
	state->turn++;


	cout << "go" << endl;
};
