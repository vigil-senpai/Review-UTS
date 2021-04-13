// test UTS Case 2

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

//	Declaration

int unique;
int new_val;

int arr[1000] = {0};

struct Node {
	int idx;
	int val;
	int depth;
	Node* left;
	Node* right;
} *root;

Node* create_node(int idx, int val) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->val = val;
	temp->idx = idx;
	temp->depth = 0;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

//	Funct 1

Node* insert(Node* root, Node* node, int depth) {
	if(root == NULL) {
		root = node;
		root->depth = depth;
		unique = 1;
		return root;
	}
	if(node->idx < root->idx) {
		depth += 1;
		root->left = insert(root->left, node, depth);
		return root;
	}
	if(node->idx > root->idx) {
		depth += 1;
		root->right = insert(root->right, node, depth);
		return root;
	}
	if(node->idx == root->idx) {
		depth += 1;
		root->val += node->val;
		unique = 0;
		new_val = root->val;
		return root;
	}
}

//	Funct 2

void display(Node* root) {
	if(root == NULL) {
		return;
	}
	display(root->left);
	printf(">> Cave %d (depth %d), total gold production: %d\n", root->idx, root->depth, root->val);
	display(root->right);
}

//	Funct 3

void reports(Node* root) {
	if(root == NULL) {
		return;
	}
	reports(root->left);
	arr[root->depth] += root->val;
	reports(root->right);
}

//	Funct 4

void _delete(Node* root) {
	if(root == NULL) {
		return;
	}
	_delete(root->left);
	_delete(root->right);
	free(root);
}

//	Validation

bool index_validation(int index) {
	if(index >= 1 && index <= 999) {
		return 1;
	}
	return 0;
}

bool production_validation(int val) {
	if(val >= 1 && val <= 100) {
		return 1;
	}
	return 0;
}

//	Misc

void menu() {
	printf("Hov Mining Simulator\n");
	printf("====================\n");
	printf("[1] Insert Mining Data\n");
	printf("[2] Display All Cave Data\n");
	printf("[3] Display Mining Reports\n");
	printf("[4] Exit\n");
	printf(">> ");
}

int main() {
	while(1) {
		int opt;
		menu();
		scanf("%d", &opt);
		getchar();
		if(opt == 1) {
			int idx, val;
			system("CLS");
			
			do {
				printf("Input cave index [1-999]: ");
				scanf("%d", &idx);
				getchar();
			} while(index_validation(idx) == 0);
			
			do {
				printf("Input gold production [1-100]: ");
				scanf("%d", &val);
				getchar();
			} while(production_validation(val) == 0);
			
			unique = -1;
			
			root = insert(root, create_node(idx, val), 1);
			
			if(unique == 1) {
				printf("\nNew cave index detected.\n");
				printf("Total gold production for cave %d is %d.\n\n\n", idx, val);
				printf("Pres any key to continue...");
				getchar();
			}
			if(unique == 0) {
				printf("\nCave index already exists.\n");
				printf("New total gold production for cave %d is %d.\n\n\n", idx, new_val);
				printf("Pres any key to continue...");
				getchar();
			}
		}
		if(opt == 2) {
			system("CLS");
			if(root != NULL) {
				display(root);
			}
			else {
				printf("Cave data is empty, nothing to display\n\n");
			}
			printf("Pres any key to continue...");
			getchar();
		}
		if(opt == 3) {
			system("CLS");
			if(root != NULL) {
				for(int i = 0; i < 1000; i++) {
					arr[i] = 0;
				}
				reports(root);
				
				for(int i = 0; i < 1000; i++) {
					if(arr[i] != 0) {
						printf(">> Total gold production for depth %d	is %d\n", i, arr[i]);
					}
				}
			}
			else {
				printf("Cave data is empty, nothing to display\n\n");
			}
			printf("Pres any key to continue...");
			getchar();
		}
		if(opt == 4) {
			system("CLS");
			_delete(root);
			root = NULL;
			printf(" All data has been removed from memory.\n");
			printf(" Thank you for playing, see you again....\n");
			break;
		}
		system("CLS");
	}
	return 0;
}
