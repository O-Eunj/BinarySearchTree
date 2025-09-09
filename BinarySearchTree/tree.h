#ifndef TREE_H
#define TREE_H

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* insert(Node* root, int data);

Node* min_node(Node* root);

Node* bst_delete(Node* root, int data);

Node* find(Node* root, int data);

//void print_tree(Node* root);
void print_tree(Node* root, int depth);

Node* clear(Node* root);


#endif 
