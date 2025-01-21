//#include<iostream>
//#include<string>
//#include<fstream>
//#include"Credentials.h"
//#include"Customer.h"
//#include"Items.h"
#include"Cart.h"
#include"Admin.h"
//using namespace std;
int main()
{
	int choice = 1, L_choice = 1, x = 0;
	char role;
	Cart c_obj; 
	Admin a_obj;
	cout << "\n\n\t\t\t\t\tWELCOME TO FAST ONLINE SUPERMARKET PORTAL\n\n";
	system("pause");
	system("cls");
	while (choice != 0)
	{
		cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
		cout << "Select A Role\n\n";
		cout << " [1] Customer\n";
		cout << " [2] Admin\n";
		cout << " [3] Vendor\n";
		cout << " [0] Exit\n";
		cout << "\nYour Choice: ";
		cin >> choice;
		L_choice = 1;
		switch (choice)
		{
		case 1:
			system("cls");
			role = 'C';
			while (L_choice != 0)
			{
				cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
				cout << "Role: Customer\n\n";
				cout << "Are you Registered?\n\n";
				cout << " [1] No! Register Now\n";
				cout << " [2] Yes! Login\n";
				cout << " [3] Forgot Password\n";
				cout << " [0] Back\n";
				cout << "\nYour Choice: ";
				cin >> L_choice;
				switch (L_choice)
				{
				case 1:
					c_obj.details();
					c_obj.setID(role);
					system("cls");
					c_obj.Options();
					system("cls");
					break;
				case 2:
					x = c_obj.verifyID(role);
					if (x == 1)
					{
						c_obj.Options();
					}
					system("cls");
					break;
				case 3:
					c_obj.forgot(role);
					system("cls");
					break;
				case 0:
					system("cls");
					break;
				default:
					cout << "\nInvalid Input, Choose Again.\n\n";
					system("pause");
					system("cls");
					break;
				}
			}
			system("cls");
			break;
		case 2:
			system("cls");
			role = 'A';
			while (L_choice != 0)
			{
				cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
				cout << "Role: Admin\n\n";
				cout << "Are you Registered?\n\n";
				cout << " [1] No! Register Now\n";
				cout << " [2] Yes! Login\n";
				cout << " [3] Forgot Password\n";
				cout << " [0] Back\n";
				
				
				cout << "\nYour Choice: ";
				cin >> L_choice;
				switch (L_choice)
				{
				case 1:
					a_obj.setID(role);
					system("cls");
					a_obj.Options();
					system("cls");
					break;
				case 2:
					x = a_obj.verifyID(role);
					if (x == 1)
					{
						a_obj.Options();
					}
					system("cls");
					break;
				case 3:
					a_obj.forgot(role);
					system("cls");
					break;
				case 0:
					system("cls");
					break;
				default:
					cout << "\nInvalid Input, Choose Again.\n\n";
					system("pause");
					system("cls");
					break;
				}
			}
			system("cls");
			break;
		case 3:
			system("cls");
			role = 'V';
			while (L_choice != 0)
			{
				cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
				cout << "Role: Vendor\n\n";
				cout << "Are you Registered?\n\n";
				cout << " [1] No! Register Now\n";
				cout << " [2] Yes! Login\n";
				cout << " [3] Forgot Password\n";
				cout << " [0] Back\n";
				cout << "\nYour Choice: ";
				cin >> L_choice;
				switch (L_choice)
				{
				case 1:


					system("cls");
					break;
				case 2:
					
					system("cls");
					break;
				case 3:
					
					system("cls");
					break;
				case 0:
					system("cls");
					break;
				default:
					cout << "\nInvalid Input, Choose Again.\n\n";
					system("pause");
					system("cls");
					break;
				}
			}
			system("cls");
			break;
		case 0:
			system("cls");
			cout << "\nTHANK YOU.......\n";
			break;
		default:
			cout << "\nInvalid Input, Choose Again.\n\n";
			system("pause");
			system("cls");
			break;
		}
	}
	
}