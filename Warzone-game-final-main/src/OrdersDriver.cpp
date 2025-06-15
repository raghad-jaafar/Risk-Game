#include <memory>
#include "include/OrdersDriver.h"

#include <iostream>


using namespace std;

/*Parameterized*/
//OrdersDriver::OrdersDriver(vector<Order> oList)
//{
//	testOrdersLists(oList);
//}

void testOrdersLists()
{
	OrdersList oL;

    std::cout<<"Creating Orders...\n";
//CREATE ORDER NEW OBJECTS
//  Deploy deployOrder;
    //Deploy* deployOrder = new Deploy();
    //Advance* advanceOrder = new Advance();
    //Bomb* bombOrder = new Bomb();
    //Blockade* blockadeOrder = new Blockade();
    //Airlift* airliftOrder = new Airlift();
    //Negotiate* negotiateOrder = new Negotiate();

	const auto deployOrder = make_shared<Deploy>();
    const auto advanceOrder = make_shared<Advance>();
    const auto bombOrder = make_shared<Bomb>();
    const auto blockadeOrder = make_shared<Blockade>();
    const auto airliftOrder = make_shared<Airlift>();
    const auto negotiateOrder = make_shared<Negotiate>();
//CREATE ORDER LIST

//	A free function named testOrdersLists() that creates orders of every kind,
//	places them in an OrdersList object
//    OrdersList oL;

// add order object in list
    oL.addOrder((deployOrder));
    oL.addOrder((advanceOrder));
    oL.addOrder((bombOrder));
    oL.addOrder((blockadeOrder));
    oL.addOrder((airliftOrder));
    oL.addOrder((negotiateOrder));

//PRINTING ORDER LIST
    cout << "\n";
    int index = 1;
    for (const auto& order : oL.getOrderList())
    {
        cout << index << " " << order->getDescription() + "\n";
        index++;
    }
    cout << "\n";

    cout << "\nPrinting effect of each order type:\n";
    cout << "\n***********************************\n";
    index = 1;
    for (const auto& order : oL.getOrderList())
    {
        cout << index << " " << *order << "\n" << endl;
        index++;
    }

    cout << "\n***********************************\n";
    cout << "\nTesting to print specific order:r\n";
    // ONLY WORK FOR DEPLOY TYPE -
    cout << index << " " << *deployOrder << "\n" << endl;
    cout << index << " " << *advanceOrder << "\n" << endl;
    cout << index << " " << *bombOrder << "\n" << endl;
    cout << index << " " << *blockadeOrder << "\n" << endl;
    cout << index << " " << *airliftOrder << "\n" << endl;
    cout << index << " " << *negotiateOrder << "\n" << endl;
    cout << "\n***********************************\n" << endl;
//
//// MOVING ORDER FROM LIST - INDEX OF ORDER FROM 1 TO 5
    cout << "Input the order number you want to move: ";
    int i;
    int j;
    cin >> i;
    cout << "Where to input it? : ";
    cin >> j;
    oL.move(i,j);

    //PRINTING ORDER LIST
    cout << "\nNew order list:\n";
    index = 1;
    for (const auto& order : oL.getOrderList())
    {
        cout << index << " " << order->getDescription() + "\n";
        index++;
    }
    cout << "\n";


//// REMOVING ORDER
    cout << "Input the order number you want to remove: ";
    int r;
    cin >> r;
    oL.remove(r);

    //PRINTING ORDER LIST
    cout << "\nNew order list:\n";
    index = 1;
    for (const auto& order : oL.getOrderList())
    {
        cout << index << " " << order->getDescription() + "\n";
        index++;
    }
    cout << "\n";
   


}

