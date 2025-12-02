#include <stdio.h>
#include <stdlib.h>
#include <two_l_list.h>

#define _STR_END_ '\0'
#define _EXP_END_ '='
#define _SPC_ ' '
// 001 010 100

#define _VAL_NUM_ 1
#define _VAL_KEY_ 2
#define _EXCESS_ 4

#define _OP_PLUS_ '+'
#define _OP_MINUS_ '-'
#define _OP_MULT_ '*'
#define _OP_DEV_ '/'
#define _OP_POW_ '^'
#define _OP_L_BRACK_ '('
#define _OP_R_BRACK_ ')'
#define _LF_ 0xa

typedef struct ex_context_s {
	node* beg;
	node* end;
	node* cursor;
} ex_context;

typedef struct tr_context_s {
	int num;
	char key;
	char excess;
	int val_type;
	bool can_continue;
} tr_context;

typedef struct operation_s {
	char key;
	short priority;
	bool is_left_assoc;
	node* (*execute)(node* l_bond, node* r_bond, node* cur);
} operation;

bool is_key(char symb) {
	switch (symb) {
		case _OP_L_BRACK_: case _OP_R_BRACK_: case _OP_PLUS_: 
		case _OP_MINUS_: case _OP_DEV_: case _OP_POW_: case _OP_MULT_:
			return true;
		default:
			return false;
	}
};

bool is_ascii_num(char symb) {
	bool result = symb > '0' && symb < '9';
	return result;
};

void finish_num(tr_context* ctx) {
	ctx -> val_type = _VAL_NUM_;
	ctx -> excess = _STR_END_;
	ctx -> key = _STR_END_;
};

void finish_key(tr_context* ctx, char cur) {
	ctx -> val_type = _VAL_KEY_;
	ctx -> key = cur;
	ctx -> num = 0;
	ctx -> excess = _STR_END_;
};

void finish_num_with_excess(tr_context* ctx, char cur) {
	ctx -> val_type = (_EXCESS_ | _VAL_NUM_);
	ctx -> excess = cur;
};

int to_int(char input) {
	int result = input - '0';
	return result;
};

void process_num(tr_context* ctx, char cur) {
	ctx -> val_type = _VAL_NUM_;
	ctx -> num = (ctx -> num) * 10 + to_int(cur);
};

bool get_lex(tr_context* ctx) {
	bool in_process = true;
	bool is_new = true;
	char cur = '#'; 
	while (in_process && cur != _EXP_END_ && ctx -> can_continue) {
		if ((ctx -> val_type & _EXCESS_) != _EXCESS_) {
			cur = getchar();
		}
		else {
			cur = ctx -> excess;
		}
		
		if (cur == _EXP_END_) ctx -> can_continue = false;
		if (is_new && (cur == _SPC_ || cur == _LF_)) continue;
		if (!is_new && (cur == _SPC_ || cur == _LF_ || cur == _EXP_END_) 
				&& ((ctx -> val_type & _VAL_NUM_) == _VAL_NUM_)) {
			finish_num(ctx);
			return true;
		}

		if (is_key(cur) && is_new) {
			finish_key(ctx, cur);
			return true;
		}
		
		if (is_key(cur) && !is_new
				&& ((ctx -> val_type & _VAL_NUM_) == _VAL_NUM_)) {
			finish_num_with_excess(ctx, cur);
			return true;
		}
		
		if (is_ascii_num(cur)) {
			is_new = false;
			process_num(ctx, cur);
			continue;
		}

		if (cur == _EXP_END_) return false;
	
		printf("Cannot process symb: %c\n", cur);
		exit(-1);
	}

	return false;
};

tr_context* init_translation_context() {
	tr_context* tr_ctx = malloc(sizeof(tr_context));
	tr_ctx -> num = 0;
	tr_ctx -> key = _STR_END_;
	tr_ctx -> excess = _STR_END_;
	tr_ctx -> can_continue = true;
	return tr_ctx;
};

void remove_translation_context(tr_context* t_ctx) {
	free(t_ctx);
};

ex_context* init_execution_context() {
	ex_context* e_ctx = malloc(sizeof(ex_context));
	e_ctx -> beg = NULL;
	e_ctx -> end = NULL;
	e_ctx -> cursor = NULL;
	return e_ctx;
};

void remove_execution_context(ex_context* e_ctx) {
	node* cur = e_ctx -> beg;
	while (cur) {
		node* tmp = cur;
		cur = cur -> next;
		remove_node(tmp);
	}

	free(e_ctx);
};

void remove_operation(operation* op) {
	free(op);
};

bool is_higher_priority(node* left, node* right) {
	if (!left || !right) {
		printf("Bad input!\n");
		exit(-1);
	}

	if (!left -> is_executable && right -> is_executable) return false;
	if (left -> is_executable && !right -> is_executable) return true;
	if (!left -> is_executable && !right -> is_executable) return true;
	operation* l_op = (operation*)left -> op;
	operation* r_op = (operation*)right -> op;
	if (l_op -> priority > r_op -> priority) return true;
	if (l_op -> priority < r_op -> priority) return false;
	if (l_op -> key != r_op -> key) return true;
	if (l_op -> is_left_assoc != r_op -> is_left_assoc) {
		printf("Bad input!\n");
		exit(-1);
	}
	
	if (l_op -> is_left_assoc) return true;
	if (!l_op -> is_left_assoc) return false;
	printf("Non implemented!\n");
	exit(-1);
};

node* get_highest_priority(node* beg, node* end) {
	if (!beg || !end) return NULL;
	node* cursor = beg -> next;
	node* result = beg;
	while (cursor && cursor != end -> next) {
		if (!is_higher_priority(result, cursor)) {
			result =  cursor;
		}

		cursor = cursor -> next;
	}

	return result;
};

int calculate_ctx(node* beg, node* end) {
	node* left = beg;
	node* right = end;
	node* l_edge = beg -> prev;
	node* r_edge = end -> next;
	node* cur = get_highest_priority(left, right);
	while (cur -> is_executable) {
		cur = (*((operation*)cur -> op) -> execute)(left, right, cur);
		left = get_left_bond(cur, l_edge);
		right = get_right_bond(cur, r_edge);
		cur = get_highest_priority(left, right);
	}
	
	int result = cur -> val;
	if (cur -> next) cur -> next -> prev = NULL;
	if (cur -> prev) cur -> prev -> next = NULL;
	remove_node(cur);
	return result;
};

void replace_range(node* beg, node* end, node* tgt) {
	tgt -> prev = beg -> prev;
	tgt -> next = end -> next;
	if (tgt -> prev) tgt -> prev -> next = tgt;
	if (tgt -> next) tgt -> next -> prev = tgt;
	node* cursor = end;
	while (cursor != beg && cursor) {
		node* tmp = cursor;
		cursor = cursor -> prev;
		remove_node(tmp);
	}
	
	if (beg) {
		remove_node(beg);
	}
};

node* execute_l_bracket(node* l_bond, node* r_bond, node* cur) {
	if (((operation*)cur -> op) -> key != _OP_L_BRACK_) {
		printf("Bad operation!\n");
		exit(-1);
	}

	node* cursor = cur -> next;
	node* start = cur;
	bool is_searching = true;
	while (cursor != r_bond && is_searching) {
		if (cursor -> is_executable
				&& ((operation*)cursor -> op) -> key == _OP_L_BRACK_) {
			cursor = execute_l_bracket(l_bond, r_bond, cursor);
		}

		if (cursor -> is_executable &&
				((operation*)cursor -> op) -> key == _OP_R_BRACK_) {
			is_searching = false;
			continue;
		}

		cursor = cursor -> next;
	}

	if (((operation*)cursor -> op) -> key != _OP_R_BRACK_) {
		printf("Not found r bracket!\n");
		exit(-1);
	}

	node* end = cursor;
	int result = calculate_ctx(start -> next, end -> prev);
	node* r_node = create_node();
	r_node -> is_executable = false;
	r_node -> val = result;
	replace_range(start, end, r_node);
	return r_node;
};

node* execute_r_bracket(node* start, node* end, node* cur) {
	printf("Closing not openned bracket!\n");
	exit(-1);
};

node* execute_plus(node* start, node* end, node* cur) {
	if (cur -> next -> is_executable || cur -> prev -> is_executable) {
		printf("Bad plus!\n");
		exit(-1);
	}
	
	int result = cur -> prev -> val + cur -> next -> val;
	node* r_node = create_node();
	r_node -> is_executable = false;
	r_node -> val = result;
	replace_range(cur -> prev, cur -> next, r_node);
	return r_node;
};

node* execute_minus(node* start, node* end, node* cur) {
	if (cur -> next -> is_executable || cur -> prev -> is_executable) {
		printf("Bad minus!\n");
		exit(-1);
	}

	int result = cur -> prev -> val - cur -> next -> val;
	node* r_node = create_node();
	r_node -> is_executable = false;
	r_node -> val = result;
	replace_range(cur -> prev, cur -> next, r_node);
	return r_node;
};

node* execute_mult(node* start, node* end, node* cur) {
	if (cur -> next -> is_executable || cur -> prev -> is_executable) {
		printf("Bad mult!\n");
		exit(-1);
	}

	int result = (cur -> prev -> val) * (cur -> next -> val);
	node* r_node = create_node();
	r_node -> is_executable = false;
	r_node -> val = result;
	replace_range(cur -> prev, cur -> next, r_node);
	return r_node;
};

node* execute_dev(node* start, node* end, node* cur) {
	if (cur -> next -> is_executable || cur -> prev -> is_executable) {
		printf("Bad dev!\n");
		exit(-1);
	}

	int result = (cur -> prev -> val) / (cur -> next -> val);
	node* r_node = create_node();
	r_node -> is_executable = false;
	r_node -> val = result;
	replace_range(cur -> prev, cur -> next, r_node);
	return r_node;
};

int calc_pow(int base, int exp) {
	int result = 1;
	for (int i = 0; i < exp; i++) {
		result = result * base;
	}

	return result;
};

node* execute_pow(node* start, node* end, node* cur) {
	if (cur -> next -> is_executable || cur -> prev -> is_executable) {
		printf("Bad pow!\n");
		exit(-1);
	}

	int result = calc_pow(cur -> prev -> val, cur -> next -> val);
	node* r_node = create_node();
	r_node -> is_executable = false;
	r_node -> val = result;
	replace_range(cur -> prev, cur -> next, r_node);
	return r_node;
};

int get_priority(char key) {
	switch (key) {
		case _OP_L_BRACK_: return 10;
		case _OP_POW_: return 8;
		case _OP_MULT_: return 7;
		case _OP_DEV_: return 5;
		case _OP_MINUS_: return 3;
		case _OP_PLUS_: return 2;
		case _OP_R_BRACK_: return 0;
		default:
			printf("No priority for %c", key);
			exit(-1);
	}
};

operation* get_operation(char key) {
	operation* result = malloc(sizeof(operation));
	switch (key) {
		case _OP_L_BRACK_:
			result -> key = _OP_L_BRACK_;
			result -> is_left_assoc = true;
			result -> priority = get_priority(key);
			result -> execute = &execute_l_bracket;
			return result;
		case _OP_R_BRACK_:
			result -> key = _OP_R_BRACK_;
			result -> is_left_assoc = true;
			result -> priority = get_priority(key);
			result -> execute = &execute_r_bracket;
			return result;
		case _OP_PLUS_:
			result -> key = _OP_PLUS_;
			result -> is_left_assoc = true;
			result -> priority = get_priority(key);
			result -> execute = &execute_plus;
			return result;
		case _OP_MINUS_:
			result -> key = _OP_MINUS_;
			result -> is_left_assoc = true;
			result -> priority = get_priority(key);
			result -> execute = &execute_minus;
			return result;
		case _OP_MULT_:
			result -> key = _OP_MULT_;
			result -> is_left_assoc = true;
			result -> priority = get_priority(key);
			result -> execute = &execute_mult;
			return result;
		case _OP_DEV_:
			result -> key = _OP_DEV_;
			result -> is_left_assoc = true;
			result -> priority = get_priority(key);
			result -> execute = &execute_dev;
			return result;
		case _OP_POW_:
			result -> key = _OP_POW_;
			result -> is_left_assoc = false;
			result -> priority = get_priority(key);
			result -> execute = &execute_pow;
			return result;
		default:
			printf("No operation for key %c", key);
			exit(-1);
	}
};

ex_context* get_ctx() {
	tr_context* tr_ctx = init_translation_context();
	ex_context* e_ctx = init_execution_context();
	bool need_set_beg = true;
	node* prev_node = NULL;

	while(get_lex(tr_ctx)) {
		node* cur_node = malloc(sizeof(node));
		if (prev_node) {
			prev_node -> next = cur_node;
			cur_node -> prev = prev_node;
		}

		if (need_set_beg) {
			e_ctx -> beg = cur_node;
			need_set_beg = false;
		}

		e_ctx -> end = cur_node;
		if ((tr_ctx -> val_type & _VAL_NUM_) == _VAL_NUM_) {
			cur_node -> op = NULL;
			cur_node -> is_executable = false;
			cur_node -> val = tr_ctx -> num;
		}
		else if (tr_ctx -> val_type == _VAL_KEY_) {
			cur_node -> is_executable = true;
			cur_node -> op = get_operation(tr_ctx -> key);
		}
		else {
			printf("Could not resolve operation for key %c and num %d",
					tr_ctx -> key, tr_ctx -> num);
			exit(-1);
		}

		prev_node = cur_node;
	}

	e_ctx -> cursor = e_ctx -> beg;
	remove_translation_context(tr_ctx);
	return e_ctx;
};
