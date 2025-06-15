cmake_minimum_required(VERSION 3.25)
project(Warzone_game)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Warzone_game
        include/Cards.h
        include/CardsDriver.h
        include/GameEngine.h
        include/GameEngineDriver.h
        include/MainDriver.h
        include/Map.h
        include/Orders.h
        include/Player.h
        include/PlayerDriver.h
        src/Cards.cpp
        src/CardsDriver.cpp
        src/GameEngine.cpp
        src/GameEngineDriver.cpp
        src/MainDriver.cpp
        src/Map.cpp
        src/Orders.cpp
        src/Player.cpp
        src/PlayerDriver.cpp "src/MapDriver.cpp" "include/MapDriver.h"
        src/OrdersDriver.cpp
        include/OrdersDriver.h src/MapDriver.cpp)
