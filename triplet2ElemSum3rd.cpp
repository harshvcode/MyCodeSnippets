/*
	Count the triplets such that sum of the two is equal to the third element.
	link:- https://practice.geeksforgeeks.org/problems/count-the-triplets/0
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 04:32 PM 17-06-2020
*/
#include <bits/stdc++.h>
#define LL long long
#define M 1000000009
#define NL '\n';
#define PB push_back
#define Ai vector<int> arr
using namespace std;
void triplet2ElemSum3rd(vector<int> &arr,int n){
	sort(arr.begin(),arr.end());
	for(int i=n-1; i>=0; i--){
		int j=0,k=i-1;
		while(j < k){
			if(arr[i] == arr[j] + arr[k]){
				cout <<"Found: " << arr[j] << ',' << arr[k] << ',' << arr[i] << '\n';
				return;
			}
			else if(arr[i] > arr[j] + arr[k]) j++;
			else k--;
		}
	}
	cout << "No such triplet found!\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	Ai {5,4,1,20,13,2,5};
	int n=(int)arr.size();
	triplet2ElemSum3rd(arr,n);
	return 0;
}