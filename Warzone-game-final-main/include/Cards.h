
//
// Created by sonia on 2023-09-16.
//

#ifndef WARZONE_GAME_CARDS_H
#define WARZONE_GAME_CARDS_H
#include <string>
#include <queue>
#include "Orders.h"
class Cards {
public:
    // Constructors and Destructors
    Cards(unique_ptr<int>::pointer type);
    Cards(const Cards& card);
    ~Cards();
    Cards();

    // Overloaded assignment
    Cards& operator= (const Cards& c);
    friend std::ostream& operator<<(std::ostream& os, const Cards& c);

    // Variables
//    int* type;

    unique_ptr<int> type;
    // Functions
    void play();
    Cards play(shared_ptr<vector<Cards>> handVector, std::shared_ptr<OrdersList> ol);
};

class Deck{
private:

public:
    // Constructors and Destructors
    Deck();
    Deck(const Deck& deck);
    ~Deck();

    // Overloaded assignment
    Deck& operator= (const Deck& d);
    friend std::ostream& operator<<(std::ostream& os, const Deck& d);

    // Variables
    unique_ptr<std::vector<Cards>> deckVector;

    //Functions
    std::vector<Cards> draw(std::vector<Cards> deckVector, std::vector<Cards>* handVector);

};

// A Player obj has a Hand Obj
class Hand:Deck {
public:
    // Constructors and Destructors
    Hand();
    Hand(const Hand& hand);
    ~Hand();

    // Overloaded assignment
    Hand& operator= (const Hand& h);
    friend std::ostream& operator<<(std::ostream& os, const Hand& h);

    // Members
    shared_ptr<std::vector<Cards>> myHand;  // Contains a list of Cards the Hand has

    // Methods
    std::vector<Cards> draw(std::vector<Cards> deckVector, std::vector<Cards>* myHand);

};

#endif //WARZONE_GAME_CARDS_H