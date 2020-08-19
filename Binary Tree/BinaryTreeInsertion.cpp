/*****Author	:	harshvcode*****/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define VT vector
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define SZ(x) (int)(x).size()
#define FR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define ECH(x, a) for (auto& x: a)
#define F first
#define S second
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randnum(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}
struct Node{
	int data;
	Node *left, *right;
	Node(int data){
		this->data=data;
		left=right=NULL;
	}
};
void inorder(Node *node){
	if(node == NULL) return;
	inorder(node->left);
	cout << node->data << ' ';
	inorder(node->right);
}
void insert(Node *node, int data){
	queue<Node*> q;
	q.push(node);
	while(! q.empty()){
		Node *temp=q.front();
		q.pop();
		if(temp->left == NULL){
			temp->left=new Node(data);
			break;
		}
		else q.push(temp->left);
		if(temp->right == NULL){
			temp->right=new Node(data);
			break;
		}
		else q.push(temp->right);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Node *root=new Node(1);
	root->left=new Node(2);
	root->left->left=new Node(3);
	root->right=new Node(4);
	root->right->left=new Node(5);
	root->right->right=new Node(6);
	inorder(root);
	cout << '\n';
	insert(root, 100);//this step checks for every node starting from root that: if any position(left or right) is empty, and sets 100 at there.
	inorder(root);
	return 0;
}
