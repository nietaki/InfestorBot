#include "InfestorBot.h"

using namespace std;

//constructor
InfestorBot::InfestorBot() {
	state = State::instance();


}
;

//plays a single game of Ants.
void InfestorBot::playGame() {
	//reads the game parameters and sets up
	cin >> *state;
	state->setup();
	antManager = AntManager::instance();
	antManager->setGrid(& state->grid);

	endTurn();


	//continues making moves while the game is not over
	while (cin >> *state) {
		state->updateVisionInformation();
		AntManager::instance()->nextTurn(state->turn);
		makeMoves();
		endTurn();
	}
}
;

//makes the bots moves for the turn
void InfestorBot::makeMoves() {
	state->bug << "turn " << state->turn << ":" << endl;
	state->bug << *state << endl;
	return;


	AntSet *ants = antManager->getAnts();
	AntSet::iterator it;
	for(it=ants->begin(); it != ants->end(); it++){
		AntPtr curAnt = *it;
//		curAnt.
		for (int d = 0; d < TDIRECTIONS ; d++) {
			Location loc = state->getLocation(curAnt->getLocation(), d);

			if (!state->grid[loc.row][loc.col].isWater) {
				antManager->makeMove(curAnt->getLocation(), d);
				break;
			}
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


	state->bug << "time taken: " << state->timer.getTime() << "ms" << endl << endl;
}
;

//finishes the turn
void InfestorBot::endTurn() {
	if (state->turn > 0)
		state->reset();
	state->turn++;


	cout << "go" << endl;
}
;
