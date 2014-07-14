#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	struct node *right, *left;
};

node* add_node(int x) {
	node* root = new node();
	root->data = x;
	root->left = root->right = NULL;
	return root;
}
void inorder(node *root) {
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int height(node *root) {
	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

int diameter(node *root) {
	if(root == NULL) return 0;
	int hl = height(root->left);
	int hr = height(root->right);

	return max(diameter(root->left), max(diameter(root->left), 1+hl+hr));
}

int opt_diameter(node *root, int& height) {
	//bug in this algo!
	//:( need to do it myself
	//also I'm try git let's see what happens :)
	if(root == NULL) {
		height = 0;
		return height;
	}
	int ht_l = 0, ht_r = 0;
	int res = 0;
	res = opt_diameter(root->left, ht_l);
	res = max(res, opt_diameter(root->left, ht_r));
	height = 1+max(ht_l, ht_r);
	return max(1 + ht_l + ht_r, res);
}
int main() {
	node *root = add_node(5);
	root->left = add_node(7);
	root->right = add_node(9);
	root->right->left = add_node(33);
	root->right->left->right = add_node(88);
	root->right->left->right->left = add_node(22);
	root->right->right = add_node(19);
	root->right->right->left = add_node(3);
	inorder(root);
	int var = 0;
	cout << "The diameter of the tree is: " << diameter(root) << endl;
	cout << "The diameter of the tree(optimized) is: " << opt_diameter(root, var) << endl;
	return 0;
}
