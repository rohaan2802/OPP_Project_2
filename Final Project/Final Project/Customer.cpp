#include "Customer.h"

Customer::Customer() {}

void Customer::details()
{
	system("cls");
	cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
	cout << "REGISTRATION\n\n";
	string n, e, a, p;

	cin.ignore();

	cout << "Enter your full name: ";
	getline(cin, n);

	cout << "Enter your email: ";
	getline(cin, e);

	cout << "Enter your phone number: ";
	cin >> p;
	cin.ignore();

	cout << "Enter your address: ";
	getline(cin, a);

	name = n;
	phone = p;
	email = e;
	address = a;

	ofstream r1("C_info.txt", ios::app);
	r1 << name << ' ' << phone << ' ' << email << ' ' << address << endl;
}
Customer::~Customer(){}
