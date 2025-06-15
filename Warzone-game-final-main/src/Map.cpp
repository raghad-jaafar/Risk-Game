#include "./include/Map.h"

#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>


using namespace std;


// trim from start (in place)
void Ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

// trim from end (in place)
void Rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
void Trim(std::string& s) {
	Rtrim(s);
	Ltrim(s);
}


Territory::Territory() {
	this->Name = new string;
	*(this->Name) = "";
	this->Continent = new string;
	*(this->Continent) = "";
	this->Id = new int;
	*(this->Id) = 0;

}

Territory::Territory(const Territory& territory)
{
	this->Id = new int;
	*(this->Id) = *(territory.Id);
	this->Name = new string;
	*(this->Name) = *(territory.Name);
	this->Continent = new string;
	*(this->Continent) = *(territory.Continent);
};

//Territory destructor
Territory::~Territory() {
	//	cout << "Territory destructor called" << "\n";
	delete Name;
	delete Id;
	delete Continent;
	Name = nullptr;
	Id = nullptr;
	Continent = nullptr;

};

Territory::Territory(string argName, const int argId, string argContinent)
{
	this->Name = new string(std::move(argName));
	this->Id = new int(argId);
	this->Continent = new string(std::move(argContinent));

}
Territory& Territory::operator=(const Territory& t) {
	if (this == &t) {
		return *this;
	}
	Name = t.Name;
	Continent = t.Continent;
	Id = t.Id;
	return *this;
}
std::ostream& operator<< (std::ostream& out, const Territory& territory)
{
	out << "(" << *territory.Name << "," << *territory.Id << "," << *territory.Continent << ") ";

	return out;
}

void Territory::Display() const {
	if (Name && Id) {
		std::cout << "(" << *Name << "," << *Id << ") ";
	}
	else {
		std::cout << "(Invalid Territory) ";
	}
}

int Territory::GetId() const
{
	return *Id;
}

string Territory::getName() const {
	return *Name;
}

void Territory::setName(string name) {
	*Name = std::move(name);
}

string Territory::getContinent() const {
	return *Continent;
}

void Territory::setContinent(string continent) {
	*Continent = std::move(continent);
}

int Territory::getId() const {
	return *Id;
}

void Territory::setId(int id) {
	*Id = id;
}

bool Compare::operator()(const string& a, const string& b) const
{
	return (a < b);
}

Map::Map() {
	cout << "Map Constructor Called" << "\n";
	this->AdjacentList = new std::map<string, std::list<string>, Compare>;
	this->TerritoryDictionary = new std::map<std::string, Territory*>;

}

Map::Map(const Map& argMap)
{
	cout << "Map Copy Constructor Called" << "\n";
	this->AdjacentList = new std::map<string, std::list<string>, Compare>;
	*(this->AdjacentList) = *(argMap.AdjacentList);
	this->TerritoryDictionary = new map<string, Territory*>;
	*(this->TerritoryDictionary) = *(argMap.TerritoryDictionary);
};



//Destructor for Map
Map::~Map() {
	cout << "Map Destructor Called" << "\n";
	for (const auto& pair : *TerritoryDictionary) {
		auto pointer = pair.second;
//		delete pointer;
//		pointer = nullptr;
	}
	delete TerritoryDictionary;
	TerritoryDictionary = nullptr;
	AdjacentList->clear();
	delete AdjacentList;
	AdjacentList = nullptr;
};





void Map::Iterate(const Territory& src) const
{
	src.Display();
	cout << " : ";

	for (const auto& adjacentTerritoryName : AdjacentList->at(src.getName()))
	{
		auto territoryPtr = this->TerritoryDictionary->at(adjacentTerritoryName);
		territoryPtr->Display();
	}
	cout << endl;
}

std::map<std::string, std::list<std::string>, Compare>* Map::getAdjacentList() const {
	return AdjacentList;
};


void Map::Validate() const
{
	const auto firstTerritoryName = AdjacentList->begin()->first;
	const auto firstTerritory = TerritoryDictionary->at(firstTerritoryName);
	const auto sizeOfMap = AdjacentList->size();
	const auto visitedTerritories = new bool[sizeOfMap] {false};
	Bfs(*firstTerritory, visitedTerritories);

	int counter = 0;
	for (size_t i = 0; i < sizeOfMap; ++i)
	{
		if (visitedTerritories[i])
		{
			counter++;
		}
	}

	if (static_cast<size_t>(counter) == sizeOfMap)
	{
		cout << "Graph is connected" << endl;
	}
	else
	{
		cout << "Graph is not connected" << endl;
	}

	delete[] visitedTerritories;
}

//BFS to check if graph is connected
//TODO: Check if we can add functions to class not mentioned in document.
void Map::Bfs(const Territory& s, bool visited[]) const
{
	list<string> q;
	q.push_back(s.getName());



	while (!q.empty())
	{
		const auto territoryName = (q.front());
		q.pop_front();
		for (const auto& territory : AdjacentList->at(territoryName))
		{
			auto territoryPtr = TerritoryDictionary->at(territory);
			if (!visited[territoryPtr->GetId()])
			{
				visited[territoryPtr->GetId()] = true;
				q.push_back(territory);
			}
		}
	}
}

void Map::AddAdjacentTerritories(Territory& src, const list<string>& adjacentNodes) const
{
	this->AdjacentList->insert({ src.getName(), adjacentNodes });

}
Map& Map::operator=(const Map& m) {
	if (this == &m) {
		return *this;
	}
	AdjacentList = m.AdjacentList;
	TerritoryDictionary = m.TerritoryDictionary;
	return *this;
}
std::ostream& operator<<(ostream& out, const Map& map) {
	out << "Territories in map:\n";
	for (const auto& territory : *map.TerritoryDictionary) {
		out << *territory.second << "\n";
	}
	return out;
}


MapLoader::MapLoader() {
	GameMap = new Map();
};

//MapLoader destructor
MapLoader::~MapLoader() {
	delete GameMap;
	GameMap = nullptr;
	cout << "Map Loader Destructor called" << "\n";
};

Map* MapLoader::GetMap() const
{
	return GameMap;
}

bool MapLoader::LoadMap(const string& fileName)
{

	try
	{
		// Opening File
		ifstream infile;
		infile.open(fileName);

		if (!infile.is_open()) {
			stringstream ss;
			ss << "failed to open " << fileName;
			throw std::runtime_error(ss.str());

		}

		//Go thought the input stream till it reaches the Continents section
		string currentLine;
		while (getline(infile, currentLine))
		{
			if (currentLine == "[Continents]")
			{
				break;
			}
		}
		//        vector<vector<string>> continentInfo;
		//
		//        while (getline(infile, currentLine))
		//        {
		//            //Skip empty lines
		//            if (currentLine.empty())
		//            {
		//                continue;
		//            }
		//            vector<string> wordsLine;
		//            stringstream ss(currentLine);
		//            string str;
		//
		//            //Parse words until it reaches the delimiter (,)
		//            //Appends them to a vector
		//            //TODO: Trim the str pushed to wordsLine of spaces
		//            while (getline(ss, str, '='))
		//            {
		//                Trim(str);
		//                wordsLine.push_back(str);
		//            }
		//            //Appends it to the vector of string vector , for use after
		//            continentInfo.push_back(wordsLine);
		//        }


		while (getline(infile, currentLine))
		{
			if (currentLine == "[Territories]")
			{
				break;
			}
		}


		// Parse through the territory section and pull out the words from each line
		vector<vector<string>> territoryInfo;
		while (getline(infile, currentLine))
		{
			//Skip empty lines
			if (currentLine.empty())
			{
				continue;
			}

			vector<string> wordsLine;
			stringstream ss(currentLine);
			string str;

			//Parse words until it reaches the delimiter (,)
			//Appends them to a vector
			//TODO: Trim the str pushed to wordsLine of spaces
			while (getline(ss, str, ','))
			{
				Trim(str);
				wordsLine.push_back(str);
			}

			//Appends it to the vector of string vector , for use after
			territoryInfo.push_back(wordsLine);
		}

		auto territoryDictionary = GameMap->TerritoryDictionary;
		int territoryId = 0;

		for (auto line : territoryInfo)
		{
			auto territoryPtr = new Territory(line.at(0), territoryId, line.at(3));
			territoryDictionary->insert({ line.at(0), territoryPtr });
			territoryId++;
		}



		// TODO: Add error handling; Example, if the given dictionary key is not existent
		// The 2005 map has the territory Bielorrusia is written Bielorusia once and makes the code fail.
		for (auto line : territoryInfo)
		{
			Territory* currentTerritoryPtr = (*territoryDictionary)[line.at(0)];
			list<string> adjacentTerritories;
			for (size_t i = 4; i < line.size(); ++i)
			{
				if ((territoryDictionary->count(line.at(i)))) {
					auto entry = line.at(i);
					adjacentTerritories.push_back(entry);
				}
				else {
					stringstream ss;
					ss << "Entry " << line.at(i) << " does not exist";
					throw std::runtime_error(ss.str());
				}
			}
			this->GameMap->AddAdjacentTerritories(*currentTerritoryPtr, adjacentTerritories);
			this->GameMap->Iterate(*currentTerritoryPtr);
		}
		return true;

	}
	catch (const std::exception& err)
	{
		cerr << "Map not Valid" << "\n";
		cerr << err.what() << "\n";
		delete this->GameMap;
		this->GameMap = new Map();
		return false;

	}



}

MapLoader::MapLoader(const MapLoader& mapLoader) {
	this->GameMap = new Map();
	*(this->GameMap) = *(mapLoader.GameMap);
}
MapLoader& MapLoader::operator=(const MapLoader& m) {
	if (this == &m) {
		return *this;
	}
	GameMap = m.GameMap;
	return *this;
}
std::ostream& operator<<(ostream& out, const MapLoader& mapLoader) {
	out << *mapLoader.GameMap << "\n";
	return out;
}

