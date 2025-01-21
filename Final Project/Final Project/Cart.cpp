#include "Cart.h"

Cart::Cart() 
{
	cart_size = 0;
	total_bill = 0;
}

void Cart::AddItems()
{
	Items item;
	Display(item);
	my_cart[cart_size] = item;
	cart_size++;
	cout << "\nItem Added to Cart Successfuly!\n\n";
	system("pause");
}
void Cart::DisplayItems()
{
	cout << "\nCART\n\n";
	if (cart_size == 0)
	{
		cout << "Your Cart is Empty!\n";
	}
	else
		cout << "NO.\t\tSKU\t\tNAME\t\t\tCATEGORY\t\tPRICE($)\n\n";
	for (int i = 0; i < cart_size; i++)
	{
		cout << i + 1 << "\t\t" << my_cart[i].SKU << "\t\t" << my_cart[i].name << "\t\t" << my_cart[i].category << "\t\t" << my_cart[i].s_price << endl;
	}
	cout << endl;
	system("pause");
}
void Cart::RemoveItems()
{
	int x;
	cout << "\n\nREMOVE AN ITEM\n\n";
	cout << "NO.\t\tSKU\t\tNAME\t\t\tCATEGORY\t\tPRICE($)\n\n";
	for (int i = 0; i < cart_size; i++)
	{
		cout << i + 1 << "\t\t" << my_cart[i].SKU << "\t\t" << my_cart[i].name << "\t\t" << my_cart[i].category << "\t\t" << my_cart[i].s_price << endl;
	}
	cout << "\nWhich item do you want to remove? ";
	cin >> x;

	if (x >= 1 && x <= cart_size)
	{
		for (int i = x - 1; i < cart_size; i++)
		{
			my_cart[i] = my_cart[i + 1];
		}

		cart_size--;

		cout << "Item removed successfully.\n";
	}
	else
	{
		cout << "\nInvalid item number. Removal failed.\n\n";
	}
	system("pause");
}
void Cart::TotalPrice()
{
	float tt=0;
	for (int i = 0; i < cart_size; i++)
	{
		tt += my_cart[i].s_price;
	}
	total_bill = tt;
	cout << "\nYour total Bill is: $" << tt << endl << endl;
	system("pause");
}
void Cart::Search()
{
	string prod;
	int x;
	cout << "\nWhich category of product do you want to search in?\n";
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
	cin >> x;

	if (x >= 1 && x <= 10)
	{
		cout << "Enter the product name: ";
		cin.ignore();
		getline(cin, prod);

		string filename;

		if (x == 1)
		{
			filename = "FnM.txt";
		}
		else if (x == 2)
		{
			filename = "FF.txt";
		}
		else if (x == 3)
		{
			filename = "LnT.txt";
		}
		else if (x == 4)
		{
			filename = "Bak.txt";
		}
		else if (x == 5)
		{
			filename = "BnT.txt";
		}
		else if (x == 6)
		{
			filename = "FP.txt";
		}
		else if (x == 7)
		{
			filename = "Groc.txt";
		}
		else if (x == 8)
		{
			filename = "HnH.txt";
		}
		else if (x == 9)
		{
			filename = "PC.txt";
		}
		else if (x == 10)
		{
			filename = "PnW.txt";
		}

		ifstream file(filename);
		if (!file)
		{
			cout << "\nError: Unable to open the product file.\n";
			return;
		}

		string line;
		bool found = false;
		while (getline(file, line))
		{
			stringstream ss(line);
			string sku, name, category, price;
			getline(ss, sku, ',');
			getline(ss, name, ',');
			getline(ss, category, ',');
			getline(ss, price);

			if (name.find(prod) != string::npos)
			{
				found = true;
				cout << "\nProduct Found:\n";
				cout << "SKU: " << sku << endl;
				cout << "Name: " << name << endl;
				cout << "Category: " << category << endl;
				cout << "Price: $" << price << endl;
				cout << "Product Added to Cart\n";
				my_cart[cart_size].SKU = sku;
				my_cart[cart_size].name = name;
				my_cart[cart_size].category = category;
				my_cart[cart_size].s_price = 8.45;
				cart_size++;

				break;
			}
		}

		if (!found)
		{
			cout << "\nProduct not found in the selected category.\n";
		}

		file.close();
	}
	else
	{
		cout << "\nInvalid Selection. Choose Again.\n\n";
	}
	system("pause");
}

void Cart::PlaceOrder()
{
	if (cart_size != 0)
	{
		cout << "\n\nDATE\t\t\tTIME\n\n";
		cout << __DATE__ << "\t\t" << __TIME__ << endl;
		cout << "\nOrder Placed!!!\n";
		cout << "\nIt will be shipped in 2 Days\n";
		cout << "\nInvoice Generated\n\n";
		ofstream z1("Invoice.txt", ios::app);
        cout << "NO.\t\tSKU\t\tNAME\t\t\tCATEGORY\t\tPRICE($)\n\n";
			for (int i = 0; i < cart_size; i++)
			{
				cout << i + 1 << "\t\t" << my_cart[i].SKU << "\t\t" << my_cart[i].name << "\t\t" << my_cart[i].category << "\t\t" << my_cart[i].s_price << endl;
				z1 << i + 1 << ',' << my_cart[i].SKU << ',' << my_cart[i].name << ',' << my_cart[i].category << ',' << my_cart[i].s_price << ',';
			}
			TotalPrice();
			z1 << total_bill << endl;
	}
	else
	{
		cout << "\nYour Cart is empty!\n\n";
		system("pause");
	}
}
void Cart::Options()
{
	int choice = 1;
	while (choice != 0)
	{
		cout << "What do y want to do ?\n";
		cout << " [1] Place Order\n";
		cout << " [2] Add item to cart\n";
		cout << " [3] Display cart\n";
		cout << " [4] Search Item\n";
		cout << " [5] Remove an item from cart\n";
		cout << " [6] See your total bill\n";
		cout << " [0] Exit\n\n";
		cout << "Select an option: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			PlaceOrder();
			system("cls");
			break;
		case 2:
			AddItems();
			system("cls");
			break;
		case 3:
			DisplayItems();
			system("cls");
			break;
		case 4:
			Search();
			system("cls");
			break;
		case 5:
			RemoveItems();
			system("cls");
			break;
		case 6:
			TotalPrice();
			system("cls");
			break;
		}
	}
}
Cart::~Cart(){}