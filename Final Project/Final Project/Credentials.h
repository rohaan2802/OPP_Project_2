#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class Credentials
{
protected:
	string username;
	string password;
public:
	Credentials();
	void setID(char x);
	int verifyID(char x);
	void forgot(char x);
};

