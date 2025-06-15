//
// Created by sonia on 2023-09-16.
//

#include <iostream>
#include "./include/MainDriver.h"

Deck::Deck(){
    this->deckVector = make_unique<std::vector<Cards>>();
}
//Copy Constructor
Deck::Deck(const Deck& d) {
    // Create a deep copy of the deckVector
    deckVector = std::make_unique<std::vector<Cards>>(*d.deckVector);
}
Cards::Cards(const Cards& card){
    type = make_unique<int>(*card.type);
};
Hand::Hand(const Hand& hand){
    myHand = std::make_shared<std::vector<Cards>>(*hand.myHand);
}

Deck::~Deck(){

}

Cards::~Cards(){

};

Cards::Cards(unique_ptr<int>::pointer type) {
    this->type = make_unique<int>(*type);
}



void Cards::play() {
    std::cout<<*this->type;
    std::cout<<"\t";
}
Cards Cards::play(shared_ptr <vector<Cards>> handVector, std::shared_ptr<OrdersList> ol) {  //should return itself


    shared_ptr<Airlift> airliftOrder;
    shared_ptr<Blockade>  blockadeOrder;
    shared_ptr<Bomb>  bombOrder;
    shared_ptr<Negotiate>  negotiateOrder;
    shared_ptr<Deploy>  deployOrder;
    shared_ptr<Advance>  advanceOrder;
    switch(*this->type){
        case 1:
            // Creates Order
            airliftOrder = make_shared<Airlift>();
            ol->addOrder(airliftOrder);
            //Adds to player's list of orders
            break;
        case 2:
            blockadeOrder = make_shared<Blockade>();
            ol->addOrder(blockadeOrder);
            break;
        case 3:
            bombOrder = make_shared<Bomb>();
            ol->addOrder(bombOrder);
            break;
        case 4:
            negotiateOrder = make_shared<Negotiate>();
            ol->addOrder(negotiateOrder);
            break;
        case 5:
            deployOrder = make_shared<Deploy>();
            ol->addOrder(deployOrder);
            break;

        case 6:
            advanceOrder = make_shared<Advance>();
            ol->addOrder(advanceOrder);
            break;

        default:
            break;

    }
    std::cout<<"\n------------------------\n";
    std::cout<<"My Cards: \t";

    for (auto card: *handVector.get()) {
        card.play();
    }
    std::cout<<"\nI play: ";
    std::cout<<*this;
    std::cout<<"\n";

    for (auto card: *handVector.get()) {
        if(*card.type.get() == *type.get()){
            handVector->pop_back();
            break;
        }
        else{

        }
    }
    return *this;
}

// stream insertion overload (Cards)
ostream& operator<<(ostream& stream, const Cards& c)
{
    stream << *c.type.get();
    return stream;
}

// stream insertion overload (Deck)
ostream& operator<<(ostream& stream, const Deck& d)
{
    std::string deckStr;
    for (auto card:*d.deckVector){
        std::cout<<card;
        std::cout<<"\t";
    }

    stream << deckStr;
    return stream;
}

// stream insertion overload (Deck)
ostream& operator<<(ostream& stream, const Hand& h)
{
    std::string handStr;
    for (auto card:*h.myHand){
        std::cout<<card;
        std::cout<<"\t";
    }

    stream << handStr;
    return stream;
}


// assignment operator (Cards)
Cards& Cards::operator=(const Cards& c) {
    if (this == &c) {
        return *this;
    }
    type = std::make_unique<int>(*c.type);

    return *this;
}


Hand& Hand::operator=(const Hand& h) {
    if (this == &h) {
        return *this;
    }
    myHand = std::make_shared<std::vector<Cards>>(*h.myHand);
    return *this;
}

Deck& Deck::operator=(const Deck& d) {
    if (this == &d) {
        return *this;
    }
    deckVector = std::make_unique<std::vector<Cards>>(*d.deckVector);

    return *this;
}

Cards::Cards(){

}



Hand::Hand() {
    this->myHand = make_shared<std::vector<Cards>>();
}

std::vector<Cards> Hand::draw(std::vector<Cards> deckVector, std::vector<Cards>* handVector) {

    return Deck::draw(deckVector, handVector);
}

std::vector<Cards> Deck::draw(std::vector<Cards> deckVector, std::vector<Cards>* handVector) {
    Cards newCard = deckVector.back();      // Get the last card from the deck
    handVector->insert(handVector->begin(), newCard); // Add to the front
    deckVector.pop_back();  // Remove the last card from the Deck
    return deckVector;
}


Hand::~Hand(){

}