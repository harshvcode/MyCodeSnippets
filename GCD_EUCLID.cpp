/*
	By: harshvcode | harshvsingh.223@gmail.com
	Created at: 11:31:32_PM_19-JUNE-2020
*/
#include <bits/stdc++.h>
#define LL long long
#define M 1000000009
#define NL '\n';
#define PB push_back
#define Ai vector<int> arr
using namespace std;
int euclid_gcd(int a,int b){
	int dividend = a >= b ? a : b;
	int divisor = a <= b ? a : b;
	while(divisor != 0){
		int remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	return dividend;
}
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int a,b;
  	a=105; b=350;
  	cout << euclid_gcd(a,b) << NL;
	return 0;
}