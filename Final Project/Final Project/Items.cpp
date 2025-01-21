#include "Items.h"

Items::Items(){}

void Items::Display(Items& item)
{
	system("cls");
	int choice = 1, count = 0, select = 0, x;
	Items *arr=new Items[30];
	ifstream x1("FnM.txt"), x2("FF.txt"), x3("LnT.txt"), x4("Bak.txt"), x5("BnT.txt"), x6("FP.txt"), x7("Groc.txt"), x8("HnH.txt"), x9("PC.txt"), x10("PnW.txt");
	cout << "\nCATEGORIES\n\n";
	cout << "[1] FISH & MEAT\n";
	cout << "[2] FROZEN FOOD\n";
	cout << "[3] LIQUOR & TOBACCO\n";
	cout << "[4] BAKERY\n";
	cout << "[5] BABY & TODDLER\n";
	cout << "[6] FRESH PRODUCE\n";
	cout << "[7] GROCERIES\n";
	cout << "[8] HOUSEHOLD & HOMECARE\n";
	cout << "[9] PERSONAL CARE\n";
	cout << "[10] PHARMA & WELLNESS\n\n";
	cout << "Choose a Category: ";
	cin >> choice;

	cout << "\nNO.\t\tSKU\t\tNAME\t\t\tCATEGORY\t\tPRICE($)\n";
	switch (choice)
	{
	case 1:
		while (!x1.eof())
		{
			getline(x1, arr[count].SKU, ',');
			getline(x1, arr[count].name, ',');
			getline(x1, arr[count].category, ',');
			x1 >> arr[count].s_price;
			x1.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x1.close();
		count = 0;
		cout << endl;
		break;
	case 2:
		while (!x2.eof())
		{
			getline(x2, arr[count].SKU, ',');
			getline(x2, arr[count].name, ',');
			getline(x2, arr[count].category, ',');
			x2 >> arr[count].s_price;
			x2.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x2.close();
		count = 0;
		cout << endl;
		break;
	case 3:
		while (!x3.eof())
		{
			getline(x3, arr[count].SKU, ',');
			getline(x3, arr[count].name, ',');
			getline(x3, arr[count].category, ',');
			x3 >> arr[count].s_price;
			x3.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x3.close();
		count = 0;
		cout << endl;
		break;
	case 4:
		while (!x4.eof())
		{
			getline(x4, arr[count].SKU, ',');
			getline(x4, arr[count].name, ',');
			getline(x4, arr[count].category, ',');
			x4 >> arr[count].s_price;
			x4.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x4.close();
		count = 0;
		cout << endl;
		break;
	case 5:
		while (!x5.eof())
		{
			getline(x5, arr[count].SKU, ',');
			getline(x5, arr[count].name, ',');
			getline(x5, arr[count].category, ',');
			x5 >> arr[count].s_price;
			x5.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x5.close();
		count = 0;
		cout << endl;
		break;
	case 6:
		while (!x6.eof())
		{
			getline(x6, arr[count].SKU, ',');
			getline(x6, arr[count].name, ',');
			getline(x6, arr[count].category, ',');
			x6 >> arr[count].s_price;
			x6.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x6.close();
		count = 0;
		cout << endl;
		break;
	case 7:
		while (!x7.eof())
		{
			getline(x7, arr[count].SKU, ',');
			getline(x7, arr[count].name, ',');
			getline(x7, arr[count].category, ',');
			x7 >> arr[count].s_price;
			x7.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x7.close();
		count = 0;
		cout << endl;
		break;
	case 8:
		while (!x8.eof())
		{
			getline(x8, arr[count].SKU, ',');
			getline(x8, arr[count].name, ',');
			getline(x8, arr[count].category, ',');
			x8 >> arr[count].s_price;
			x8.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x8.close();
		count = 0;
		cout << endl;
		break;
	case 9:
		while (!x9.eof())
		{
			getline(x9, arr[count].SKU, ',');
			getline(x9, arr[count].name, ',');
			getline(x9, arr[count].category, ',');
			x9 >> arr[count].s_price;
			x9.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x9.close();
		count = 0;
		cout << endl;
		break;
	case 10:
		while (!x10.eof())
		{
			getline(x10, arr[count].SKU, ',');
			getline(x10, arr[count].name, ',');
			getline(x10, arr[count].category, ',');
			x10 >> arr[count].s_price;
			x10.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n [" << count + 1 << "] \t\t" << arr[count].SKU << "\t\t" << arr[count].name << "\t\t\t" << arr[count].category << "\t\t" << arr[count].s_price;
			count++;
		}
		x10.close();
		count = 0;
		cout << endl;
		break;
	default:
		cout << "Invalid input, Enter Again\n";
		break;
	}
	cout << "\nChoose an item you want to add to cart: ";
	cin >> x;
	item = arr[x - 1];
	delete[] arr;
}
