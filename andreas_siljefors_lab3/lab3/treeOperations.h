#include <stdio.h>
#include <stdlib.h>

//operations
node*newnode(int data);
node*insert(node*newnode,int data);
node* search(node*root,int data);
node* minimum(node* root);
node* maximum(node*root);
node* delete(node*root,int data);
node* treedelete(node* root, node* n);
node* successor(node* n);
node* predecessor(node* n);
node* inorderwalk(node*n);
int treedepth(node*root);
int treesize(node* root);

//tests
int testinsert(node* root, int data);
int testsearch(node* root, int data);
int testminimum(node* root,int data);
int testmaximum(node* root, int data);
int testdelete(node* root, int data);
int testsuccessor(node* n,int data);
int testpredecessor(node* n, int data);
int testdepth(node*root,int data);
int testsize(node*root,int nodes);
void testTreeWalk(node* root);
