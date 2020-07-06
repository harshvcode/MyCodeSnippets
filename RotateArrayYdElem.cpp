/*_*<harshvcode>*_*/

#include<bits/stdc++.h>
using namespace std;
void lrot(vector<int>& arr, int& n, int d){//Method for left rotation by d elements
	while(d--){
		int f=arr[0];
		for(int i=1; i<n; i++){
			arr[i-1]=arr[i];
		}
		arr[n-1]=f;
	}
}
void rrot(vector<int>& arr, int& n, int d){//Method for right rotation by d elments
	while(d--){
		int e=arr[n-1];
		for(int i=n-1; i>0; i--){
			arr[i]=arr[i-1];
		}
		arr[0]=e;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> arr{1,2,3,4,5,6,7};
	cout << "Previously: ";
	for(int& e:arr) cout << e << ' ';
	cout << '\n';
	int n=arr.size();
	int d;
	printf("Enter number upto which elements gets rotated: ");
	cin >> d;
	cout << "After left rotation: ";
	lrot(arr, n, d);
	for(int e:arr) cout << e << ' ';
	rrot(arr, n, d);
	cout << '\n';
	cout << "After right rotation: ";
	for(int e:arr) cout << e << ' ';
	cout << '\n';
	return 0;
}