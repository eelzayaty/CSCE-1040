/*
*   Author: Ethan El-Zayaty (ethanel-zayaty@my.unt.edu)
*   Date: 01/23/2023
*   Instructor: Dr Maharjan
*   Description: Lab1: File inputs with arrays of structures
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
//structure to store customer data
struct Customer{
    int id;
    string name;
    double balance;
};

//struct to store employee data
struct Employee{
    int id;
    string name;
};

int main() {
    char type;
    //variables for transactions
    int employeeID;
    int custID;
    double amt;
    char transac;
    int eIndex;
    int cIndex;
    //counter variables
    int nextC = 0;
    int nextE = 0;
    //arrays of employees and customers
    Employee employees[50];
    Customer customers[50];

    ifstream fin;
    //make sure file exists
    fin.open("transactiondata");
    if(fin.fail()) {
        cout << "File Error.";
        exit(1);
    }
    //print title section
    cout << "************* Transaction Information *************" << endl;
    cout.setf(ios::right);
    cout << setw(15) << "Customer" << setw(15) << "Employee" << setw(10) << "Amount" << setw(10) << "Balance" << endl;
    cout << "___________________________________________________" << endl; 
    while (fin >> type)
    {
        switch(type) {
            case 'e': //enter new employee
                fin >> employees[nextE].id;
                fin >> employees[nextE].name;
                nextE++;
                break;
            case 'c': //enter new customer
                fin >> customers[nextC].id;
                fin >> customers[nextC].name;
                fin >> customers[nextC].balance;
                nextC++;
                break;
            case 't':
                //take in id of both customer and employee
                fin >> custID;
                fin >> employeeID;
                //take transaction type
                fin >> transac;
                //locate indexes of employee and customer
                for(int i = 0; i < nextC; i++) {
                    if(custID == customers[i].id) {
                        cIndex = i;
                    }
                }
                for (int i = 0; i < nextE; i++)
                {
                    if (employeeID == employees[i].id)
                    {
                        eIndex = i;
                    }
                }
                //take transaction amount
                fin >> amt;
                //complete transaction
                if(transac == 'w') { //withdraw
                    customers[cIndex].balance -= amt;
                }
                else { //deposit
                    customers[cIndex].balance += amt;
                }

                //print info
                cout << setw(15) << customers[cIndex].name << setw(15) << employees[eIndex].name;
                //add the '-' or '+' based on either withdraw or deposit
                if(transac == 'w') {
                    cout << setw(2) << " -$"  << setw(8) << amt;
                }
                else {
                    cout << setw(2) << " +$" << setw(8) << amt;
                }
                cout << fixed << setprecision(2) << setw(2) << "$" << setw(8) << customers[cIndex].balance << endl;
                break;
            default:
                cout << "Error.";
        }
    }

    return 0;
}