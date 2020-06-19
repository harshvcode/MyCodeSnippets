/*
	Rearrange characters in a string such that no two adjacent are same.
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 07:12 PM 18-06-2020
*/
#include <bits/stdc++.h>
#define LL long long
#define M 1000000009
#define NL '\n';
#define PB push_back
#define Ai vector<int> arr
using namespace std;
string arrangeNoadjcntCharSame(char s[],int n){
	for(int i=0; i<n-1; i++){
		char c1=s[i];
		if(s[i] == s[i+1]){
			int j=i+2;
			while(j < n){
				if(s[i+1] != s[j]) { swap(s[i+1],s[j]); break; }
				j++;
			}
		}
	}
	n--;
	for(int i=0; i<n; i++) if(s[i] == s[i + 1]) return "Not Possible";
	return s;
}
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	string s;
	cin >> s;
	int n=(int)s.size();
	char arr[n+1];
	strcpy(arr,s.c_str());
	cout << arrangeNoadjcntCharSame(arr,n) << NL;
	return 0;
}