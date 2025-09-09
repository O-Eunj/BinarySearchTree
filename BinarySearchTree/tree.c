#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"
#include "queue.h"


Node* insert(Node* root, int data) {
	if (root == NULL) {
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = data;
		new_node->right = new_node->left = NULL;
		return new_node;
	}
	if (data > root->data) {
		root->right = insert(root->right, data);
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
	}
	return root;
}

Node* min_node(Node* root) {
	if (root == NULL) return NULL;
	while (root->left) root = root->left;
	return root;
}

Node* bst_delete(Node* root, int data) {
	if (root == NULL) return NULL;
	if (data > root->data) {
		root->right = bst_delete(root->right, data);
	}
	else if (data < root->data) {
		root->left = bst_delete(root->left, data);
	}
	else {
		if (root->right == NULL && root->left == NULL) {
			free(root);
			return NULL;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		else if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else {
			Node* temp = min_node(root->right);
			root->data = temp->data;
			root->right = bst_delete(root->right, temp->data);
		}
	}
	return root;
}

Node* find(Node* root, int data) {
	if (root == NULL) return NULL;
	if (data > root->data) {
		find(root->right, data);
	}
	else if (data < root->data) {
		find(root->left, data);
	}
	else if (data == root->data) {
		return root;
	}
}

/*void print_tree(Node* root) {
	if (root == NULL) return;
	print_tree(root->left);
	printf("%d ", root->data);
	print_tree(root->right);
}*/

/*void print_tree(Node* root, int depth) {
	if (root == NULL) return;
	print_tree(root->right, depth + 1);
	for (int i = 0; i < depth; i++) printf("    ");
	printf("%d\n", root->data);
	print_tree(root->left, depth + 1);
}*/

int depth_max(Node* root, int depth) {
	if (root == NULL) return depth;
	int left_depth = depth_max(root->left, depth + 1);
	int right_depth = depth_max(root->right, depth + 1);
	return (left_depth > right_depth) ? left_depth : right_depth;
}

void print_tree(Node* root) {
	if (root == NULL) return;

	int depth = depth_max(root, 0);

	//printf("%d\n", depth_max(root, 0));

	Queue q;
	init_queue(&q);
	push_queue(&q, root);
	
	while (!empty_queue(&q)) {
		int count = q.size;
		int space1 = (int)pow(2, depth - 1 ) - 1;
		int space2 = (int)pow(2, depth) - 1;
		depth--;
		for (int i = 0; i < space1; i++) {
			printf(" ");
		}
		while (count) {
			Node* node;
			pop_queue(&q, &node);
			count--;
			printf("%d", node->data);
			for (int i = 0; i < space2; i++) {
				printf(" ");
			}
			if (node->left) push_queue(&q, node->left);
			if (node->right) push_queue(&q, node->right);
		}
		printf("\n");
	}
}

Node* clear(Node* root) {
	if (root == NULL) return NULL;
	root->left = clear(root->left);
	root->right = clear(root->right);
	free(root);
	return NULL;
}