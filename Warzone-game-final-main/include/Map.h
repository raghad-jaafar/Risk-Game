#pragma once
#include <iostream>
#include <list>
#include <map>

// Graph Adapted from https://www.algotree.org/algorithms/adjacency_list/graph_as_adjacency_list_c++/


// Territory is Node
class Territory
{
private:

	std::string* Name;
	std::string* Continent;
	int* Id;

public:
	Territory();
	Territory(const Territory&);
	~Territory();
	Territory& operator= (const Territory&);
	friend std::ostream& operator<< (std::ostream& out, const Territory& territory);

	[[nodiscard]] std::string getName() const;

	void setName(std::string name);

	[[nodiscard]] std::string getContinent() const;

	void setContinent(std::string continent);

	[[nodiscard]] int getId() const;

	void setId(int id);

	Territory(std::string, int, std::string);

	void Display() const;

	[[nodiscard]] int GetId() const;


};

class Compare
{
public:
	bool operator () (const std::string& a, const std::string& b) const;
};

// Map is Graph
class Map
{
private:
	std::map<std::string, std::list<std::string>, Compare>* AdjacentList;

public:
	std::map<std::string, Territory*>* TerritoryDictionary;
	Map();
	Map(const Map&);
	~Map();
	Map& operator= (const Map&);
	friend std::ostream& operator<< (std::ostream& out, const Map& map);

	void Iterate(const Territory&) const;
	std::map<std::string, std::list<std::string>, Compare>* getAdjacentList() const;

	void Validate() const;
	void Bfs(const Territory& s, bool visited[]) const;

	void AddAdjacentTerritories(Territory& src, const std::list<std::string>& adjacentNodes) const;
};
//In the same file because it is asked on the  

/*
* Must be able to read from these .map files: http://www.windowsgames.co.uk/conquest_maps.html
* Instruction to understand these files: http://www.windowsgames.co.uk/conquest_create.html
*/
class MapLoader
{
private:
	Map* GameMap;


public:
	MapLoader();
	MapLoader(const MapLoader&);
	~MapLoader();
	[[nodiscard]] Map* GetMap() const;
	bool LoadMap(const std::string& fileName);
	MapLoader& operator= (const MapLoader&);
	friend std::ostream& operator<< (std::ostream& out, const MapLoader& mapLoader);

};



