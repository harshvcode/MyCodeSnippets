/* 
 * PROGRAM TO GET DEFINE OUR OWN POWER FUNCTION WITHOUT USING BUILTIN
 * POW() FUNCTION
 * author: harshvcode|harshvsingh.223@gmail.com
 * timestamp: 09:52 AM 13-06-2020
 */
#include <bits/stdc++.h>
#define M 1000000007
#define NL '\n'
#define LL long long
#define PB push_back
using namespace std;
int power(int a,int b){
	if(b==0) return 1;
	return a * power(a,b-1);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<power(n,m)<<NL;
	return 0;
}
