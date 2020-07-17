/*
_._._._._harshvcode_._._._._
*/
#include<bits/stdc++.h>
using namespace std;
#define FI(n) for(int i=0;i<n;i++)
#define ALL(arr) arr.begin(),arr.end()
#define NL '\n'
#define PB push_back
#define MP make_pair
#define W int tt;cin>>tt;while(tt--)
#define Q ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//BELOW TEMPLATE FOR FACTORIAL
template<unsigned int n>
struct fact{
	enum{
		value=n*fact<n-1>::value
	};
};
template<>
struct fact<0>{
	enum{
		value=1
	};
};
int main(){
	Q;
	cout<<"Factorial: "<<fact<6>::value<<'\n';
	return 0;
}