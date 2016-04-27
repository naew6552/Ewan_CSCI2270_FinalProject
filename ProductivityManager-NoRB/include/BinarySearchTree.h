#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

struct Day
{
    int productivity, day, month, year;
    double sleep, exercise;
    std::string description;
    Day *parent = NULL, *left = NULL, *right = NULL;
    Day* previous = NULL, *next = NULL;

    Day(){}
    Day(int prodIn, double sleepIn, double exerciseIn, int dayIn, int monthIn, int yearIn, std::string descriptionIn)
    {
        productivity = prodIn;
        sleep = sleepIn;
        exercise = exerciseIn;
        day = dayIn;
        month = monthIn;
        year = yearIn;
        description = descriptionIn;
    }
    Day(int prodIn)
    {
        productivity = prodIn;
    }
};

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void displayMenu();
        int countDays();
        void deleteDay(int, int, int);
        void addDay(int);
        void addDay(int, double, double, int, int, int, std::string);
        void mostProd();
        void leastProd();
        void searchDay();
        void printDays(int, int, int, int, int, int);
        void printDays(int, int);
        void printAll();
    protected:

    private:
        void deleteAll(Day* ); //post order traversal of tree
        void printDays(Day*);
        void countDays(Day*, int*);
        void deleteDay(int);
        void stringOut(Day* node);
        void printDays(int, int, Day*);
        Day* searchDate(int, int, int);
        Day* searchProductivity(int);
        Day* minDay(Day*);
        Day* root;
        Day* first;
        Day* last;
};

#endif // BINARYSEARCHTREE_H
