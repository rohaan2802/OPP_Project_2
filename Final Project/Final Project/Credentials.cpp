#include "Credentials.h"

Credentials::Credentials(){}
void Credentials::setID(char x)
{
	string ID = "", PASS = "";
	cout << "Enter a username: ";
	cin >> ID;
	cout << "Enter a password: ";
	cin.ignore();
	cin >> PASS;
	username = ID;
	password = PASS;
	if (x == 'C')
	{
		ofstream c1("C_credentials.txt", ios::app);
		c1 << username << ' ' << password << endl;
		cout << "\nRegistration Successful\n\n";
		system("pause");
	}
	if (x == 'A')
	{
		ofstream c1("A_credentials.txt", ios::app);
		c1 << username << ' ' << password << endl;
		cout << "\nRegistration Successful\n\n";
		system("pause");
	}
	if (x == 'V')
	{
		ofstream c1("V_credentials.txt", ios::app);
		c1 << username << ' ' << password << endl;
		cout << "\nRegistration Successful\n\n";
		system("pause");
	}
}
int Credentials::verifyID(char x)
{
	string ID = "", PASS = "";
	int count = 0;
	system("cls");
	cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
	cout << "LOGIN\n\n";
	cout << "Enter a username: ";
	cin >> ID;
	cout << "Enter a password: ";
	cin.ignore(1, '\n');
	cin >> PASS;
	if (x == 'C')
	{
		ifstream i1("C_credentials.txt");
		while (i1 >> username >> password)
		{
			if (username == ID && password == PASS)
			{
				count = 1;
				break;
			}
		}
		i1.close();
		if (count == 1)
		{
			cout << "\nLogin Successful\n\n";
			system("pause");
			system("cls");
			return count;
		}
		if (count == 0)
		{
			cout << "\nERROR, Account not found\n\n";
			system("pause");
			return count;
		}
	}
	if (x == 'A')
	{
		ifstream i1("A_credentials.txt");
		while (i1 >> username >> password)
		{
			if (username == ID && password == PASS)
			{
				count = 1;
				break;
			}
		}
		i1.close();
		if (count == 1)
		{
			cout << "\nLogin Successful\n\n";
			system("pause");
			system("cls");
		}
		if (count == 0)
		{
			cout << "\nERROR, Account not found\n\n";
			system("pause");
			return count;
		}
	}
	if (x == 'V')
	{
		ifstream i1("V_credentials.txt");
		while (i1 >> username >> password)
		{
			if (username == ID && password == PASS)
			{
				count = 1;
				break;
			}
		}
		i1.close();
		if (count == 1)
		{
			cout << "\nLogin Successful\n\n";
			system("pause");
			system("cls");
		}
		if (count == 0)
		{
			cout << "\nERROR, Account not found\n\n";
			system("pause");
			return count;
		}
	}
}
void Credentials::forgot(char x)
{
	string ID = "";
	int count = 0;
	system("cls");
	cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
	cout << "FORGOT PASSWORD\n\n";
	cout << "Enter the username you remember: ";
	cin >> ID;
	if (x == 'C')
	{
		ifstream f1("C_credentials.txt");
		while (f1 >> username >> password)
		{
			if (username == ID)
			{
				count = 1;
				break;
			}
		}
		f1.close();
		if (count == 1)
		{
			cout << "\nCongrats! We found your account\n";
			cout << "\nThe Password for '" << username << "' is: " << password << endl << endl;
			system("pause");
			return;
		}
		if (count == 0)
		{
			cout << "\nSorry! We could not find you account\n\n";
			system("pause");
			return;
		}
	}
	if (x == 'A')
	{
		ifstream f1("A_credentials.txt");
		while (f1 >> username >> password)
		{
			if (username == ID)
			{
				count = 1;
				break;
			}
		}
		f1.close();
		if (count == 1)
		{
			cout << "\nCongrats! We found your account\n";
			cout << "\nThe Password for '" << username << "' is: " << password << endl << endl;
			system("pause");
			return;
		}
		if (count == 0)
		{
			cout << "\nSorry! We could not find you account\n\n";
			system("pause");
			return;
		}
	}
	if (x == 'V')
	{
		ifstream f1("V_credentials.txt");
		while (f1 >> username >> password)
		{
			if (username == ID)
			{
				count = 1;
				break;
			}
		}
		f1.close();
		if (count == 1)
		{
			cout << "\nCongrats! We found your account\n";
			cout << "\nThe Password for '" << username << "' is: " << password << endl << endl;
			system("pause");
			return;
		}
		if (count == 0)
		{
			cout << "\nSorry! We could not find you account\n\n";
			system("pause");
			return;
		}
	}
	
}