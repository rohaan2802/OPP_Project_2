#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Customer.h"

using namespace std;

class Items:public Customer
{
public:
	string name;
	string category;
	string SKU;
	float s_price;
	float p_price;
	int quantity;

	Items();
	void Display(Items&);
};

