#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
public:
    int id;
    string name;
    float price;
    int quantity;

    void input()
    {
        cout << "\n - - - Add new product - - -\n";
        cout << "Enter Product ID  : ";
        cin >> id;
        cout << "Enter Product name :";
        cin >> name;
        cout << "Enter Product price :";
        cin >> price;
        cout << "Enter Product quantity :";
        cin >> quantity;
    }

    void Display()
    {
        cout << left << setw(10) << id << setw(25) << name << setw(50) << price << setw(10) << quantity << setw(10) << price * quantity << endl;
    }

    float getTotal()
    {
        return price * quantity;
    }
};

int main()
{
    Product p[50];
    int count = 0, choice;

    do
    {
        cout << "\n================================\n";
        cout << "Welcome to Grocery Store Management\n";
        cout << "\n=================================\n";
        cout << "1. Add Product\n";
        cout << "2. Show Bill\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice :";
        cin >> choice;

        if (choice == 1)
        {
            p[count].input();
            count++;
            cout << "Product Added Successfully!\n";
        }
        else if (choice == 2)
        {
            if (count == 0)  // Check if no products are added
            {
                cout << "No Product to display.\n";
            }
            else
            {
                float totalbill = 0;
                cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(50) << "Price" << setw(10) << "Quantity" << setw(10) << "Total" << endl;
                cout << "------------------------------------------------------------------------------------------";
                for (int i = 0; i < count; i++)
                {
                    p[i].Display();
                    totalbill += p[i].getTotal();
                }
                cout << "------------------------------------------------------------------------------------------";
                cout << right << setw(40) << "Total Bill: ₹ " << totalbill << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Thanks for shopping with us!\n";
        }
        else
        {
            cout << "Invalid choice! Try again\n";
        }

    } while (choice != 3); 
    return 0;
}