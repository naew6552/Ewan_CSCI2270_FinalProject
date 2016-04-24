#include "stdafx.h"
#include "RedBlackTree.h"


RedBlackTree::RedBlackTree()
{
	root = NULL;
}


RedBlackTree::~RedBlackTree()
{
}

void RedBlackTree::redBlackInsert(int productivity)
{
	Day* x = insertRB(productivity);
	while (x != root && x->parent->color != 'R')
	{
		if (x->parent == x->parent->parent->left)
		{
			Day* uncle = x->parent->parent->right;
			if (uncle->color == 'R')
			{
				x->parent->color = 'B';
				uncle->color = 'B';
				x->parent->parent->color = 'B';
				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->right)
				{
					x = x->parent;
					leftRotate(x);
				}
				x->parent->color = 'B';
				x->parent->parent->color = 'R';
				rightRotate(x);
			}
		}
		else
		{
			Day* uncle = x->parent->parent->left;
			if (uncle->color == 'R')
			{
				x->parent->color = 'B';
				uncle->color = 'B';
				x->parent->parent->color = 'B';
				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->left)
				{
					x = x->parent;
					rightRotate(x);
				}
				x->parent->color = 'R';
				x->parent->parent->color = 'R';
				leftRotate(x);
			}
		}
	}
}

void RedBlackTree::redBlackDelete(int)
{
}

Day * RedBlackTree::search(int)
{
	return nullptr;
}

void RedBlackTree::leftRotate(Day *)
{
}

void RedBlackTree::rightRotate(Day *)
{
}

Day* RedBlackTree::insertRB(int productivity)
{
	Day* newDay = new Day(productivity);
	Day* tmp = root;
	Day* parent = root;

	while (tmp != NULL)
	{
		parent = tmp;

		if (productivity < tmp->productivity)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp -> right;
		}
	}

	if (parent == NULL)
	{
		root = newDay;
	}
	else if (productivity < parent->productivity)
	{
		parent->left = newDay;
		newDay->parent = parent;
	}
	else
	{
		parent->right = newDay;
		newDay->parent = parent;
	}
	return newDay;
}

void RedBlackTree::rbBalance(Day *)
{
}

bool RedBlackTree::compare(Day * i, Day * j)
{
	return false;
}
