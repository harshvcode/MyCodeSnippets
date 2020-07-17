/*
_._._._._harshvcode_._._._._
Codeforces A. Magical Sticks
Link: https://codeforces.com/problemset/problem/1371/A
*/
#include<bits/stdc++.h>
#define FI(n) for(int i=0;i<n;i++)
#define SALL(arr) sort(arr.begin(),arr.end())
#define NL '\n'
#define PB push_back
#define MP make_pair
#define W int tt;cin>>tt;while(tt--)
#define Q ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int main(){
	Q;
	W{
		int n;
		cin >> n;
		if(n<=2) cout<<1<<NL; else if(n%2==0) cout<<(n/2)<<NL; else cout<<(n/2)+1<<NL;
	}
	return 0;
}