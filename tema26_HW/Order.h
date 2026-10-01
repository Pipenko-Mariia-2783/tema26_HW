#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Time_.h"
using namespace std;

class Order
{
	static int countOrder;
	Date date;
	Time_ time;
	int cookedT;
	string orserDesc;
	float price;
	int ordnum;
public:
	Order();
	Order(int cookedT,string orderDesc,float price);

	Date getdate()const;
	Time_ getTime()const;
	int getcookedT();
	string getorderDesc();
	float getprice();
	int getordnum();

	Time_ plusTime()const;
	void showOrder();
};

