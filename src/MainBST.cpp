/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

//struct node * add_node_spec(struct node *root, int data);
struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) 
		return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

int main(){

	//Use it for testing ,Creating BST etc

	struct node *root = NULL;
	int nums[10] = { 50, 25, 75, 30, 27, 60, 99, 53, 51, 57 };

	for (int i = 0; i < 10; i++){
		root = add_node_spec(root, nums[i]);
	}


	int *arr = BSTRighttoLeftRows(root);

	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);

	getchar();

}
