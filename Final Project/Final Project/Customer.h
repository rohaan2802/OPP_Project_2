#pragma once
#include"Credentials.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Customer:public Credentials
{
private:
	string name;
	string email;
	string phone;
	string address;
public:
	Customer();
	void details();
	~Customer();
};

