
#include "./include/Map.h"




void testLoadMaps()
{
	// If it doesn't work , just put the full path to the map file
	// Also , don't use singular slashes of this type "\"
    // TODO: Add more map files to test
    std::string listOfFiles [2] {
        "../resources/maps/World++.map",
        "../resources/maps/World2005.map"
    };
    for(const auto& file : listOfFiles){
        MapLoader mp;
        std::cout << "Loading file: " << file << "\n";
        if (
                mp.LoadMap(file))
        {
	        const auto myMap = mp.GetMap();
            myMap->Validate();
        }
    }

	//    mp.GetMap().Validate();

}
