#ifndef AVL_H
#define AVL_H

	struct node{
		int data;
		node* left;
		node* right;
	}* root;

class AVL{

public:
	int AVL_Tree();
	int height(node*);
	int height_diff(node*);
	node* rr_rotation(node*);
	node* ll_rotation(node*);
	node* lr_rotation(node*);
	node* rl_rotation(node*);
	node* balance(node*);
	node* insertion(node*, int);
	node* findMax(node*);
	node* deletion(node*, int);
	
};

#endif /* AVL_H */