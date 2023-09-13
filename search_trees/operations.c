#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "treeOperations.h"

node*newnode(int data) {
	
		node* newnode = (node*)malloc(sizeof(node));
		if (newnode) {
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = NULL;
		return newnode;
	}
	else {
		return NULL;
	}
}

 node* insert(node* n1, int data){
	 node* n2 = NULL;
	 
	 if (n1 == NULL) {
		 return newnode(data);
	 }
	 else {
		 if (data <= n1->data) {
			 n2 = insert(n1->left, data);
			 n1->left = n2;
			 n2->parent = n1;
		 }
		 else {
			 n2 = insert(n1->right, data);
			 n1->right = n2;
			 n2->parent = n1;
		 }
	 }
	return n1;
}

 node* search(node*root, int data){
	 if (root == NULL || root->data == data) {
		 return root;
	 }
	 if (root->data < data) {
		 return search(root->right, data);
	 }
	 return search(root->left, data);
 }

 node* treedelete(node*root, node*n) {
	 node* x;
	 node* y;
	 if(n->left == NULL || n->right == NULL){
		x = n;
	 }
	 else {
		x = successor(n);
	 }
	 if (n->left != NULL) {
		y = n->left;
	 }
	 else {
		y = n->right;
	 }
	 if (y != NULL) {
		 y->parent = x->parent;
	 }
	 if(x->parent != NULL) {
		 root = y;
	 }
	 else {
		 if(x==x->parent->left) {
			x->parent->left = y;
		 }
		 else {
			x->parent->right = y;
		 }
		 if (x != n) {
			 n->data = x->data;
		 }
		 
	 }
	 return x;
 }

node*delete(node*root, int data){
	if (root == NULL) {
		return root;
   }
	if(data < root->data){
		root->left = delete(root->left, data);
	}
	else if(data > root->data) {
		root->right = delete(root->right, data);
	}
	else {
		if (root->left == NULL) {
			node* n = root->right;
			free(root);
			return n;
		}
		else if(root->right== NULL){
			node* n1 = root->left;
			free(root);
			return n1;
		}
		node* n2 = minimum(root->right);
		root->data = n2->data;
		root->right = delete(root->right,n2->data);
	}
	return root;
 }

 node*minimum(node*root){
	 if (root == NULL) {
		 return 0;
	 }
		 while (root && root->left != NULL){
			 root = root->left;
	 }
		 return root;
 }

 node* maximum(node*root){
	 if (root == NULL) {
		 return 0;
	 }
	 while (root && root->right != NULL) {
		 root = root->right;
	 }
	 return root;
 }

 node* successor(node*n){
	 if (n == NULL) {
		 printf("\nnode not found");
		 return 0;
	 }
	if (n->right != NULL) {
		return minimum(n->right);
	}
	node* parent;
	parent = n->parent;
	while(parent != NULL && n == parent->right) {
		n = parent;
		parent = n->parent;
	}
	return parent;
 }

node* predecessor(node*n){
	if(n == NULL){
		printf("\nnode not found");
		return 0;
	}
	if (n->left != NULL) {
		return maximum(n->left);
	}
	node* parent;
	parent = n->parent;
	while (parent != NULL && n == parent->left) {
		n = parent;
		parent = n->parent;
	}
	return parent;
}

int treedepth(node*root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int left = treedepth(root->left);
		int right = treedepth(root->right);
		if (left > right) {
			left = left + 1;
			return left;
		}
		else {
			right = right + 1;
			return right;
		}
	}
}
int treesize(node* root)
{
	if (root == NULL)
		return 0;
	else {
		int left = treesize(root->left);
		int  right = treesize(root->right);
		int treesize = (left + right + 1);
		return treesize;
	}
}

node* inorderwalk(node*root) {
	if(root != NULL) {
		inorderwalk(root->left);
		printf("\n%d", root->data);
		inorderwalk(root->right);
	}
	return root;
}