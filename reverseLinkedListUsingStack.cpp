#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(arr) arr.begin(),arr.end()
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;
class Node{
	public:
		int data;
		Node* next;
};
void push(Node** head, int data){
	Node *newnode=new Node();
	newnode->data=data;
	newnode->next=*head;
	*head=newnode;
}
void print(Node* node){
	while(node != NULL){
		cout << node->data << ' ';
		node=node->next;
	}
	cout << '\n';
}
void rev(Node *node){
	//PROGRAM TO REVERSE A LINKED LIST USING STACK
	Node *t=node;
	stack<int> st;
	while(t != NULL){
		st.push(t->data);
		t=t->next;
	}
	while(node != NULL){
		node->data=st.top();
		st.pop();
		node=node->next;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Node *head=NULL;
	for(int i=1 ;i <11; i++) push(&head, i);
	print(head);
	rev(head);
	cout << "After reversing: ";
	print(head);
	return 0;
}