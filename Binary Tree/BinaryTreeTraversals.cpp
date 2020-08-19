/*
BINARY TREE TRAVERSALS( INORDER , PREORDER, POSTORDER )
 __	__  __  	  __
|  |   |  | \ \          / /
|  |___|  |  \ \        / /
|  arsh   |   \ \      / /
|   ___   |    \ \____/ /
|  |   |  |     \ code /
|__|   |__|      \____/
*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* left,*right;
	Node(int data){
		this->data=data;
		left=right=NULL;
	}
};
void printPostorder(struct Node* node){
	if( node == NULL) return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data << ' ';
}
void printInorder(struct Node* node){
	if(node == NULL) return;
	printInorder(node->left);
	cout << node->data << ' ';
	printInorder(node->right);
}
void printPreorder(struct Node* node){
	if(node == NULL) return;
	cout << node->data << ' ';
	printPreorder(node->left);
	printPreorder(node->right);
}
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	cout << "\n Preorder traversal: ";
	printPreorder(root);
	cout << "\nPostorder traversal: ";
	printPostorder(root);
	cout << "\nInorder traversal: ";
	printInorder(root);
	cout << '\n';
	return 0;
}
