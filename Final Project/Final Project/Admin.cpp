#include "Admin.h"
#include <iostream>
using namespace std;
Admin::Admin(){}

void Admin::Options()
{
    int choice = 1;
    while (choice != 0)
    {
        cout << "What do y want to do ?\n";
        cout << " [1] Add\n";
        cout << " [2] Stock\n";
        cout << " [3] Remove\n";
        cout << " [4] Search\n";
        cout << " [5] Modify\n";
        cout << " [6] Show Details\n";
        cout << " [7] Refill through Vendor";
        cout << " [0] Exit\n\n";
        cout << "Select an option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add();
            system("pause");
            system("cls");
            break;
        case 2:
            Stock();
            system("pause");
            system("cls");
            break;
        case 3:
            Remove();
            system("pause");
            system("cls");
            break;
        case 4:
            Search();
            system("pause");
            system("cls");
            break;
        case 5:
            Modify();
            system("pause");
            system("cls");
            break;
        case 6:
        ShowAllDetails();
        system("pause");
            system("cls");
            break;
        case 7:
            Refill();
            system("pause");
            system("cls");
            break;
        default:
            cout << "Invalid Input Enter Again";
            system("pause");
            system("cls");
            break; 
        }
        
    }
}

void Admin::Add()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "ADD PRODUCT\n\n";

    string code, name, category;
    double price;
    int quantity;

    cout << "Enter product code: ";
    getline(cin, code);

    cout << "Enter product name: ";
    getline(cin, name);

    cout << "Enter product category: ";
    getline(cin, category);

    cout << "Enter product price: ";
    while (!(cin >> price))
    {
        cout << "Invalid input. Please enter a valid price: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter product quantity: ";
    while (!(cin >> quantity))
    {
        cout << "Invalid input. Please enter a valid quantity: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    ofstream file("products.csv", ios::app);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    file << code << "," << name << "," << category << "," << price << "," << quantity << endl;
    file.close();

    cout << "Product added successfully!" << endl;
}

void Admin::Stock()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "UPDATE STOCK\n\n";

    string code;
    cout << "Enter the product code: ";
    cin.ignore();
    getline(cin, code);

    ifstream file("products.csv");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;

    ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        cout << "Error opening temp file!" << endl;
        return;
    }

    while (getline(file, line))
    {
        int pos = line.find(code);
        if (pos != string::npos)
        {
            found = true;

            int quantityStartPos = line.find_last_of(",");
            int quantity = stoi(line.substr(quantityStartPos + 1));

            int newQuantity;
            cout << "Current stock quantity: " << quantity << endl;
            cout << "Enter the new stock quantity: ";
            while (!(cin >> newQuantity))
            {
                cout << "Invalid input. Please enter a valid quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            line = line.substr(0, quantityStartPos + 1) + to_string(newQuantity);
        }

        tempFile << line << endl;
    }

    file.close();
    tempFile.close();

    if (remove("products.csv") != 0)
    {
        cout << "Error deleting file!" << endl;
        return;
    }

    if (rename("temp.csv", "products.csv") != 0)
    {
        cout << "Error renaming file!" << endl;
        return;
    }

    if (!found)
    {
        cout << "Product not found!" << endl;
        return;
    }

    cout << "Stock updated successfully!" << endl;
}

void Admin::Remove()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "REMOVE PRODUCT\n\n";

    string code;
    cout << "Enter the product code: ";
    cin.ignore();
    getline(cin, code);

    ifstream file("products.csv");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        cout << "Error opening file!" << endl;
        file.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line))
    {
        if (line.find(code) == string::npos)
        {
            tempFile << line << endl;
        }
        else
        {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    if (!found)
    {
        cout << "Product not found!" << endl;
        return;
    }

    remove("products.csv");
    rename("temp.csv", "products.csv");
    cout << "Product removed successfully!" << endl;
}

void Admin::Modify()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "MODIFY PRODUCT\n\n";

    string code;
    cout << "Enter the product code: ";
    cin.ignore();
    getline(cin, code);

    ifstream file("products.csv");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    ofstream tempFile("temp.csv");
    if (!tempFile)
    {
        cout << "Error opening file!" << endl;
        file.close();
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line))
    {
        if (line.find(code) == string::npos)
        {
            tempFile << line << endl;
        }
        else
        {
            found = true;

            cout << "Current details:\n";
            cout << line << endl;

            string newName;
            cout << "Enter the new name: ";
            getline(cin, newName);

            string newCategory;
            cout << "Enter the new category: ";
            getline(cin, newCategory);

            string newPrice;
            cout << "Enter the new price: ";
            while (!(cin >> newPrice))
            {
                cout << "Invalid input. Please enter a valid price: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            string newQuantity;
            cout << "Enter the new quantity: ";
            while (!(cin >> newQuantity))
            {
                cout << "Invalid input. Please enter a valid quantity: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            tempFile << code << ',' << newName << ',' << newCategory << ',' << newPrice << ',' << newQuantity << endl;
        }
    }

    file.close();
    tempFile.close();

    if (!found)
    {
        cout << "Product not found!" << endl;
        return;
    }

    if (remove("products.csv") != 0)
    {
        cout << "Error deleting file!" << endl;
        return;
    }

    if (rename("temp.csv", "products.csv") != 0)
    {
        cout << "Error renaming file!" << endl;
        return;
    }

    cout << "Product details modified successfully!" << endl;
}

void Admin::Search()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "SEARCH PRODUCT\n\n";

    string code;
    cout << "Enter the product code: ";
    cin.ignore();
    getline(cin, code);

    ifstream file("products.csv");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line))
    {
        if (line.find(code) != string::npos)
        {
            found = true;

            cout << "Product details:\n";
            cout << line << endl;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "Product not found!" << endl;
    }
}

void Admin::ShowAllDetails()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "ALL PRODUCT DETAILS\n\n";

    ifstream file("products.csv");
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void Admin::Refill()
{
    system("cls");
    cout << "\t\t\t\t\tFAST ONLINE SUPERMARKET PORTAL\n\n";
    cout << "REFILL REQUEST\n\n";

    string productCode, productName, vendorName, message;

    cout << "Enter product code: ";
    cin.ignore();
    getline(cin, productCode);

    cout << "Enter product name: ";
    getline(cin, productName);

    cout << "Enter vendor name: ";
    getline(cin, vendorName);

    cout << "Enter refill request message: ";
    getline(cin, message);

    ofstream refillFile("refill_requests.csv", ios::app);
    if (!refillFile)
    {
        cout << "Error creating file!" << endl;
        return;
    }

    refillFile << productCode << "," << productName << "," << vendorName << "," << message << endl;

    refillFile.close();

    cout << "Refill request sent successfully!" << endl;
}