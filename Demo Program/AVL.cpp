#include <iostream>
#include <cstdlib>
#include <AVL.h>

using namespace std;



int AVL::AVL_Tree(){
	root = NULL;
	
	return 0;
}

int AVL::height(node* temp){
	int h = 0;
	
	if(temp != NULL){
		int left_height = height(temp -> left);
		int right_height = height(temp -> right);
		int max_height = max(left_height, right_height);
		h = max_height + 1;
	}
	
	return h;
}

int AVL::height_diff(node* temp){
	int left_height = height(temp -> left);
	int right_height = height(temp -> right);
	int b_factor = left_height - right_height;
	
	return b_factor;
}

node* AVL::rr_rotation(node* parent){
	node* temp;
	temp = parent -> right;
	parent -> right = temp -> left;
	temp -> left = parent;
	
	return temp;
}

node* AVL::ll_rotation(node* parent){
	node* temp;
	temp = parent -> left;
	parent -> left = temp -> right;
	temp -> right = parent;
	
	return temp;
}

node* AVL::lr_rotation(node* parent){
	node* temp;
	temp = parent -> left;
	parent -> left = rr_rotation(temp);
	
	return ll_rotation(parent);
}

node* AVL::rl_rotation(node* parent){
	node* temp;
	temp = parent -> right;
	parent -> right = ll_rotation(temp);
	
	return rr_rotation(parent);
}

node* AVL::balance(node* temp){
	int bal_factor = height_diff(temp);
	
	if(bal_factor > 1){
		if(height_diff(temp -> left) > 0){
			temp = ll_rotation(temp);
		}
		else {
			temp = rr_rotation(temp);
		}
	}
	else if(bal_factor < -1){
		if(height_diff(temp -> right) > 0){
			temp = rl_rotation(temp);
		}
		else {
			temp = rr_rotation(temp);
		}
	}
	
	return temp;
}

node* AVL::insertion(node* root, int value){
	if(root == NULL){
		root = new node;
		root -> data = value;
		root -> left = NULL;
		root -> right = NULL;
		
		return root;
	}
	else if(value < root -> data){
		root -> left = insertion(root -> left, value);
		root = balance(root);
	}
	else if(value >= root -> data){
		root -> right = insertion(root -> right, value);
		root = balance(root);
	}
	
	return root;
}

node* AVL::findMax(node* root){
	if(root == NULL){
		return NULL;
	}
	
	while(root -> right != NULL){
		root = root -> right;
	}
	
	return root;
}

node* AVL::deletion(node* root, int value){
	if(root == NULL){		
		return root;
	}
	else if(value < root -> data){
		root -> left = deletion(root -> left, value);
		root = balance(root);
	}
	else if(value > root -> data){
		root -> right = deletion(root -> right, value);
		root = balance(root);
	}
	else {
		if(root -> left == NULL && root -> right == NULL){
			delete root;
			root = NULL;
		}
		else if(root -> left == NULL){
			node* temp = root;
			root = root -> right;
			delete temp;
		}
		else if(root -> right == NULL){
			node* temp = root;
			root = root -> left;
			delete temp;
		}
		else {
			node* temp = findMax(root -> left);
			root -> data = temp -> data;
			root -> left = deletion(root -> left, temp -> data);
		}
	}
	
	return root;
}