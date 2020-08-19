/*
    harshvcode | hvsreal.223@gmail.com
    PROGRAM TO MERGE TWO LINKEDLISTS
*/
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
		Node *next;
};
void print(Node *node){
	while(node != NULL){
		cout << node->data << ' ';
		node=node->next;
	}
	cout << '\n';
}
void append(Node **head, int data){
	Node *newnode=new Node();
	newnode->data=data;
	newnode->next=NULL;
	if(*head == NULL){
		*head=newnode;
		return;
	}
	Node *last=*head;
	while(last->next != NULL) last=last->next;
	last->next=newnode;
}
void mergetwosortedll(Node *node1, Node *node2){
	while(node1->next != NULL) node1=node1->next;
	while(node2 != NULL){
		node1->next=node2;
		node1=node1->next;
		node2=node2->next;
	}
	node1->next=NULL;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Node *head=NULL;
	for(int i=1; i<11; i++) append(&head, i);
	Node *head2=NULL;
	for(int i=11; i<21; i++) append(&head2, i);
	mergetwosortedll(head, head2);
	print(head);
	return 0;
}
