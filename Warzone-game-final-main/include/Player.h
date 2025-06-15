//
// Created by sonia on 2023-09-16.
//

#ifndef WARZONE_GAME_PLAYER_H
#define WARZONE_GAME_PLAYER_H
#include <list> //idk if we can use this
#include "./include/Cards.h"
#include "./include/PlayerDriver.h"
#include "./include/Cards.h"
#include "include/Map.h"
#include <string>



class Player {

public:
    // Constructors and Destructors
    Player(std::string name);
    Player();
    Player(const Player& other);    //  Copy Constructor
    ~Player();

    // Overloaded assignment
    Player& operator= (const Player& p);
    friend std::ostream& operator<<(std::ostream& os, const Player& p1);

    //Variables
    std::unique_ptr<string> name;
    shared_ptr<OrdersList> ol;
    std::shared_ptr<Hand> playerHand;
    std::unique_ptr<std::vector<Territory>> playerTerritory;


    // Functions

    int toAttack(Map&);
    int  toDefend();
    int issueOrder(int cardNum); //creates an Order instance, return 0 if all good

};


#endif //WARZONE_GAME_PLAYER_H
