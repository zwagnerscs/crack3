typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;

void insert(int key, node **leaf);

void print(node *leaf);

node *search(int key, node *leaf);
