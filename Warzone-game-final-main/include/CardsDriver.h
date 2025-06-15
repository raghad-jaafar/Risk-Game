//
// Created by sonia on 2023-09-16.
//

#ifndef WARZONE_GAME_CARDSDRIVER_H
#define WARZONE_GAME_CARDSDRIVER_H


#include "Player.h"

class CardsDriver {
public:
    CardsDriver();
    ~CardsDriver();
    int testCards(std::vector<Player> playerObjList);
};
void testCards();

#endif //WARZONE_GAME_CARDSDRIVER_H
