#include <iostream>
#include <sstream>
#include <string>
#include "include/BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree b;
    int intIn;
    string strIn;

    while(intIn != 9)
    {
        b.displayMenu();

        getline(cin, strIn);
        stringstream ss(strIn);
        ss >> intIn;

        switch(intIn)
        {
        case 1: //Add day
            {
                string prodIn, sleepIn, exerciseIn, dayIn, monthIn, yearIn, description;
                int prod, day, month, year;
                double sleep, exercise;
                cout << "Enter how productive you were out of 100" << endl;
                getline(cin, prodIn);
                cout << "Enter how many hours of sleep you got the previous night" << endl;
                getline(cin, sleepIn);
                cout << "Enter how many hours of exercise you complete today" << endl;
                getline(cin, exerciseIn);
                cout << "Enter a brief description of relevant information:" << endl;
                getline(cin, description);
                cout << "Enter the day in the form DD" << endl;
                getline(cin, dayIn);
                cout << "Enter the month in the form MM" << endl;
                getline(cin, monthIn);
                cout << "Enter the year in the form YYYY" << endl;
                getline(cin, yearIn);
                prod = stoi(prodIn);
                day = stoi(dayIn);
                month = stoi(monthIn);
                year = stoi(yearIn);
                sleep = stod(sleepIn);
                exercise = stod(exerciseIn);

                b.addDay(prod, sleep, exercise, day, month, year, description);

                break;
            }
        case 2: //Delete Day
            {
                string dayIn, monthIn, yearIn;
                int day, month, year;
                cout << "Enter the day in the form DD" << endl;
                getline(cin, dayIn);
                cout << "Enter the month in the form MM" << endl;
                getline(cin, monthIn);
                cout << "Enter the year in the form YYYY" << endl;
                getline(cin, yearIn);
                day = stoi(dayIn);
                month = stoi(monthIn);
                year = stoi(yearIn);
                b.deleteDay(day, month, year);

                break;
            }
        case 3: //Most Productive Day
            {
                b.mostProd();
                break;
            }
        case 4: //Least Productive Day
            {
                b.leastProd();
                break;
            }
        case 5: //Print Range of days by date
            {
                string date1, date2;
                int dateBeginning, dateEnding;
                cout << "Enter the beginning date: " << endl;
                getline(cin, date1);
                cout << "Enter the ending date: " << endl;
                getline(cin, date2);
                dateBeginning = stoi(date1);
                dateEnding = stoi(date2);
                b.printDays(dateBeginning, dateEnding);
                break;
            }
        case 6: //Print Range of days by productivity
            {
                string prod1, prod2;
                int prodBeginning, prodEnding;
                cout << "Enter the beginning productivity: " << endl;
                getline(cin, prod1);
                cout << "Enter the ending productivity: " << endl;
                getline(cin, prod2);
                prodBeginning = stoi(prod1);
                prodEnding = stoi(prod2);
                b.printDays(prodBeginning, prodEnding);
                break;
            }
        case 7: // Print All
            {
                b.printAll();
                break;
            }
        case 8: //Print Statistics
            {
                break;
            }
        case 9: //Quit
            {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }

    return 0;
}
