#include "Order.h"

Order::Order()
{
	countOrder++;
	cookedT = 0;
	orserDesc = "unknown";
	price = 0;
	ordnum = countOrder;
}

Order::Order(int cookedT, string orderDesc, float price)
{
	countOrder++;
	this->cookedT = cookedT;
	this->orserDesc = orderDesc;
	this->price = price;
	ordnum = countOrder;
}

Date Order::getdate() const
{
	return date;
}

Time_ Order::getTime() const
{
	return time;
}

int Order::getcookedT()
{
	return cookedT;
}

string Order::getorderDesc()
{
	return orserDesc;
}

float Order::getprice()
{
	return price;
}

int Order::getordnum()
{
	return ordnum;
}


Time_ Order::plusTime() const
{
	return time + cookedT;
}

void Order::showOrder()
{
	cout << "--------------------------" << endl;
	cout << "Date: " << date << endl;
	cout << "Time: ";
	time.showTime();
	cout << "Time cooked: " << cookedT << endl;
	cout << "Order description: " << orserDesc << endl;
	cout << "Price: " << price << endl;
	cout << "Num of order: " << ordnum << endl;
	cout << "--------------------------" << endl;
}
