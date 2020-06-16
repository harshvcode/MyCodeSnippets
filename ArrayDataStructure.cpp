/*
	Array Data structure Implementation with five methods.
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 11:43 AM 16-06-2020
*/
#include<bits/stdc++.h>
using namespace std;
class Array{
	int size=0;
	int arr[1000];    
	public:
		void traverse();
		void insert(int data);
		void deletearray(int data);
		void sortarray();
		void searchinarray(int data);
};
void Array::traverse(){
	if(size == 0) { cout << "Array is empty!\n"; return; }
	for(int i=0; i<size; i++) cout << arr[i] << ' ';
	cout << '\n';
}
void Array::insert(int data){
	if(size > 999) { cout << "Array is already full of 1000 elements";
		cout << " , so insertion of: " << data << " failed!\n"; return; }
	arr[size]=data;
	size++;
}
void Array::deletearray(int data){
	if(arr[size-1] == data) { size--; return; }
	if(arr[0] == data){
		for(int i=0; i<size-1; i++) arr[i]=arr[i+1];
		size--;
		return;
	}
	bool found=false;
	int i=0;
	for(; i<size; i++){
		if(arr[i] == data){found=true; break;}
	}
	if(! found) { cout << "value you entered doesn't exist!\n"; return;}
	for(; i<size-1; i++) arr[i]=arr[i+1];
	size--;
}
void Array::sortarray(){
	sort(arr,arr+size);
}
void Array::searchinarray(int data){
	for(int x=0; x<size; x++) if(arr[x] == data) { cout << "found at: " << x+1 << '\n';return; }
	cout<<"Value: " << data << " not found!\n";
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	Array obj;
	obj.traverse();
	for(int x=1000 ; x >=0; x--) obj.insert(x+1);
	obj.traverse();
	obj.deletearray(1);
	obj.traverse();
	obj.deletearray(12);
	obj.traverse();
	obj.deletearray(6000);
	obj.traverse();
	obj.sortarray();
	obj.traverse();
	obj.searchinarray(8);
	obj.searchinarray(1400);
	return 0;
}