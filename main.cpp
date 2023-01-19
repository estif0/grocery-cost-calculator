/*
Team 4, section 13
1. Dina Mohammednur Seid UGR/26420/14
2. Tolawak Badasa Birasa UGR/26107/14
3. Estifanose Sahilu Kassaye UGR/25427/14
4. Nebil Esmael Suliyman UGR/25496/14
5. Jitunus Habte Shuma UGR/25636/14
*/

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int mainChoice, operationChoice; // Global variable that are needed for switch statment

struct Grocery // Structure for the items in file
{
    string itemName;
    float dailyIntake;
    float unitPrice;
    float monthlyIntake;
    float monthlyCost;
};

int countLine(string file) // Counts the amount of lines in a file
{
    string line;   // To read each line from code
    int count = 0; // Variable to keep count of each line
    ifstream mfile;
    mfile.open(file.c_str());
    if (mfile.is_open())
    {
        while (mfile.peek() != EOF)
        {
            getline(mfile, line);
            count++;
        }
        mfile.close();
        return count; // returns the amount of line in a file
    }
    else
        exit(1);
}

int sum(int total_num, int num) // Returns the sum of n integer numbers.
{
    int sum = num;
    for (int i = 0; i < total_num - 1; i++)
    {
        cout << "Please enter the numbers:";
        cin >> num;
        sum += num;
    }
    cout << "\nThe sum of these numbers is ";
    return sum;
}

int difference(int total_num, int num) // Returns the difference of n integers
{
    int difference = num;
    for (int i = 0; i < total_num - 1; i++)
    {
        cout << "Please enter the numbers:";
        cin >> num;
        difference -= num;
    }
    cout << "\nThe difference of these numbers is ";
    return difference;
}

int quotient(int total_num, int num) // Returns the quotient of n integers
{
    int quotient = num;
    for (int i = 0; i < total_num - 1; i++)
    {
        cout << "Please enter the numbers:";
        cin >> num;
        if (num != 0)
        {
            quotient /= num;
        }
        else
        {
            cout << "Can't divide number by zero!";
            break;
        }
    }
    cout << "\nThe quotient of these numbers is ";
    return quotient;
}

int product(int total_num, int num) // Returns the product of n integers
{
    int product = num;
    for (int i = 0; i < total_num - 1; i++)
    {
        cout << "Please enter the numbers:";
        cin >> num;
        product *= num;
    }
    cout << "\nThe product of these numbers is ";
    return product;
}

int modulo(int total_num) // Returns the modulo of n integers
{
    int num, modulo;
    cout << "Please enter the numbers:";
    cin >> modulo;
    for (int i = 0; i < total_num - 1; i++)
    {
        cout << "Please enter the numbers:";
        cin >> num;
        modulo %= num;
    }
    cout << "\nThe modulus of these numbers is ";
    return modulo;
}

float sqr_root_ofNumber(int num) // Returns the square root of a number
{
    if (num < 0)
    {
        cout << "You can't find the square root of a negative number!";
        return 0;
    }
    if (num < 2)
        return num;

    float y = num;
    float square_ofnumber = (y + (num / y)) / 2;

    while (abs(y - square_ofnumber) >= 0.00001)
    {
        y = square_ofnumber;
        square_ofnumber = (y + (num / y)) / 2;
    }
    return square_ofnumber;
}

void square(double num) // Returns the square of a number
{
    cout << "The square of " << num << " is " << num * num << endl;
}

void cube(double num) // Returns the cube of a number
{
    cout << "The cube of " << num << " is " << num * num * num << endl;
}

void grocery(string itemName, double daily_in_take, float costs) // Writes items, Daily intake and prices in to grocery.txt file
{
    ofstream groceryFile("grocery.txt", ios::app);
    if (groceryFile.is_open())
    {
        groceryFile << left << setw(14) << itemName << left << setw(22) << daily_in_take << left << setw(18) << costs << endl;
        groceryFile.close();
    }
    else
    {
        cout << "Check if the file exists!\n";
    }
}

void calc_monthly_in_take(ifstream &inFile)
{
    inFile.open("grocery.txt");
    string uselessLine;
    int loop = countLine("grocery.txt"); // counts the line of the grocery file
    Grocery coll[loop - 1];              // declares an array at the size of the number of lines in the text file minus the first line
    cout << "What month would you like to calculate? ";
    cout << "\n(1)January\n(2)February\n(3)March\n(4)April\n(5)May\n(6)June\n(7)July\n(8)August\n(9)September\n(10)October\n(11)November\n(12)December\n";
    int option, daysInMonth, year;
    cout << "Enter your choice: ";
    cin >> option; // Changes the number of days depending on the length of the month
    if (option == 1 || option == 3 || option == 5 || option == 7 || option == 8 || option == 10 || option == 12)
    {
        daysInMonth = 31;
    }
    else if (option == 4 || option == 6 || option == 9 || option == 11)
    {
        daysInMonth = 30;
    }
    else if (option == 2) // Since February can be either 28 or 29 depending on the year, the code below calculates leap year
    {
        cout << "What year is it? ";
        cin >> year;
        if (abs(year - 2020) % 4 == 0)
        {
            daysInMonth = 29;
        }
        else
        {
            daysInMonth = 28;
        }
    }
    else
    {
        cout << "Invalid Input\n";
    }

    if (inFile.is_open())
    {
        getline(inFile, uselessLine);      // removes the first line of the text file which is filled wit titles
        for (int i = 0; i < loop - 1; i++) // loop-1 is the limit since loop also contains the first line
        {
            inFile >> coll[i].itemName >> coll[i].dailyIntake >> coll[i].unitPrice;
            coll[i].monthlyIntake = coll[i].dailyIntake * daysInMonth;
            coll[i].monthlyCost = coll[i].dailyIntake * coll[i].unitPrice * daysInMonth;
        }
        inFile.close();
    }
    else
    {
        cout << "Error! Check if the file exists!\n";
    }

    ofstream out("grocery_cost.txt");
    if (out.is_open())
    {
        out << left << setw(14) << "Item" << left << setw(15) << "Daily_intake" << left << setw(12) << "Unit_price" << left << setw(16) << "Monthly_intake" << left << setw(14) << "Monthly_cost" << endl;
        for (int i = 0; i < loop - 1; i++)
        {
            out << left << setw(14) << coll[i].itemName << left << setw(15) << coll[i].dailyIntake << left << setw(12) << coll[i].unitPrice << left << setw(16) << coll[i].monthlyIntake << left << setw(14) << coll[i].monthlyCost << endl;
        }
        out.close();
    }
    else
    {
        cout << "Error! Check if the file exists!\n";
    }
}
void yearlyCost(ifstream &inFile)
{
    inFile.open("grocery_cost.txt");
    int loop = countLine("grocery_cost.txt"), daysInYear, currentYear;
    Grocery coll3[loop - 1];
    string uselessLine;
    if (inFile.is_open())
    {
        getline(inFile, uselessLine);
        for (int i = 0; i < loop - 1; i++)
        {
            inFile >> coll3[i].itemName >> coll3[i].dailyIntake >> coll3[i].unitPrice >> coll3[i].monthlyIntake >> coll3[i].monthlyCost;
        }
        cout << "What year is it?";
        cin >> currentYear;
        if (abs(currentYear - 2020) % 4 == 0)
        {
            daysInYear = 366;
        }
        else
        {
            daysInYear = 365;
        }
        for (int i = 0; i < loop - 1; i++)
        {
            cout << left << setw(14) << coll3[i].itemName << left << setw(20) << coll3[i].dailyIntake * coll3[i].unitPrice * daysInYear << endl;
        }
        float totalYearlyCost = 0;
        for (int i = 0; i < loop - 1; i++)
        {
            totalYearlyCost += coll3[i].dailyIntake * coll3[i].unitPrice * daysInYear;
        }
        cout << "The Total yearly cost of the year " << currentYear << " is " << totalYearlyCost << endl;
    }
    else
    {
        cout << "Check if the file exists!\n";
    }
}
float calcMonthlyCost(ifstream &inFile)
{
    inFile.open("grocery_cost.txt");
    int loop = countLine("grocery_cost.txt");
    Grocery coll2[loop - 1];
    string uselessLine;
    if (inFile.is_open())
    {
        getline(inFile, uselessLine);
        for (int i = 0; i < loop - 1; i++)
        {
            inFile >> coll2[i].itemName >> coll2[i].dailyIntake >> coll2[i].unitPrice >> coll2[i].monthlyIntake >> coll2[i].monthlyCost;
        }
        for (int i = 0; i < loop - 1; i++)
        {
            cout << left << setw(14) << coll2[i].itemName << left << setw(14) << coll2[i].monthlyCost << endl;
        }
        float totalMonthlyCost = 0;
        for (int i = 0; i < loop - 1; i++)
        {
            totalMonthlyCost += coll2[i].monthlyCost;
        }
        cout << "The total monthly cost is ";
        return totalMonthlyCost;
    }
    else
    {
        return 0;
    }
}

void menu() // Dispays the main menu for the program
{
    cout << "\nChoose one of the following options: \n";
    cout << "(1) Enter list of items to the text file. \n";
    cout << "(2) Calculate monthly amount of each item with their total costs and save it in a file.(This is only available after choice one is completed).\n";
    cout << "(3) Calculate each individual item's Monthly cost and display their total cost.\n";
    cout << "(4) Calculate each individual item's Yearly cost and display their total cost. \n";
    cout << "(5) Perform other basic calculations.\n";
    cout << "(6) Exit the program.\n";
    cout << "\nEnter your choice: ";
    cin >> mainChoice;
}
void operationMenu() // Displays operation menu for the program
{
    cout << "\nChoose one of the following operations: \n";
    cout << "(1) Addition \n";
    cout << "(2) Subtraction \n";
    cout << "(3) Multiplication \n";
    cout << "(4) Division \n";
    cout << "(5) Modulo \n";
    cout << "(6) Square root \n";
    cout << "(7) Square of a number \n";
    cout << "(8) Cube of a number \n";
    cout << "(9) Exit \n";
    cout << "\nEnter your choice: ";
    cin >> operationChoice;
}
int main()
{
    cout << "This program is designed to help Accountants.\n";
    do // Repeats the program until the user wants to exit
    {
        menu();
        switch (mainChoice)
        {
        case 1:
            cout << "\nDo you want to add new items to the existing file(If you have an existing one)(1) or start adding items into a new file (2): ";
            int option1;
            cin >> option1;
            if (option1 == 1)
            {
                cout << "How many items do you want to add?: ";
                int amountOfItems;
                cin >> amountOfItems;
                string itemName;
                double daily_in_take;
                float costs;
                cout << "When you enter the item name, add the unit in which the item is measured.\n For example: Oil(L), Carrot(KG),...\n";
                for (int i = 0; i < amountOfItems; i++)
                {
                    cout << "Enter the item name: ";
                    cin >> itemName;
                    cout << "Enter your daily intake of the above item per unit: ";
                    cin >> daily_in_take;
                    cout << "Enter the cost of above item per unit: ";
                    cin >> costs;
                    grocery(itemName, daily_in_take, costs);
                }
            }
            else if (option1 == 2)
            {
                cout << "How many items do you want to add?: ";
                int amountOfItems;
                cin >> amountOfItems;
                string itemName;
                double daily_in_take;
                float costs;
                cout << "When you enter the item name, add the unit in which the item is measured.\n For example: Oil(L), Carrot(KG),...\n";
                ofstream groceryFile("grocery.txt");
                if (groceryFile.is_open())
                {
                    groceryFile << left << setw(14) << "Item name" << left << setw(22) << "Daily intake in unit" << left << setw(18) << "Price per unit" << endl;
                    groceryFile.close();
                }
                for (int i = 0; i < amountOfItems; i++)
                {
                    cout << "Enter the item name: ";
                    cin >> itemName;
                    cout << "Enter your daily intake of the above item per unit: ";
                    cin >> daily_in_take;
                    cout << "Enter the cost of above item per unit: ";
                    cin >> costs;
                    grocery(itemName, daily_in_take, costs);
                }
            }
            break;
        case 2:
        {
            ifstream fin;
            calc_monthly_in_take(fin);
            cout << "Done! Check for the file 'grocery_cost.txt' in the folder where the program exists.\n";
            break;
        }
        case 3:
        {
            cout << endl;
            ifstream fin;
            cout << calcMonthlyCost(fin);
            cout << endl;
            break;
        }
        case 4:
        {
            cout << endl;
            ifstream fin;
            yearlyCost(fin);
            cout << endl;
            break;
        }
        case 5:
            do
            {
                cout << endl;
                operationMenu();
                switch (operationChoice)
                {
                case 1:
                    int totalSum, numSum;
                    cout << "How many number do you want to add? ";
                    cin >> totalSum;
                    cout << "Please enter the numbers:";
                    cin >> numSum;
                    cout << sum(totalSum, numSum);
                    break;
                case 2:
                    int totalDiff, numDiff;
                    cout << "How many number do you want to subtract? ";
                    cin >> totalDiff;
                    cout << "Please enter the numbers:";
                    cin >> numDiff;
                    cout << difference(totalDiff, numDiff);
                    break;
                case 3:
                    int totalProduct, numProduct;
                    cout << "How many number do you want to multiply? ";
                    cin >> totalProduct;
                    cout << "Please enter the numbers:";
                    cin >> numProduct;
                    cout << product(totalProduct, numProduct);
                    break;
                case 4:
                    int totalDiv, numDiv;
                    cout << "How many number do you want to divide? ";
                    cin >> totalDiv;
                    cout << "Please enter the numbers:";
                    cin >> numDiv;
                    cout << quotient(totalDiv, numDiv);
                    break;
                case 5:
                    int totalModulo;
                    cout << "How many numbers do you want to compute? ";
                    cin >> totalModulo;
                    cout << modulo(totalModulo);
                    break;
                case 6:
                    int numsqrt;
                    cout << "Enter the number you want the square root of: ";
                    cin >> numsqrt;
                    cout << sqr_root_ofNumber(numsqrt);
                    break;
                case 7:
                    int squareNum;
                    cout << "Enter the number you want the square of: ";
                    cin >> squareNum;
                    square(squareNum);
                    break;
                case 8:
                    int cubeNum;
                    cout << "Enter the number you want the cube of: ";
                    cin >> cubeNum;
                    cube(cubeNum);
                    break;
                case 9:
                    break;
                default:
                    cout << "Enter a valid choice\n";
                }
            } while (operationChoice != 9);
        case 6:
            break;
        default:
            cout << "Enter a valid choice\n";
        }
    } while (mainChoice != 6);
    return 0;
}
