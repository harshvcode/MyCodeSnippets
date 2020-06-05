/*
 * author: harshvcode|harshvsingh.223@gmail.com
 */
#include <bits/stdc++.h>
#define mod 1000000007
#define nl '\n'
#define lol long long
#define pb push_back
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
void append(Node** head_ref,int new_data){
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
	}
	Node* last=*head_ref;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=new_node;
	new_node->next=NULL;
}
void push(Node** head_ref,int new_data){
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
int sumElem(Node* node,int sum=0){
	cout<<"Sum: ";
	while(node!=NULL){
		sum+=node->data;
		node=node->next;
	}
	return sum;
}
void popback(Node* node){
	while(node->next->next!=NULL){
		node=node->next;
	}
	node->next=NULL;
}
void popfront(Node** head_ref,Node* node){
	*head_ref=node->next;
}
void traverse(Node* node){
	cout<<"traverse: ";
	while(node!=NULL){
		cout<<node->data<<' ';
		node=node->next;
	}
	cout<<nl;
}
int size_of_ll(Node* node){
	int ans=0;
	while(node!=NULL){
		ans++;
		node=node->next;
	}
	return ans;
}
void insertAfterValue(Node* node,int aftvalue){
	Node* new_node=new Node();
	int newval;
	cout<<"Enter Value to insert: ";
	cin>>newval;
	//cout<<"hey "<<newval<<nl;
	new_node->data=newval;
	while(node!=NULL){
		if(node->data == aftvalue){
			Node* temp=node->next;
			node->next=new_node;
			new_node->next=temp;
			return;
		}
		node=node->next;
	}
	cout<<"The value you entered doesn't exist, so insertion failed\n";
}
void BubbleSort(Node* head){
	int len=size_of_ll(head);
	int i=0,j=0;
	for(Node* inode=head ; i<len-1 ; inode=inode->next){
		j=0;
		for(Node* jnode=head ; j<len-1-i ; jnode=jnode->next){
			if(jnode->data > jnode->next->data)
				swap(jnode->data,jnode->next->data);
			j++;
		}
		i++;
	}
}
int mostOccuringElem(Node* node){
	map<int,int> mp;
	int key,value;
	while(node!=NULL){
		mp[node->data]++;
		node=node->next;
	}
	for(auto x:mp){
		key=x.first;
		value=x.second;
		break;
	}
	for(auto e: mp) if(e.second>value) key=e.first;
	return key;
}
int large(Node* node){
	int ans=node->data;
	cout<<"Max: ";
	while(node!=NULL){
		if(ans < node->data){
			ans=node->data;
		}
		node=node->next;
	}
	return ans;
}
void rotateLeft(Node** head,Node* node){
	Node* last=*head;
	while(last->next != NULL){
		last=last->next;
	}
	push(head,last->data);
	popfirst(node);
}
void joinLLtoFirst(Node* node_of_first, Node* node_of_sec){
	Node* lastOfFirst=node_of_first;
	while(lastOfFirst->next != NULL) lastOfFirst=lastOfFirst->next;
	lastOfFirst->next=node_of_sec;
	while(node_of_sec != NULL){
		lastOfFirst->next=node_of_sec;
		lastOfFirst=lastOfFirst->next;
		node_of_sec=node_of_sec->next;
	}
	lastOfFirst->next=NULL;
}
void nextGreater(Node* node){
	while(node->next != NULL){
		printf("%d->%d\n",node->data,node->next->data);
		node=node->next;
	}
}
void arrangeEvnFirst(Node* node){
	Node* inode=node;
	while(inode != NULL){
		if(inode->data % 2 != 0){
			Node* jnode=inode;
			while(jnode != NULL){
				if(jnode->data % 2 == 0) 
					swap(inode->data,jnode->data);
				jnode=jnode->next;
			}
		}
		inode=inode->next;
	}
}
void delet(Node** head){
	Node* current = *head;  
	Node* next;  
	while (current != NULL)  
	{  
    	next = current->next;  
    	free(current);  
    	current = next;  
	}    
	*head=NULL;
}
int Recursiv_size_of_ll(Node* head){
	if(head == NULL) return 0;
	return 1+Recursiv_size_of_ll(head->next);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	Node* head=NULL;;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	append(&head,1);//TILL HERE,ALL PREVIOUS STEPS WERE MUST
	for(int i=2 ; i<11 ; i++) push(&head,i);
	traverse(head);
	int aftval;
	cout<<"Enter value after which you can add a new value: ";
	cin >> aftval;
	insertAfterValue(head,aftval);
	traverse(head);
	popfront(&head,head);
	traverse(head);
	return 0;
}