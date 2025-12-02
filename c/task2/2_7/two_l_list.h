typedef struct node_s {
	struct node_s* prev;
	struct node_s* next;
	bool is_executable;
	int val;
	void* op;
} node;

node* get_left_bond(node* cur, node* l_edge) {
	if (!cur) return NULL;
	
	while(cur -> prev && cur -> prev != l_edge) {
		cur = cur -> prev;
	}

	return cur;
};

node* get_right_bond(node* cur, node* r_edge) {
	if (!cur) return NULL;
	while(cur -> next && cur -> next != r_edge) {
		cur = cur -> next;
	}

	return cur;
};

void remove_node(node* nd) {
	if (nd -> op) free(nd -> op);
	free(nd);
};

node* create_node() {
	node* result = malloc(sizeof(node));
	result -> prev = NULL;
	result -> next = NULL;
	result -> op = NULL;
	return result;
};
