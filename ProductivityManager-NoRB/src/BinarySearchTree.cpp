#include "../include/BinarySearchTree.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
    first = NULL;
    last = NULL;
    string line;
    ifstream fileIn;
    fileIn.open("Save File");

    if(fileIn.is_open())
    {
        while(getline(fileIn, line))
        {
            string prodIn, dayIn, monthIn, yearIn, sleepIn, exerciseIn, descriptionIn;
            int productivity, day, month, year;
            double sleep, exercise;
            stringstream ss(line);
            getline(ss, prodIn, ',');
            getline(ss, dayIn, ',');
            getline(ss, monthIn, ',');
            getline(ss, yearIn, ',');
            getline(ss, sleepIn, ',');
            getline(ss, exerciseIn, ',');
            getline(ss, descriptionIn, ',');
            productivity = stoi(prodIn);
            day = stoi(dayIn);
            month = stoi(monthIn);
            year = stoi(yearIn);
            sleep = stod(sleepIn);
            exercise = stod(exerciseIn);
            addDay(productivity, sleep, exercise, day, month, year, descriptionIn);
        }
    }
}

BinarySearchTree::~BinarySearchTree()
{
    ofstream fileOut;
    fileOut.open("Save File");
    Day* tmp = root;
    while(tmp != NULL)
    {
        fileOut << tmp -> productivity << "," << tmp -> day << "," << tmp -> month << "," << tmp -> year << "," << tmp -> sleep << "," << tmp -> exercise << "," << tmp -> description << "," << endl;
        tmp = tmp -> next;
    }
}

void BinarySearchTree::addDay(int productivity)
{
    Day* dayIn = new Day(productivity);
    Day* parent = root;
    Day* tmp = root;

    while(tmp != NULL)
    {
        parent = tmp;
        if(productivity < tmp -> productivity)
        {
            tmp = tmp -> left;
        }
        else
        {
            tmp = tmp -> right;
        }
    }

    if(parent == NULL)
    {
        root = dayIn;
        first = dayIn;
    }
    else if(productivity < parent -> productivity)
    {
        parent -> left = dayIn;
        dayIn -> parent = parent;
        last -> next = dayIn;
        dayIn -> previous = last;
        last = last -> next;
    }
    else
    {
        parent -> right = dayIn;
        dayIn -> parent = parent;
        last -> next = dayIn;
        dayIn -> previous = last;
        last = last -> next;
    }
}

void BinarySearchTree::addDay(int productivity, double sleep, double exercise, int day, int month, int year, string description)
{
    Day* dayIn = new Day(productivity, sleep, exercise, day, month, year, description);
    Day* parent = root;
    Day* tmp = root;

    while(tmp != NULL)
    {
        parent = tmp;
        if(productivity < tmp -> productivity)
        {
            tmp = tmp -> left;
        }
        else
        {
            tmp = tmp -> right;
        }
    }

    if(parent == NULL)
    {
        root = dayIn;
        first = dayIn;
        last = dayIn;
    }
    else if(productivity < parent -> productivity)
    {
        parent -> left = dayIn;
        dayIn -> parent = parent;
        last -> next = dayIn;
        dayIn -> previous = last;
        last = last -> next;
    }
    else
    {
        parent -> right = dayIn;
        dayIn -> parent = parent;
        last -> next = dayIn;
        dayIn -> previous = last;
        last = last -> next;
    }
}

void BinarySearchTree::deleteDay(int productivity)
{
    Day* node = searchProductivity(productivity);
    Day* minNode = new Day();
    if(node != NULL && node != root)
    {
        if(node -> parent -> left == node)
        {
            if(node -> left == NULL && node -> right == NULL)
            {
                node -> parent -> left = NULL;
            }
            else if(node -> left != NULL && node -> right != NULL)
            {
                minNode = minDay(node -> right);
                if(minNode == node -> right)
                {
                    node -> parent -> left = minNode;
                    minNode -> parent = node -> parent;
                    minNode -> left = node -> left;
                }
                else
                {
                    minNode -> parent -> left = minNode -> right;
                    minNode -> parent = node -> parent;
                    if(minNode -> right != NULL)
                    {
                        minNode -> right -> parent = minNode -> parent;
                    }
                    node -> parent -> left = minNode;
                    minNode -> left = node -> left;
                    minNode -> right = node -> right;
                    node -> right -> parent = minNode;
                    node -> left -> parent = minNode;
                }
            }
            else if(node -> left == NULL)
            {
                Day* x = node -> right;
                node -> parent -> left = x;
                x -> parent = node -> parent;
            }
            else
            {
                Day* x = node -> left;
                node -> parent -> left = x;
                x -> parent = node -> parent;
            }
        }
        else if(node -> parent -> right == node)
        {
            if(node -> left == NULL && node -> right == NULL)
            {
                node -> parent -> right == NULL;
            }
            else if(node -> left != NULL && node -> right != NULL)
            {
                minNode = minDay(node -> right);
                if(minNode == node -> right)
                {
                    node -> parent -> right = minNode;
                    minNode -> parent = node -> parent;
                }
                else
                {
                    minNode -> parent -> left = minNode -> right;
                    minNode -> parent = node -> parent;
                    if(minNode -> right != NULL)
                    {
                        minNode -> right -> parent = minNode -> parent;
                    }
                    node -> parent -> right = minNode;
                    minNode -> left = node -> left;
                    minNode -> right = node -> right;
                    node -> right -> parent = minNode;
                    node -> left -> parent = minNode;
                }
            }
            else if(node -> left == NULL)
            {
                Day* x = node -> right;
                node -> parent -> right = x;
                x -> parent = node -> parent;
            }
            else
            {
                Day* x = node -> left;
                node -> parent -> right = x;
                x -> parent = node -> parent;
            }
        }
    }

    if(node == root)
    {
        minNode = minDay(node -> right);
        if(minNode == node -> right)
        {
            if(node -> left != NULL)
            {
                node -> left -> parent = minNode;
                root = minNode;
            }
        }
        else
        {
            minNode -> parent -> left = minNode -> right;
            if(minNode -> right != NULL)
            {
                minNode -> right -> parent = minNode -> parent;
            }
            minNode -> left = node -> left;
            minNode -> right = node -> right;
            node -> right -> parent = minNode;
            node -> left -> parent = minNode;
            root = minNode;
        }
    }

    cout << "f3" << endl;
    if(node == first)
    {
        cout << "f4" << endl;
        if(node -> next != NULL)
        {
            first = node -> next;
            node -> next -> previous = NULL;
        }
        else
        {
            first = NULL;
        }
        cout << "f5" << endl;
    }
    else if(node == last)
    {
        cout << "f6" << endl;
        last = node -> previous;
        node -> previous -> next = NULL;
        cout << "f7" << endl;
    }
    else
    {
        cout << "f8" << endl;
        node -> next -> previous = node -> next;
        node -> previous -> next = node -> previous;
        cout << "f9" << endl;
    }

    cout << "Deleting: " << node -> month << "/" << node -> day << "/" << node -> year << endl;
    delete node;
}

Day* BinarySearchTree::searchProductivity(int productivity)
{
    Day* tmp = root;
    while(tmp != NULL)
    {
        if(productivity < tmp -> productivity)
        {
            tmp = tmp -> left;
        }
        else if(productivity > tmp -> productivity)
        {
            tmp = tmp -> right;
        }
        else if(productivity == tmp -> productivity)
        {
            return tmp;
        }
    }
    std::cout << "Day not found." << std::endl;
    return NULL;
}

Day* BinarySearchTree::searchDate(int day, int month, int year)
{
    Day* tmp = first;

    while(tmp != NULL)
    {
        if(tmp -> day == day && tmp -> month == month && tmp -> year == year)
        {
            return tmp;
        }
        tmp = tmp -> next;
    }
    cout << "Day not found" << endl;
    return NULL;
}

Day* BinarySearchTree::minDay(Day* node)
{
    Day* tmp = node;
    Day* parent = node;
    while(tmp != NULL)
    {
        parent = tmp;
        tmp = tmp -> left;
    }
    return parent;
}

void BinarySearchTree::displayMenu()
{
    std::cout << "1. Add Day" << std::endl;
    std::cout << "2. Delete Day" << std::endl;
    std::cout << "3. Most Productive Day" << std::endl;
    std::cout << "4. Least Productive Day" << std::endl;
    std::cout << "5. Print Range of days by date" << std::endl;
    std::cout << "6. Print Range of days by productivity" << std::endl;
    std::cout << "7. Print All" << std::endl;
    std::cout << "8. Print Statistics" << endl;
    std::cout << "9. Quit" << std::endl;
}

void BinarySearchTree::mostProd()
{
    Day* tmp = root;
    Day* parent = root;
    while(tmp != NULL)
    {
        parent = tmp;
        tmp = tmp -> right;
    }

    cout << "Your most productive day was on:" << endl;
    cout << parent -> month << "/" << parent -> day << "/" << parent -> year << endl;
    cout << "Productivity was: " << endl;
    cout << parent -> productivity << endl;
}

void BinarySearchTree::leastProd()
{
    Day* tmp = root;
    Day* parent = root;
    while(tmp != NULL)
    {
        parent = tmp;
        tmp = tmp -> left;
    }

    cout << "Your least productive day was on:" << endl;
    cout << parent -> month << "/" << parent -> day << "/" << parent -> year << endl;
    cout << "Productivity was: " << endl;
    cout << parent -> productivity << endl;
}

void BinarySearchTree::deleteDay(int day, int month, int year)
{
    Day* tmp = first;
    while(tmp != NULL)
    {
        if(tmp -> day == day && tmp -> month == month && tmp -> year == year)
        {
            deleteDay(tmp -> productivity);
        }
        tmp = tmp -> next;
    }
}

void BinarySearchTree::printDays(int dayB, int monthB, int yearB, int dayE, int monthE, int yearE)
{
    Day* beginning = searchDate(dayB, monthB, yearB);
    Day* end = searchDate(dayE, monthE, yearE);
    Day* tmp = first;

    while(tmp != NULL)
    {
        if(tmp == beginning)
        {
            while(tmp != end)
            {
                stringOut(tmp);
                tmp = tmp -> next;
            }
            tmp = NULL;
        }
        else
        {
            tmp = tmp -> next;
        }
    }
}

void BinarySearchTree::printDays(int prodB, int prodE, Day* node)
{
    if(node -> left != NULL)
    {
        printDays(prodB, prodE, node);
    }

    if(node -> productivity < prodE && node -> productivity > prodB)
    {
        stringOut(node);
    }

    if(node -> right != NULL)
    {
        printDays(prodB, prodE, node -> right);
    }
}

void BinarySearchTree::printDays(int prodB, int prodE)
{
    printDays(prodB, prodE, root);
}

void BinarySearchTree::stringOut(Day* node)
{
    cout << "Date: " << node -> month << "/" << node -> day << "/" << node -> year << endl;
    cout << "Productivity: " << node -> productivity << ", Sleep: " << node -> sleep << ", Exercise: " << node -> exercise << endl;
    cout << "Description: " << node -> description << endl;
}

void BinarySearchTree::printAll()
{
    Day* tmp = first;
    while(tmp != NULL)
    {
        stringOut(tmp);
        tmp = tmp -> next;
    }
}

