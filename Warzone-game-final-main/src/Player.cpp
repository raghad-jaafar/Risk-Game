//
// Created by sonia on 2023-09-16.
//
#include <iostream>
#include "./include/Player.h"
#include <string>
#include "./include/MainDriver.h"

Player::Player(std::string name) {
    this->name = make_unique<std::string>(name);
    this->playerHand = make_shared<Hand>();
    this->ol = make_unique<OrdersList>();
    this->playerTerritory = make_unique<std::vector<Territory>>();
}

// Copy constructor
Player::Player(const Player& player){
    name = std::make_unique<string>(*player.name);
}

// stream insertion overload
ostream& operator<<(ostream& stream, const Player& p)
{
    stream << *p.name;
    return stream;
}

// assignment operator
Player& Player::operator=(const Player& p) {
    if (this == &p) {
        return *this;
    }

    name = std::make_unique<string>(*p.name);
    ol = std::make_unique<OrdersList>(*p.ol);
    playerHand = std::make_shared<Hand>(*p.playerHand);
    playerTerritory = std::make_unique<std::vector<Territory>>(*p.playerTerritory);



    return *this;
}

Player::~Player() {

}




int Player::toAttack(Map& m) {
    std::cout<< *this;
    std::cout<< " can attack:\n";
    std::map<std::string, std::list<std::string>, Compare>* adjacentList = m.getAdjacentList();
    for (const auto& e: *adjacentList)
    {
        const std::string& territoryName = e.first;
        for (auto t : *this->playerTerritory) {
            if (t.getName() == territoryName) {
                m.Iterate(t);
            }
        }
    }
    return 0;
}
int Player::toDefend() {
    std::cout << *this->name + " has to defend:\n";
        for (auto Territory : *this->playerTerritory){
            Territory.Display();

    }
    return 0;
}


//isuueOrder should Take in a card to check which order to issue
int Player::issueOrder(int cardNum) {
    std::cout <<*name + "'s Orders List\n";
    int index = 0;
    for (const auto& order: this->ol->getOrderList())
    {
        cout << index << " " << order->getDescription() + "\n";
        index++;
    }
    cout << "\n";

    shared_ptr<Airlift> airliftOrder;
    shared_ptr<Blockade>  blockadeOrder;
    shared_ptr<Bomb>  bombOrder;
    shared_ptr<Negotiate>  negotiateOrder;
    shared_ptr<Deploy>  deployOrder;
    shared_ptr<Advance>  advanceOrder;
    std::cout <<"Adding ";
    switch(cardNum){
        case 1:
            deployOrder = make_shared<Deploy>();
            this->ol->addOrder(deployOrder);
            cout << deployOrder->getDescription()+ "\n";
            break;
        case 2:
            advanceOrder = make_shared<Advance>();
            this->ol->addOrder(advanceOrder);
            cout << advanceOrder->getDescription()+ "\n";
            break;
        case 3:
            bombOrder = make_shared<Bomb>();
            this->ol->addOrder(bombOrder);
            cout << bombOrder->getDescription()+ "\n";
            break;
        case 4:
            blockadeOrder = make_shared<Blockade>();
            this->ol->addOrder(blockadeOrder);
            cout << blockadeOrder->getDescription()+ "\n";
            break;
        case 5:
            airliftOrder = make_shared<Airlift>();
            this->ol->addOrder(airliftOrder);
            cout << airliftOrder->getDescription()+ "\n";
            break;
        case 6:
            negotiateOrder = make_shared<Negotiate>();

            cout << negotiateOrder->getDescription()+ "\n";
            this->ol->addOrder(negotiateOrder);
            break;
default: ;
    }

    std::cout<<"After Issuing:\n";
    index = 0;
    for (const auto& order: this->ol->getOrderList())
    {
        cout << index << " " << order->getDescription() + "\n";
        index++;
    }
    cout << "\n";
    // TODO: Loop through order List (Before issue)
    std::cout<<"-----------------------------\n";
    std::cout<<"Issuing Order...\n";
    std::cout<<"-----------------------------\n";
    std::cout<<"Current Orders:\n";
    // TODO: Loop through order List  (After issue)
    return 0;
}






