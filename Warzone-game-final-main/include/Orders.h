#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Map.h"

using namespace std;


class Order {

private:
	string* description;
	string* effect;

public:

	string getDescription() const;
	void setDescription(string orderName) const;

	string getEffect() const;
	void setEffect(string effect);

	/*	Default constructor*/
	Order();
	Order(string orderName, string e);

	/*	Desctructor*/
	virtual ~Order();    //each subclass will override the destructor

	/*	copy constructor*/
	Order(const Order&);

	// assignment operator
	Order& operator=(const Order& o);

	/*A stream insertion operator that outputs a string describing the order.*/
	friend ostream& operator<<(ostream&, const Order&);

	virtual bool validate(); //each subclass will override this method
	virtual void execute();   //each subclass will override this method
};

/*	========== DEPLOY ==========	*/
class Deploy : public Order {

private:
	int* numOfArmy;
	Territory* territory;

public:

	/*	Default constructor*/
	Deploy();

	//	Parameterized constructor
	Deploy(Territory*, int);

	/*	Desctructor*/
	~Deploy() override;

	/*	copy constructor*/
	Deploy(const Deploy& o);

	// stream insertion
	friend ostream& operator<<(ostream&, const Deploy&);

	// assignment operator
	Deploy& operator=(const Deploy& d);

	/*	Getter and setter*/
	int getNumOfArmy() const;
	void setNumOfArmy(int numberArmy);

	Territory* getTerritory() const;
	void setTerritory(Territory* t);

	bool validate() override;
	void execute() override;
};

/*========== ADVANCE ==========*/
class Advance : public Order {

private:

	int* advanceArmy;
	Territory* advanceSource;
	Territory* advanceTarget;


public:
	/*default constructor*/
	Advance();

	//	parameterized constructor 
	Advance(Territory*, Territory*, int);

	/*Destructor*/
	~Advance() override;

	/*copy constructor*/
	Advance(const Advance&);

	// assignment operator
	Advance& operator=(const Advance& a);

	// stream insertion
	friend ostream& operator<<(ostream&, const Advance&);

	/*Getter and setter*/
	void setadvanceArmy(int);
	int getadvanceArmy() const;

	void setadvanceTarget(Territory*);
	Territory* getadvanceTarget() const;

	void setadvanceSource(Territory*);
	Territory* getadvanceSource() const;

	bool validate() override;
	void execute() override;
};


/*========== BOMB ==========*/
class Bomb : public Order {
private:
	Territory* bombTarget;
public:

	/*Default constructor*/
	Bomb();

	/*parameterized constructor*/
	explicit Bomb(Territory*);

	/*Destructor*/
	~Bomb() override;

	/*copy constructor*/
	Bomb(const Bomb&);

	// assignment operator
	Bomb& operator=(const Bomb& b);

	// stream insertion
	friend ostream& operator<<(ostream&, const Bomb&);

	/*Getter and setter*/
	[[nodiscard]] Territory* getbombTarget() const;
	void setbombTarget(Territory*);

	bool validate() override;
	void execute() override;
};



/*========== BLOCKADE ==========*/
class Blockade : public Order {
private:
	Territory* blockedTerritory;

public:
	/*Default constructor*/
	Blockade();

	/*parameterized constructor*/
	explicit Blockade(Territory*);

	/*Destructor*/
	~Blockade() override;

	/*copy constructor*/
	Blockade(const Blockade&);

	// assignment operator
	Blockade& operator=(const Blockade& b);

	// stream insertion
	friend ostream& operator<<(ostream&, const Blockade&);

	/*Getter and setter*/
	[[nodiscard]] Territory* getblockedTerritory() const;
	void setblockedTerritory(Territory*);

	bool validate() override;
	void execute() override;
};



/*========== AIRLIFT ==========*/
class Airlift : public Order {
private:
	int* airArmy;
	Territory* sourceTerritory;
	Territory* targetTerritory;

public:

	/*Default constructor*/
	Airlift();

	//parameterized constructor 
	Airlift(Territory*, Territory*, int);

	/*Desctructor*/
	~Airlift() override;

	/*copy constructor*/
	Airlift(const Airlift& a);

	// assignment operator
	Airlift& operator=(const Airlift& a);

	// stream insertion
	friend ostream& operator<<(ostream&, const Airlift&);

	/*Getter and setter*/
	[[nodiscard]] int getAirArmy() const
		;
	void setAirArmy(int numAirArmy);

	[[nodiscard]] Territory* getSourceTerritory() const;
	void setSourceTerritory(Territory* srcTer);

	Territory* getTargetTerritory() const;
	void setTargetTerritory(Territory* tarTer);

	bool validate() override;
	void execute() override;
};


/*========== NEGOTIATE ==========*/
class Negotiate : public Order {
private:
	//	Player* opponent;

public:

	/*Default constructor*/
	Negotiate();

	//parameterized constructor 
//	Negotiate(Player*);

	/*Destructor*/
	~Negotiate() override;

	/*copy constructor*/
	Negotiate(const Negotiate&);

	// assignment operator
	Negotiate& operator=(const Negotiate& n);

	// stream insertion
	friend ostream& operator<<(ostream&, const Negotiate&);

	/*Getter and setter*/
//	Player* getopponent() const;
//	void setopponent(Player*);

	bool validate() override;
	void execute() override;

};





/*========== ORDERSLIST ==========*/
class OrdersList {
private:
	//Create an order list in default and have it store 
//	vector<Order*> orderList;
//	Player* orderListOwner;

	vector<shared_ptr<Order>> orderList;
public:
	OrdersList();
	//	OrdersList(Player* orderOwner, vector<Order*> oL);
	//  OrdersList(Player* p, vector<Order*> ol);
	~OrdersList();

	/*copy constructor*/
	OrdersList(const OrdersList& ol);	// TO VERIFY

	// assignment operator
	OrdersList& operator=(const OrdersList& ol);

	// stream insertion
	friend ostream& operator<<(ostream&, const OrdersList&);

	//getter for list
	vector<shared_ptr<Order>> getOrderList() const;

	void remove(int index);
	void  move(int i, int j);
	void addOrder(const shared_ptr<Order>& o); //add order at the end of the list



};
