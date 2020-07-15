/*
_._._._._harshvcode_._._._._
Program to find prime factors of a number
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
void primeFactors(int n){
	if(n == 0) { cout << 0 << NL; return; }
	cout << 1 << ',';
	int i=2;
	while(n > 1){
		if(n % i == 0){
			cout << i << ',';
			n/=i;
		}else i++;
	}
}
int main(){
	Q;
	int n;
	printf("Enter number: ");
	cin >> n;
	cout << "Ans: ";
	 primeFactors(n);
	return 0;
}