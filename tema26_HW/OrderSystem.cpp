#include "OrderSystem.h"
#include <algorithm>

void OrderSystem::showOrders()
{
	for (int i = 0; i < orders.size(); i++)
	{
		orders[i].showOrder();
	}
}

void OrderSystem::addNewOrder()
{
	string desc;
	int min;
	float price;
	
	cout << "Input your dish: " << endl;
	cin.ignore();
	getline(cin, desc);
	cout << "Input how many min will cook your dish: " << endl;
	cin >> min;
	cout << "Input price: " << endl;
	cin >> price;
	Order newOrd(min, desc, price);

	orders.push_back(newOrd);
}

void OrderSystem::sortByTime()
{
		sort(orders.begin(), orders.end(), [](Order a, Order b)
			{
				return a.plusTime() < b.plusTime();
			});

}

void OrderSystem::delFirstBytime()
{
	sortByTime();
	cout << "\nDONE: ";
	orders[0].showOrder();
	orders.erase(orders.begin());
}
