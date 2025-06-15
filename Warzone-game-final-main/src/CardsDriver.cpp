//
// Created by sonia on 2023-09-16.
//

#include "./include/CardsDriver.h"
#include "./include/MainDriver.h"
#include "./include/PlayerDriver.h"
#include "./include/Player.h"
#include "./include/Cards.h"
#include <iostream>
#include <random>

CardsDriver::CardsDriver() {};

void testCards(){
    std::cout<<"Creating Deck...\n";
    //1. Creates a deck of cards of all different kinds

//    Deck *deck = new Deck(); // Create Deck Obj
    unique_ptr<Deck> deck = make_unique<Deck>();

    int deckSize = 10;
    for (int i = 0; i < deckSize; i++){
        //Code for Generating Random int between 1-5
        std::random_device rd;  // Create a random device
        std::mt19937 mt(rd());  // Initialize a Mersenne Twister pseudo-random number generator
        std::uniform_int_distribution<int> dist(1, 6);  // Use a uniform distribution to get numbers from 1 to 5

        int random_number = dist(mt);   // Generate a random number in the range 1-5
//        int* newRand = new int;
        unique_ptr<int> newRand = make_unique<int>(random_number);
//        * newRand = random_number;
        Cards card = Cards(newRand.get());  //Create new card with rand int
        deck->deckVector->push_back(card);
    }

    std::cout<<"\nState: Deck contains: \t";
    std::cout<<*deck;
    std::cout<<"\n------------------------\n";
//    std::vector<Cards> handVector;
    Hand pHand = Hand();
//    Player* p = new Player("dummy");
    unique_ptr<Player> p = make_unique<Player>("dummy");
//    p->playerHand->myHand = &handVector;

    //2. Creates a hand object that is filled by drawing cards from the deck by repeatedly calling its draw() method


    // Hand draws 5 cards
    for(int i = 0; i< 5; i++){
        *deck->deckVector = pHand.draw(*deck->deckVector, p->playerHand->myHand.get());
//        *p->playerHand->myHand = p->playerHand->myHand.get();
    }

    std::cout<<"\nState: Player has drawn 5 cards\n";
    std::cout<<"\nState: Deck contains: \t";
    std::cout<<*deck;
    std::cout<<"\nState: Player Hand before playing: \t";
    std::cout<<*p->playerHand.get();

    std::cout<<"\nHand plays all cards...\n";
    for (auto rit = p->playerHand->myHand.get()->rbegin(); rit != p->playerHand->myHand.get()->rend(); ++rit) {
        Cards card = *rit;
        *deck->deckVector->insert(deck->deckVector->begin(), card.play(p->playerHand->myHand, p->ol));
        std::cout<<"\nState: Deck contains: \t";
        std::cout<<*deck;
    }
    std::cout<<"\n";




}

CardsDriver::~CardsDriver() {
}