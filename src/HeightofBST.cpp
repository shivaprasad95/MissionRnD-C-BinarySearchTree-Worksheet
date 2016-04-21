/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int height(struct node *root);
int lsum(struct node *root);
int rsum(struct node *root);


int get_height(struct node *root){

	if (root == NULL)
		return 0;

	else {
		int h = height(root);

		return h;
	}
}

int get_left_subtree_sum(struct node *root){

	if (root == NULL)
		return 0;

	else{
		int l = lsum(root->left);

		return l;
	}
}
int get_right_subtree_sum(struct node *root){
	
	if (root == NULL)
		return 0;

	else{
		int r = rsum(root->right);

		return r;
	}
}


int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		
		int l = height(node->left);
		int r = height(node->right);

		if (l > r)
			return ++l;
		else 
			return ++r;
	}
}

int lsum(struct node *root)
{
	 int l = 0;

	 if (root == NULL)
		return 0;
	
	else
	{

		 l = root->data + lsum(root->left);
		
		return l;
	}


}

int rsum(struct node *root)
{
	int l = 0;

	if (root == NULL)
		return 0;

	else
	{

		l = root->data + rsum(root->right);

		return l;
	}


}