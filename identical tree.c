// Program for finding if two trees are identical
// Hard coded tree can be changed as required
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
int isIden(struct node* root1, struct node* root2){
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;
	if(root1->data==root2->data){
		return isIden(root1->left, root2->left) && isIden(root1->right, root2->right);
	}
	return 0;
}
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8 
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);  

  struct node *root1 = newNode(1);
  root1->left        = newNode(2);
  root1->right       = newNode(3);
  root1->left->left  = newNode(4);
  root1->left->right = newNode(5);
  root1->right->left = newNode(8);  

  int t=isIden(root, root1);
  if(t==1)
  	printf("Identical");
  else
  	printf("Not identical");
  return 0;
}

