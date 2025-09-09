#include <stdio.h>
#include "tree.h"

int main() {
	int num, value;

	Node* node = NULL;

	while (1) {
		printf("MENU\n");
		printf("1.Insert\n");
		printf("2.Remove\n");
		printf("3.Find\n");
		printf("4.Print\n");
		printf("5.Clear\n");
		printf("0.Quit\n");
		printf("Enter your choice\n");
		scanf("%d", &num);

		switch (num) {

		case 1:
			printf("Insert: ");
			scanf("%d", &value);
			node = insert(node, value);
			printf("\n");
			break;

		case 2:
			printf("Remove: ");
			scanf("%d", &value);
			node = bst_delete(node, value);
			printf("\n");
			break;

		case 3:
			printf("Find: ");
			scanf("%d", &value);
			if (find(node, value) != NULL)
				printf("%d found\n", value);
			else
				printf("%d not found\n", value);
			printf("\n");
			break;

		case 4:
			if (node == NULL) {
				printf("Empty\n");
			}
			else {
				print_tree(node);
				//print_tree(node, 0);
				printf("\n");
			}
			break;

		case 5:
			node = clear(node);
			printf("tree cleared\n");
			break;

		case 0:
			printf("Exiting program\n");
			return 0;

		default:
			printf("Invalid choice\n");
			printf("\n");
		}
	}
	return 0;
}