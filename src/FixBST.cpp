/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void fixit(struct node* root, struct node** first, struct node** middle, struct node** last, struct node** temp);
void swap(int* a, int* b);

void fix_bst(struct node *root){

	struct node *first = NULL, *middle = NULL, *last = NULL, *temp = NULL;

	fixit(root, &first, &middle, &last, &temp);

	if (first && last)
		swap(&(first->data), &(last->data));
	else if (first && middle) 
		swap(&(first->data), &(middle->data));

}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void fixit(struct node* root, struct node** first,struct node** middle, struct node** last,struct node** temp)
{
	if (root)
	{
		fixit(root->left, first, middle, last, temp);

	
		if (*temp && root->data < (*temp)->data)
		{
			
			if (*first == NULL)
			{
				*first = *temp;
				*middle = root;
			}

			else
				*last = root;
		}

		*temp = root;

		fixit(root->right, first, middle, last, temp);
	}
}

