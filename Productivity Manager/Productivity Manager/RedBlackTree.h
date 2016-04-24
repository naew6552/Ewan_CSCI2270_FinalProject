#pragma once

struct Day
{
	int productivity;
	char color = 'R';
	Day* left = NULL;
	Day* right = NULL;
	Day* parent = NULL;

	Day(){}
	Day(int productivityIn)
	{
		productivity = productivityIn;
	}
};

class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();
	void redBlackInsert(int);
	void redBlackDelete(int);
	Day* search(int);

private:
	Day* root;
	void leftRotate(Day*);
	void rightRotate(Day*);
	Day* insertRB(int);
	void rbBalance(Day*);
	bool compare(Day* i, Day* j);
};

