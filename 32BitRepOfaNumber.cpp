/*
	PROGRAM TO GET A 32-BIT REPRESENTATION OF A NUMBER.
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 01:36 PM 14-06-2020
*/
#include <bits/stdc++.h>
using namespace std;
string binary(int n){
	if(n == 0) return "00000000 00000000 00000000 00000000";
	string ans="";
	int l=0, k=0;
	while(n > 0){
		ans=to_string(n%2) + ans;
		l++; k++;
		if(k == 8 && (n / 2 > 0)){ ans = " " + ans; k = 0; }
		n/=2;
	}
	int till = (32 - l) % 8;
	for(int i=0; i<till; i++) ans= "0" + ans;
	till = (32 - l) / 8;
	for(int i=0; i<till; i++){
		ans="00000000 " + ans;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int n;
  	cin >> n;
  	string bin=binary(n);                                              
  	cout << bin << '\n';
    return 0;
}