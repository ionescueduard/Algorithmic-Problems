#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct Node {
	int val;
	struct Node *xor;
} Node;

void addNode(Node **root, int val) {
	Node *new = (Node*)malloc(sizeof(Node));
	new->val = val;
	
	if ((*root) == NULL) {
		new->xor = NULL;
		(*root) = new;
		return;
	}
	
	// only one node in the list
	if ((*root)->xor == NULL) {
		new->xor = (*root);
		(*root)->xor = new;
		return;
	}
	
	//there are more then one node in the list
	Node *p = (*root);
	Node *prev = NULL;
	Node *tmp;
	while(prev != p->xor) { // gets to the final node in *p
		tmp = p;
		p = (Node*) ((uintptr_t) p->xor ^ (uintptr_t) (prev == NULL ? 0 : prev));
		prev = p;
		printf("a");
	}
	printf("b");
	new->xor = p;
	p->xor = (Node*) ((uintptr_t) p->xor ^ (uintptr_t) new);
}

int getAt(Node *p, int index) {
	if (index == 0)
		return p->val;
	
	int i = 0;
	Node *prev = NULL;
	Node *tmp;
	while (i < index && prev != p->xor) {
		tmp = p;
		p = (Node*) ((uintptr_t) p->xor ^ (uintptr_t) (prev == NULL ? 0 : prev));
		prev = p;
		i++;
	}
	if(i != index)
		return -1;
	return p->val;
}

int main() {
	Node *root = NULL;
	addNode(&root, 1);
	addNode(&root, 2);
	addNode(&root, 3);
	//addNode(&root, 4);

	printf("%d\n", root->val);
	printf("%d\n", getAt(root, 0));
	printf("%d\n", getAt(root, 1));
	//printf("%d\n", getAt(root, 2));
	//printf("%d\n", getAt(root, 3));
	
}