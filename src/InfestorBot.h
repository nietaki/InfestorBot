#ifndef INFESTOR_BOT_H_
#define INFESTOR_BOT_H_

#include "State.h"

/*
    This struct represents your bot in the game of Ants
*/
struct InfestorBot
{
    State state;

    InfestorBot();

    void playGame();    //plays a single game of Ants

    void makeMoves();   //makes moves for a single turn
    void endTurn();     //indicates to the engine that it has made its moves
};

#endif //INFESTOR_BOT_H_
