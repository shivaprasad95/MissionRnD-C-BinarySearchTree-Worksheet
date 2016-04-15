/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorderTraversal(struct node *root, int *arr);
void preorderTraversal(struct node *root, int *arr);
void postorderTraversal(struct node *root, int *arr);

int i = 0, j = 0, k = 0;


void inorder(struct node *root, int *arr){

	if (root == NULL || arr == NULL)
	{
		arr = NULL;
		return;
	}
	else
		inorderTraversal(root, arr);

	i = 0;

}
void preorder(struct node *root, int *arr){
	
	if (root == NULL || arr == NULL)
	{
		arr = NULL;
		return;
	}
	else
		preorderTraversal(root, arr);

	j = 0;
}
void postorder(struct node *root, int *arr){
	
	if (root == NULL || arr == NULL)
	{
		arr = NULL;
		return;
	}
	else
		postorderTraversal(root, arr);

	k = 0;
}

void inorderTraversal(struct node *root, int *arr1)
{
	
	if (root == NULL) {
		return;
	}

	inorderTraversal(root->left, arr1);

	arr1[i++] = root->data;

	inorderTraversal(root->right, arr1);

}

void preorderTraversal(struct node *root, int *arr2)
{
	
	if (root == NULL) {
		return;
	}

	arr2[j++] = root->data;

	preorderTraversal(root->left, arr2);

	preorderTraversal(root->right, arr2);
}

void postorderTraversal(struct node *root, int *arr3)
{
	
	if (root == NULL) {
		return;
	}

	postorderTraversal(root->left, arr3);

	postorderTraversal(root->right, arr3);

	arr3[k++] = root->data;
}