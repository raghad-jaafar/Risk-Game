//
// Created by sonia on 2023-09-16.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

#include <iostream>
#include "include/MainDriver.h"


int main() {


    while(true){
        int choice;
        std::cout<<"Choose an option:\n1 - Test Load Maps\n2 - Test Players\n3 - Test Orders List\n4 - Test Cards\n5 - Test Game States\n0 - Quit\n";
        std::cin >> choice;
        if(choice == 1){
            std::cout<<"Testing Maps\n";
            testLoadMaps();
        }
        else if (choice == 2){
            std::cout<<"Testing Players\n";
            testPlayers();
        }
        else if (choice == 3){
            std::cout<<"Testing Orders List\n";
            testOrdersLists();
            std::cout<<"I have tested the orders lists\n";
        }
        else if (choice == 4){
            std::cout<<"Testing Cards\n";
            testCards();

        }
        else if (choice == 5){
            testGameStates();
        }
        else if (choice == 0){
            std::cout<<"This is the end of the game\n";
            break;
        }
        else{
            std::cout<<"You have chosen a wrong choice\n";
        }
    }
//    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
//    _CrtDumpMemoryLeaks();
    return 0;
}