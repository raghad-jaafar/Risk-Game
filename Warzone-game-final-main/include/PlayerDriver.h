//
// Created by sonia on 2023-09-16.
//

#ifndef WARZONE_GAME_PLAYERDRIVER_H
#define WARZONE_GAME_PLAYERDRIVER_H
#include <string>

#include <list>

class PlayerDriver {
public:
    PlayerDriver();
    PlayerDriver(std::list<std::string> playerStrList);
    int testPlayers(std::list<std::string> playerStrList);


};
void testPlayers();


#endif //WARZONE_GAME_PLAYERDRIVER_H
