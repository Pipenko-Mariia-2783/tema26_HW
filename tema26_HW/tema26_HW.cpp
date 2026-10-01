#include "OrderSystem.h"

int Order::countOrder = 0;
int main()
{
    /*Order a1(10, "cheesburger", 150);
    Order a2(15, "gamburger", 170);

    a1.showOrder();
    a2.showOrder();*/

    OrderSystem d1;
    d1.addNewOrder();
    d1.addNewOrder();
    d1.addNewOrder();
    d1.showOrders();
    cout << "Sort by time: " << endl;
    d1.sortByTime();
    d1.showOrders();
    cout << "Done first: ";
    d1.delFirstBytime();
    cout << "\n============\n";
    d1.showOrders();

}