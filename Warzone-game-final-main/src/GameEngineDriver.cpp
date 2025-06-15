//
// Created by sonia on 2023-09-17.
//

#include <iostream>
#include <list>
#include "include/GameEngineDriver.h"
#include "include/PlayerDriver.h"
#include "include/OrdersDriver.h"

GameEngineDriver::GameEngineDriver() {

}
GameEngineDriver::~GameEngineDriver() {

}

void testGameStates() {
    //TODO: Load Map State + Loop
    //TODO: State: Map has been loaded
    //TODO: State: Map has been validated
    std::cout << "Starting game...\n";
    //Loading map
    std::cout << "Loading map...\n";
    MapLoader mp;
    Map* myMap;
    while (true) {
    cout << "Enter the name of your map...\n";
        std::string mapname;
        std::cin >> mapname;
        
        std::cout << "Loading " << mapname << "\n";
        if (mp.LoadMap("../resources/maps/" + mapname + ".map"))
        {
            myMap = mp.GetMap();
            myMap->Validate();
            
        }

        std::cout << "Proceed with this map?\n1- Yes\n2- No\n";
        int c;
        std::cin >> c;
        if (c == 1) {
            break;
        }
        else {
            continue;
        }
    }
    
    std::cout << "Map loaded\n";
   

    std::cout<<"Adding Players...\n";
    int playerCount = 0;
    std::vector<shared_ptr<Player>> playerObjList;  // Array of Player Objects
    while(true){
        std::string playerStr;

        std::cout <<"New Player Name (press 0 to stop): ";
        std::cin >>playerStr ;

        if(playerStr == "0" && playerCount > 0){
            std::cout <<"There are "+std::to_string(playerCount)+" players\n";
            break;
        }
        else if(playerStr == "0" && playerCount == 0){
            std::cout <<"Must have at least one player.\n";
            continue;
        }
        else{

            shared_ptr<Player> player = make_shared<Player>(playerStr);

            shared_ptr<Deploy> deployOrder = make_shared<Deploy>();
            shared_ptr<Advance> advanceOrder = make_shared<Advance>();
            shared_ptr<Bomb> bombOrder = make_shared<Bomb>();
            shared_ptr<Blockade> blockadeOrder = make_shared<Blockade>();
            shared_ptr<Airlift> airliftOrder = make_shared<Airlift>();
            shared_ptr<Negotiate> negotiateOrder = make_shared<Negotiate>();

            player->ol->addOrder(deployOrder);
            player->ol->addOrder(advanceOrder);
            player->ol->addOrder(bombOrder);
            player->ol->addOrder(blockadeOrder);
            player->ol->addOrder(airliftOrder);
            player->ol->addOrder(negotiateOrder);
            playerObjList.push_back(std::move(player));    //Push to Player Object List
            playerCount += 1;
        }
        if(playerCount > 4){
            std::cout <<"\nMax amount of players have been reached!\n";
            std::cout <<"There are "+std::to_string(playerCount)+" players\n";
            break;
        }

    }
    std::cout <<"State: Players Added\n";
    std::cout << "Assigning territories to Players\n";
    std::map<Player*, Territory*> PlayerDictionary;
    std::srand(static_cast<unsigned>(time(nullptr)));
    
    bool test = true;
    bool restartOuterLoop = false;
    for (auto& p : playerObjList) {
        auto it = myMap->TerritoryDictionary->begin();
        restartOuterLoop = false;
        while (test) { 
            int randomIndex = std::rand() % myMap->TerritoryDictionary->size();
            it = myMap->TerritoryDictionary->begin();
            std::advance(it, randomIndex);  
            for (const auto i : PlayerDictionary) {
                if (i.second == it->second) {
                    restartOuterLoop = true;
                    break;
                }         
            }
            if (restartOuterLoop)
                continue;
            else
            {
                break;
            }
        }
        auto ptr = p;
        auto ptrName = *p->name.get();
        std::string n = ptrName;
        std::cout << "Assigning Territory "<<it->second->getName()<<" to "<<n<<"\n";
        p->playerTerritory->push_back(*(it->second));
        PlayerDictionary[p.get()] = it->second;
        
    }

    while(true){
        for(auto& p : playerObjList) {   //  Iterates through the player list
            auto playerOrderVectorSub = p->ol->getOrderList();

            std::cout <<"It is ";
            std::cout<<*p;
            std::cout<<"'s turn\n";

            std::cout <<*p;
            std::cout <<"'s Orders List\n";
            cout << "\n";
            int index = 0;
            for (const auto& order: playerOrderVectorSub)
            {
                cout << index << " " << order->getDescription() + "\n";
                index++;
            }
            cout << "\n";
            std::vector<shared_ptr<Order>> ordersToBeExecutedVector;
            int orderNumInput;
            while(true){
                std::cout<<"Which order would you like to issue?\n";
                std::cin >> orderNumInput;
                if(orderNumInput > index-1){
                    std::cout<<"Pick a valid choice\n";
                }
                else{
                    break;
                }
            }


            ordersToBeExecutedVector.push_back(playerOrderVectorSub[orderNumInput]);
            playerOrderVectorSub.erase(playerOrderVectorSub.begin() + orderNumInput);
            // TODO: Remove order from order list

            while(true){
                std::cout<<"Would you like to issue more orders?\n1 - Yes\n2 - No\n";
                int choice;
                std::cin >> choice;
                if (choice == 2){
                    std::cout<<"End Issue Orders\n";
                    std::cout <<*p;
                    std::cout <<"'s Orders List\n";
                    cout << "\n";
                    cout << "\n";
                    int index = 0;
                    for (const auto& order: playerOrderVectorSub)
                    {
                        cout << index << " " << order->getDescription() + "\n";
                        index++;
                    }
                    cout << "\n";
                    break;
                }
                else if (choice == 1){
                    int index = 0;
                    for (const auto& order: playerOrderVectorSub)
                    {
                        cout << index << " " << order->getDescription() + "\n";
                        index++;

                    }

                    while(true){
                        std::cout<<"Which order would you like to issue?\n";
                        std::cin >> orderNumInput;

                        if(orderNumInput > index-1){
                            std::cout<<"Pick a valid choice\n";
                        }
                        else{
                            break;
                        }

                    }




                    ordersToBeExecutedVector.push_back(playerOrderVectorSub[orderNumInput]);
                    playerOrderVectorSub.erase(playerOrderVectorSub.begin() + orderNumInput);
                }
                else{
                    std::cout<<"Pick a valid choice\n";
                }
            }
            std::cout<<"-------------------------\n";
            std::cout<<"State: Execute Orders\n";
            for (const auto& ordersToBeExecuted : ordersToBeExecutedVector) {
                ordersToBeExecuted->execute();
                std::cout <<"\n";
            }



            while(true){
            std::cout<<"Did you win?\n1 - Yes\n2 - No\n";
            int choice;
            std::cin >> choice;
                if (choice == 1){
                    std::cout <<*p;
                    std::cout <<" has won\n";
                    while(true){
                        std::cout<<"Would you like a rematch?\n1 - Yes\n2 - No\n";

                        int choice;
                        std::cin >> choice;

                        if (choice == 2){
                            exit(0);
                        }
                        else if (choice == 1){
                            break;
                        }
                        else{
                            std::cout<<"Pick a valid choice\n";
                        }

                    }
                }
                else if (choice == 2){
                    break;
                }
                else{

                    std::cout<<"Pick a valid choice\n";
                }
            }
        }
    }
}