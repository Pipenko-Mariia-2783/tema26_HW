#pragma once
#include "Order.h"
class OrderSystem
{
	vector<Order> orders;
public:
	void showOrders();
	void addNewOrder();
	void sortByTime();
	void delFirstBytime();
};

