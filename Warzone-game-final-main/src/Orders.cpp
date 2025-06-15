#include "include/Orders.h"
/*==============    TO DO : VALIDATION FUNCTION   ==============*/
/*==============    TO DO : EXECUTION FUNCTION   ==============*/

/*From default construction*/
Order::Order()
{
	this->description = new string();
	this->effect = new string();
}

Order::Order(string orderName, string e)
{
	this->description = new string(orderName);
	this->effect = new string(e);
}

/*Copy constructor for the Order class*/
Order::Order(const Order& order): description(nullptr), effect(nullptr)
{
	*this->description = *order.description;
	*this->effect = *order.effect;
}
;


// Destructor
Order::~Order()
{
	delete description;
	delete effect;
	description = nullptr;
	effect = nullptr;

};

// assignment operator
Order& Order::operator=(const Order& o) {
	if (this == &o) {
		return *this;
	}
	description = o.description;
	effect = o.effect;
	return *this;
}


//no actual way to actually validate the orders for now
bool Order::validate() {
	return true;
};

//Similar story for the execute function
void Order::execute() {};

ostream& operator<<(ostream& os, const Order& order) {
	os << *order.description << " " << *order.effect;
	return os;
}


/*Getter and setter*/
string  Order::getDescription() const
{
	return *description;
}

void Order::setDescription(string orderName) const
{
	*description = std::move(orderName);
}

/*Getter and setter*/
string  Order::getEffect() const
{
	return *effect;
}

void Order::setEffect(string e)
{
	*effect = std::move(e);
}

/*========== DEPLOY ==========*/

//	Put a certain number of army units on a target territory

Deploy::Deploy()
{
	this->numOfArmy = new int(0);
	this->territory = nullptr;
	setDescription("Deploy order");
	setEffect(" -> Put a certain number of army units on a target territory");
}

Deploy::~Deploy()
{
	delete territory;
	delete numOfArmy;
	territory = nullptr;
	numOfArmy = nullptr;
};

//  PARAMETERIZED CONSTRUCTOR
Deploy::Deploy(Territory* t, const int n)
{
	this->numOfArmy = new int(n);
	this->territory = new Territory();
	(this->territory) = t;
};

//copy constructor
Deploy::Deploy(const Deploy& o) : Order(o)
{
	numOfArmy = o.numOfArmy;
	territory = o.territory;
};

// stream insertion overload
ostream& operator<<(ostream& stream, const Deploy& d)
{
	return stream << d.getDescription() << "\n"
		<< d.getEffect() << "\nNumber of army deployed: " << *d.numOfArmy
		<< "\nDeploy to: " << d.territory;
}

// assignment operator
Deploy& Deploy::operator=(const Deploy& d) {
	if (this == &d) {
		return *this;
	}
	numOfArmy = d.numOfArmy;
	territory = d.territory;

	return *this;
}

/*Getter and setter*/
int Deploy::getNumOfArmy() const
{
	return *numOfArmy;
}

Territory* Deploy::getTerritory() const
{
	return territory;
}


/*===== Validation ===== TO DO*/

//  Method that is used to validate if the order is valid - have the order card
//no actual way to actually validate the orders for now
bool Deploy::validate() {
	return true;
};


/*===== Execution ===== TO DO*/

//  Move a certain number of army units from the current player’s reinforcement pool to one of the current player’s territories
//  First validates the order, and executes its action if it is valid
void Deploy::execute()
{
	if (validate())
	{
		cout << "Deploy order validated and executed";
		/*Deployment validated and executed*/
	}
	else
	{
		/*Deployment not executed - Validation failed*/
	}
}


/*========== ADVANCE ==========*/



Advance::Advance() : Order{ "Advance order", "-> Move a certain number of army units from one territory (source territory)\nto another territory(target territory)" }
{
	this->advanceArmy = new int(0);
	this->advanceSource = nullptr;
	this->advanceTarget = nullptr;
}
/**
 * Destructor
 */
Advance::~Advance()
{
	delete advanceTarget;
	advanceTarget = nullptr;
	delete advanceSource;
	advanceSource = nullptr;
	delete advanceArmy;
	advanceArmy = nullptr;

};

Advance::Advance(Territory* t, Territory* s, int a) {
	(this->advanceTarget) = t;
	(this->advanceSource) = s;
	this->advanceArmy = new int(a);
};

/*copy constructor*/
Advance::Advance(const Advance& a)
	: Order(a)
{
	advanceArmy = a.advanceArmy;
	advanceSource = a.advanceSource;
	advanceTarget = a.advanceTarget;
}

// stream insertion overload
ostream& operator<<(ostream& stream, const Advance& ad)
{

	return stream << ad.getDescription() + "\n" << ad.getEffect() << "\nNumber of army advanced : "
		<< *ad.advanceArmy + "\nAdvance from: " << ad.getadvanceSource()
		<< "\nTo: " << ad.getadvanceTarget();
}

// assignment operator
Advance& Advance::operator=(const Advance& a) {
	if (this == &a) {
		return *this;
	}
	advanceArmy = a.advanceArmy;
	advanceSource = a.advanceSource;
	advanceTarget = a.advanceTarget;

	return *this;
}

/*Getter and setter*/
int Advance::getadvanceArmy() const
{
	return *advanceArmy;
}

Territory* Advance::getadvanceTarget() const
{
	return advanceTarget;
}

Territory* Advance::getadvanceSource() const
{
	return advanceSource;
}

void Advance::setadvanceArmy(int adArmy)
{
	*advanceArmy = adArmy;
}

void Advance::setadvanceTarget(Territory* adTarget)
{
	advanceTarget = adTarget;
}

void Advance::setadvanceSource(Territory* adSource)
{
	advanceTarget = adSource;
}


/*===== Validation ===== TO DO*/

//  Method that is used to validate if the order is valid - have the order card
bool Advance::validate()
{
	return true;
}

/*===== Execution ===== TO DO*/

//  Move a certain number of army units from one territory (source territory) to another territory (target territory)
//  ============ CHECK EXECUTION PHASE ============
//  First validates the order, and executes its action if it is valid
void Advance::execute()
{
	if (validate())
	{
		cout << "Advance order validated and executed";
		/*Advance validated and executed*/
	}
	else
	{
		/*Advance not executed - Validation failed*/
	}
}




/*========== BOMB ==========*/

// Destroy half of the army units located on an opponent’s territory that is adjacent to one of the current player’s territories

Bomb::Bomb()
{
	this->bombTarget = nullptr;
	setDescription("Bomb order");
	setEffect("-> Destroy half of the army units located on a target territory");
}

/*Destructor*/
Bomb::~Bomb()
{
	delete bombTarget;
	bombTarget = nullptr;
};

Bomb::Bomb(Territory* t)
{
	bombTarget = t;
}

Bomb::Bomb(const Bomb& b)
	: Order(b)
{
	bombTarget = b.bombTarget;
};

// stream insertion overload
ostream& operator<<(ostream& stream, const Bomb& b)
{
	return stream << b.getDescription() << "\n" << b.getEffect() << "\nTarget to bomb: " << b.getbombTarget();
}

// assignment operator
Bomb& Bomb::operator=(const Bomb& b) {
	if (this == &b) {
		return *this;
	}

	bombTarget = b.getbombTarget();

	return *this;
}

/*Getter and setter*/
Territory* Bomb::getbombTarget() const
{
	return bombTarget;
}

void Bomb::setbombTarget(Territory* bombTargetTerriroty)
{
	bombTarget = bombTargetTerriroty;
}

/*===== Validation ===== TO DO*/

//  Method that is used to validate if the order is valid - have the order card
bool Bomb::validate()
{
	return true;
}


/*===== Execution ===== TO DO*/

//  Destroy half of the army units located on an opponent’s territory that is adjacent to one of the current player’s territories
//  ============ CHECK EXECUTION PHASE ============
//  First validates the order, and executes its action if it is valid
void Bomb::execute()
{
	if (validate())
	{
		cout << "Bomb order validated and executed";
		/*Bomb order validated and executed*/
		//half the armies in the target territory
	}
	else
	{
		/*Bomb order not executed - Validation failed*/
	}
}



/*========== BLOCKADE ==========*/

// Triple the number of army units on a target territory and make it a neutral territory

Blockade::Blockade()
{
	this->blockedTerritory = nullptr;
	setDescription("Blockade order");
	setEffect("-> Triple the number of army units on a target territory and make it a neutral territory");
}

/*Destructor*/
Blockade::~Blockade()
{
	delete blockedTerritory;
	blockedTerritory = nullptr;
};

Blockade::Blockade(Territory* b)
{
	blockedTerritory = b;
}

Blockade::Blockade(const Blockade& b) {
	blockedTerritory = b.blockedTerritory;
}

// stream insertion overload
ostream& operator<<(ostream& stream, const Blockade& block)
{

	return stream << block.getDescription() + "\n" << block.getEffect() << "\nBlocked territory: " << block.getblockedTerritory();
}

// assignment operator
Blockade& Blockade::operator=(const Blockade& b) {
	if (this == &b) {
		return *this;
	}

	blockedTerritory = b.blockedTerritory;

	return *this;
}

/*Getter and setter*/

Territory* Blockade::getblockedTerritory() const
{
	return blockedTerritory;
}

void Blockade::setblockedTerritory(Territory* b)
{
	blockedTerritory = b;
}

/*===== Validation ===== TO DO*/

//  Method that is used to validate if the order is valid - have the order card
bool Blockade::validate()
{
	return true;
}


/*===== Execution ===== TO DO*/

//  Triple the number of army units on a target territory and make it a neutral territory
//  ============ CHECK EXECUTION PHASE ============
//  First validates the order, and executes its action if it is valid
void Blockade::execute()
{
	if (validate())
	{
		/*Blockade order validated and executed*/
		cout << "Blockade order validated and executed";
	}
	else
	{
		/*Blockade order not executed - Validation failed*/
	}
}

/*========== AIRLIFT ==========*/

//  Advance a certain number of army units from one from one territory (source territory) to another territory (target territory).
//  This order can only be issued if a player has the airlift card in their hand.

Airlift::Airlift() {

	this->airArmy = new int(0);
	this->targetTerritory = nullptr;
	this->sourceTerritory = nullptr;
	setDescription("Airlift Order");
	setEffect("-> Advance a certain number of army units from one from one territory (source territory)\nto another territory (target territory).");
}

//parameterized constructor
Airlift::Airlift(Territory* src, Territory* target, int n)
{
	this->airArmy = new int(n);
	this->sourceTerritory = new Territory(*src);
	this->targetTerritory = new Territory(*target);
}

/*Destructor*/
Airlift::~Airlift()
{
	delete targetTerritory;
	delete sourceTerritory;
	delete airArmy;
	airArmy = nullptr;
	targetTerritory = nullptr;
	sourceTerritory = nullptr;
}

/*copy constructor*/
Airlift::Airlift(const Airlift& a)
	: Order(a)
{
	airArmy = a.airArmy;
	sourceTerritory = a.sourceTerritory;
	targetTerritory = a.targetTerritory;
}

// stream insertion overload
ostream& operator<<(ostream& stream, const Airlift& air)
{

	return stream << air.getDescription() + "\n" << air.getEffect() << "\nNumber of army advanced with airlift : "
		<< *air.airArmy << "\nFrom: " << air.getSourceTerritory() << " To : " << air.getTargetTerritory();
}

// assignment operator
Airlift& Airlift::operator=(const Airlift& a) {
	if (this == &a) {
		return *this;
	}

	airArmy = a.airArmy;

	return *this;
}

/*Getter and setter*/
int Airlift::getAirArmy() const
{
	return *airArmy;
}

void Airlift::setAirArmy(int n)
{
	*airArmy = n;
}


Territory* Airlift::getSourceTerritory() const
{
	return sourceTerritory;
}

void Airlift::setSourceTerritory(Territory* s)
{
	sourceTerritory = s;
}


Territory* Airlift::getTargetTerritory() const
{
	return targetTerritory;
}
void Airlift::setTargetTerritory(Territory* t)
{
	targetTerritory = t;
}


/*===== Validation ===== TO DO*/

//  Method that is used to validate if the order is valid - have the order card
bool Airlift::validate()
{
	return true;
}


/*===== Execution ===== TO DO*/

//  advance a certain number of army units from one of the current player’s territories to any another territory
//  ============ CHECK EXECUTION PHASE ============
//  First validates the order, and executes its action if it is valid
void Airlift::execute()
{
	if (validate())
	{
		cout << "Airlift order validated and executed";
		/*Airlift order validated and executed*/
	}
	else
	{
		/*Airlift order not executed - Validation failed*/
	}
}




/*========== NEGOTIATE ==========*/

//  prevent attacks between the current player and another target player until the end of the turn.

Negotiate::Negotiate()
{
	//    opponent = nullptr;
	setDescription("Negotiate order");
	setEffect("-> Prevent attacks between the current player and another target player until the end of the turn.");
}

/*Destructor*/
Negotiate::~Negotiate()
{
	//    delete opponent;
	//    opponent = nullptr;
}

//Negotiate::Negotiate(Player* o)
//{
//    opponent = o;
//}

Negotiate::Negotiate(const Negotiate& n) {
	//    opponent = n.getopponent();
}

// stream insertion overload ==== ONLY GET THE PLAYER ID NOT THE NAME OF PLAYER
ostream& operator<<(ostream& stream, const Negotiate& n)
{
	return stream << n.getDescription() + "\n" << n.getEffect();
}

// assignment operator
Negotiate& Negotiate::operator=(const Negotiate& n) {
	if (this == &n) {
		return *this;
	}

	//    opponent = n.getopponent();

	return *this;
}

/*Getter and setter*/
//Player* Negotiate::getopponent() const
//{
//    return opponent;
//}

//void Negotiate::setopponent(Player* n)
//{
//    opponent = n;
//}

//  Method that is used to validate if the order is valid - have the order card
bool Negotiate::validate()
{
	return true;
}


/*===== Execution ===== TO DO*/

//  prevent attacks between the current player and the player targeted by the negotiated order until the end of the turn.
//  ============ CHECK EXECUTION PHASE ============
//  First validates the order, and executes its action if it is valid
void Negotiate::execute()
{
	if (validate())
	{
		cout << "Negotiate order validated and executed";
		/*Negotiate order validated and executed*/
	}
	else
	{
		/*Negotiate order not executed - Validation failed*/
	}
}







/*========== ORDERSLIST ==========*/

//   OrdersList class contains a list of Order objects.
//   OrdersList class implements a remove() method that deletes an order from the list.
//   OrdersList class implements a move() method to move an order in the list of orders

/*Default*/
OrdersList::OrdersList()
{
	orderList = std::vector<shared_ptr<Order>>();
}

//OrdersList::OrdersList(Player* p, vector<Order*> ol)
//{
//    orderListOwner = p;
//    this->orderList = ol;
//}

/*copy constructor*/
OrdersList::OrdersList(const OrdersList& ol) {

	orderList = ol.orderList;
}

/*Destructor*/
OrdersList::~OrdersList()
{
	orderList.clear();
}

// stream insertion overload
ostream& operator<<(ostream& stream, const vector<Order*>& oL)
{
	cout << "Printing out list of order: ";
	for (auto& i : oL)
	{
		cout << i->getDescription() << " ";
	}

	return stream << "End of list" << endl;
}

// assignment operator
OrdersList& OrdersList::operator=(const OrdersList& ol) {
	if (this == &ol) {
		return *this;
	}

	this->orderList = ol.orderList;

	return *this;
}

void OrdersList::remove(const int index)
{
	// last order int list
	if (index == orderList.size())
	{

		orderList.pop_back();
		return;
	}

	// out of range
	if ((index > orderList.size()) || (index <= 0))
	{
		cout << " Out of range" << endl;
	}

	// find position of order and remove it with erase()
	if (index <= orderList.size() && index > 0)
	{
		//vector<int> ::iterator it;
		const auto it = orderList.begin() + (index - 1);
		orderList.erase(it);
	}
}



void OrdersList::move(int i, int j)
{
	// using swap() method to move order within the list
	// ensure that player provides an index within the range 1 to 5
	if ((i <= orderList.size() && i > 0) && (j <= orderList.size() && j > 0)) // i and j need to be less or equal to list size AND more than 0
	{
		swap(orderList[i - 1], orderList[j - 1]);
	}
	else
		cout << "Input out of range" << endl;

}



void OrdersList::addOrder(const shared_ptr<Order>& newOrder)
{
	//add new order at the end of the order list
  // auto orderPtr = &newOrder;

	//TODO: This line gives a memory error (-Sonia)
	//orderList.push_back(orderPtr);
	orderList.push_back(newOrder);
}
vector<shared_ptr<Order>> OrdersList::getOrderList() const {
	return orderList;
}
