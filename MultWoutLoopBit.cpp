/* 
 * PROGRAM TO MULTIPLY TWO INTEGERS WITHOUT USING MULTIPLICATION,
 * DIVISION,BITWISE OPERATORS AND LOOPS.
 * author: harshvcode|harshvsingh.223@gmail.com
 * timestamp: 10:08 PM 04-06-2020
 */
#include <bits/stdc++.h>
#define M 1000000007
#define NL '\n'
#define LL long long
#define PB push_back
using namespace std;
int mul(int a,int b){
	if(b==0 || a==0) return 0;
	return a+mul(a,b-1);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	cout<<mul(n,m)<<NL;
	return 0;
}
