#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Items.h"
#include<sstream>

using namespace std;

class Cart:public Items
{
protected:
	int cart_size;
	float total_bill;
	Items my_cart[50];
public:
	Cart();
	void AddItems();
	void DisplayItems();
	void PlaceOrder();
	void RemoveItems();
	void TotalPrice();
	void Search();
	virtual void Options();
	~Cart();
};

