/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is
6                        <-- Copy this first
/ \
4  10                      <-- Copy this row next from 10 and next 4 ..
/ \   \
1   5   15                   <-- Order her is 15 ,5 ,1
\
17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int *array = NULL, l = 0;

void traverse(struct node* root, int level);
int height1(struct node* node);



int* BSTRighttoLeftRows(struct node* root)
{
	
	array = (int *)malloc(40*sizeof(int));
	

	if (root == NULL)
		return NULL;

	int h = height1(root);
	for (int i = 1; i <= h; i++)
		traverse(root, i);

	l = 0;
	return array;

}
void traverse(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		array[l++] = root->data;
	else if (level > 1)
	{
		traverse(root->right, level - 1);
		traverse(root->left, level - 1);
	}
}
int height1(struct node* node)
{
	if (node == NULL)
		return 0;
	else
	{

		int l = height1(node->left);
		int r = height1(node->right);

		if (l > r)
			return ++l;
		else
			return ++r;
	}
}