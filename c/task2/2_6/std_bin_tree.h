#include <stdio.h>

typedef struct t_node_s {
	t_node* left;
	t_node* right;
} t_node;

typedef struct b_tree_s {
	t_node* root;

} b_tree;
