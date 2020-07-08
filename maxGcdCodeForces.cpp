/*
_._._._._harshvcode_._._._._
A. Maximum GCD Codeforces
LINK - https://codeforces.com/problemset/problem/1370/A
*/
#include<bits/stdc++.h>
#define FI(n) for(int i=0;i<n;i++)
#define M 100000007
#define FEI(arr) for(int e:arr)
#define FES(arr) for(string e:arr)
#define VI vector<int> arr;
#define VIZ(n) vector<int> arr(n,0)
#define PB push_back
#define MP make_pair
#define W int tt;cin>>tt;while(tt--)
#define SPLT(s) for(auto i=strtok(&s[0]," ");i!=NULL;i=strtok(NULL," "))
#define SALL(arr) sort(arr.begin(),arr.end())
#define NL '\n'
#define REV(arr) reverse(arr.begin(),ar.end())
#define MPI map<int,int> mp
#define MPC map<char,int> mp
#define MPS map<string,int> mp
#define Q ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define FL(arr) forward_list<int> fl;
using namespace std;
int main(){
	Q;
	W{
		int n;
		cin >> n;
		if(n == 2){
			cout << 1 << NL;
		}else if(n % 2 == 0){
			cout << (n / 2) << NL;
		}else cout << ((n - 1) / 2) << NL;
	}
	return 0;
}
