#include <stdio.h>
#include <stdlib.h>

typedef struct t_node_s {
	int num;
	struct t_node_s* left;
	struct t_node_s* right;
	struct t_node_s* parent;
} t_node;

typedef struct b_tree_s {
	t_node* root;
} b_tree;

void error_alloc() {
	printf("Could no allocate new memory!\n");
	exit(-1);
}

void error_args() {
	printf("Bad arguments!\n");
	exit(-1);
}

t_node* init(int num) {
	t_node* res = malloc(sizeof(t_node));
	res -> left = NULL;
	res -> right = NULL;
	res -> parent = NULL;
	res -> num = num;
	return res;
}

void add_node(b_tree* tree, t_node* node) {
	if (!tree) return;
	if (!node) return;
	t_node* cur = tree -> root;
	if (!cur) {
		tree -> root = node;
		return;
	}
	
	int num = node -> num;
	t_node* prev = cur;
	bool is_right = true;
	while (cur) {
		prev = cur;
		if (num > cur -> num) {
			cur = cur -> right;
			is_right = true;
			continue;
		}

		if (num < cur -> num) {
			cur = cur -> left;
			is_right = false;
			continue;
		}

		if (num == cur -> num) error_args();
	}

	node -> parent = prev;
	if (is_right) {
		prev -> right = node;
	}
	else {
		prev -> left = node;
	}
};

void add_num(b_tree* tree, int num) {
	if (!tree) return;
	t_node* new_node = init(num);
	add_node(tree, new_node);
};

void add_subtree(b_tree* tree, t_node* node) {
	if (!tree) return;
	if (!node) return;
	t_node* left = node -> left;
	t_node* right = node -> right;
	node -> left = NULL;
	node -> parent = NULL;
	node -> right = NULL;
	add_node(tree, node);
	add_subtree(tree, left);
	add_subtree(tree, right);
};

t_node* find_in_subtree(t_node* cur, int num) {
	if (!cur) return NULL;
	if (cur -> num == num) return cur;
	t_node* left = find_in_subtree(cur -> left, num);
	if (left) return left;
	t_node* right = find_in_subtree(cur -> right, num);
	if (right) return right;
	return NULL;
};

t_node* find(b_tree* tree, int num) {
	if (!tree) return NULL;
	t_node* cur = tree -> root;
	if (!cur) return NULL;
	cur = find_in_subtree(cur, num);
	return cur;
};

void remove_num(b_tree* tree, int num) {
	t_node* node = find(tree, num);
	if (!node) return;
	t_node* left = node -> left;
	t_node* right = node -> right;
	if ( node -> parent && node -> parent -> left == node) {
		node -> parent -> left = NULL;
	}
	
	if (node -> parent && node -> parent -> right == node) {
		node -> parent -> right = NULL;
	}

	free(node);
	add_subtree(tree, left);
	add_subtree(tree, right);
};

void print_row(t_node** nodes, int count) {
	for (int i = 0; i < count; i++) {
		if (!nodes[i]) {
			printf(" |  null  |");
			continue;
		}

		printf("|  %d  |", nodes[i] -> num); 
	}

	printf("\n");
};

void collect_next_row(t_node** nodes, int count, t_node** result) {
	for (int i = 0; i < count; i++) {
		if (!nodes[i]) continue;
		result[2 * i] = nodes[i] -> left;
		result[2 * i + 1] = nodes[i] -> right;
	}
};

int two_exp(int exp) {
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result = result * 2;
	}
	
	return result;
};

t_node** init_row() {
	t_node** result = calloc(1, sizeof(t_node*));
	for (int i = 0; i < 100; i++) {
		result[i] = calloc(1, sizeof(t_node));
	}
};

void print_tree(b_tree* tree, int depth) {
	if (!tree) return;
	if (!tree -> root) return;
	t_node** cur_row = init_row();
	cur_row[0] = tree -> root;

	for (int i = 0; i < depth; i++) {
		print_row(cur_row, two_exp(i));
		t_node** next_row = init_row();
		collect_next_row(cur_row, two_exp(i + 1), next_row);
		for (int j = 0; j < 100; j++) {
			cur_row[j] = next_row[j];
		}

		free(next_row);
	}

	free(cur_row);
};

void clean_up_subtree(t_node* node) {
	if (!node) return;
	t_node* left = node -> left;
	t_node* right = node -> right;
	free(node);
	clean_up_subtree(left);
	clean_up_subtree(right);
}

void clean_up(b_tree* tree) {
	if (!tree) return;
	t_node* cur = tree -> root;
	free(tree);
	if (!cur) return;
	clean_up_subtree(cur);
};
