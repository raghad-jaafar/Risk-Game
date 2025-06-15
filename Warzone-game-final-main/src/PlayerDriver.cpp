//
// Created by sonia on 2023-09-16.
//
#include <iostream>
#include "./include/MainDriver.h"
#include "./include/PlayerDriver.h"
#include "./include/Player.h"
#include "./include/CardsDriver.h"
#include "./include/Cards.h"



PlayerDriver::PlayerDriver(){
};


void testPlayers() {


    unique_ptr<Player> p = make_unique<Player>("Dummy");

    Territory ter1("Canada", 1, "NA");
    Territory ter2("USA", 2, "NA");
    Territory ter3("Mexico", 3, "NA");
    Territory* pt1 = &ter1;
    Territory* pt2 = &ter2;
    Territory* pt3 = &ter3;
    p->playerTerritory->push_back(ter1);
    // p->MyTerritories.push_back(ter2);
     //p->MyTerritories.push_back(ter3);

    shared_ptr<Map> m = make_shared<Map>();
    m->TerritoryDictionary->insert({ter1.getName(), pt1});
    m->TerritoryDictionary->insert({ ter2.getName(), pt2 });
    m->TerritoryDictionary->insert({ ter3.getName(), pt3 });
    std::list<string> test1;
    test1.push_back(ter2.getName());
    test1.push_back(ter3.getName());
    m->AddAdjacentTerritories(ter1,test1);
   // p->toDefend();
   p->toAttack(*m);
   p->toDefend();
   std::cout<<"\n";
    p->issueOrder(1);
    p->issueOrder(2);
    p->issueOrder(3);
    p->issueOrder(4);
    p->issueOrder(5);
    p->issueOrder(6);

}
