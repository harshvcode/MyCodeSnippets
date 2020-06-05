/*
 * Add digits of a number until the sum of digits becomes unity(1 digit).
 * author: harshvcode|harshvsingh.223@gmail.com
 * timestamp: 09:17 AM 05-06-2020
 */
#include <bits/stdc++.h>
#define M 1000000007
#define NL '\n'
using namespace std;
int untilSingle(int n){
	if(n<10) return n;
	bool notSingle=true;
	int ans=0;
	while(notSingle){
		ans=0;
		while(n>0){
			ans+=n % 10;
			n/=10;
		}
		if(ans<10) notSingle=false;
		n=ans;
	}
	return ans;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	cout << untilSingle(n) << NL;
	return 0;
}
