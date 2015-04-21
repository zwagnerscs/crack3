#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

void insert(int key, node **leaf)
{
    if (*leaf == NULL)
    {
        *leaf = (node *) malloc(sizeof(node));
        (*leaf)->data = key;
        /* initialize the children to null */
        (*leaf)->left = NULL;    
        (*leaf)->right = NULL;  
    }
    else if (key < (*leaf)->data)
        insert (key, &((*leaf)->left) );
    else if (key > (*leaf)->data)
        insert (key, &((*leaf)->right) );
}

void print(node *leaf)
{
	if (leaf == NULL) return;
	if (leaf->left != NULL) print(leaf->left);
	printf("%d\n", leaf->data);
	if (leaf->right != NULL) print(leaf->right);
}

// TODO: Modify so the key is the hash to search for
node *search(int key, node *leaf)
{
  if (leaf != NULL)
  {
      if (key == leaf->data)
         return leaf;
      else if (key < leaf->data)
         return search(key, leaf->left);
      else
         return search(key, leaf->right);
  }
  else return NULL;
}

/*
int main()
{
    node *tree = NULL;
    
    insert(5, &tree);
    insert(2, &tree);
    insert(8, &tree);
    insert(10, &tree);
    insert(1, &tree);
    insert(4, &tree);
    insert(8, &tree);
    insert(7, &tree);

    print(tree);
}
*/
