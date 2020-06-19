/*
	Program to find the initials of a name.
	Link: https://www.geeksforgeeks.org/program-find-initials-name/
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 07:39 PM 18-06-2020
*/
#include <bits/stdc++.h>
#define LL long long
#define M 1000000009
#define NL '\n';
#define PB push_back
#define Ai vector<int> arr
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	string s;
	getline(cin , s);
	int i=0;
	for(char X:s) if(i++ == 0) cout << char(toupper(X)) << ' '; else if(X == ' ') i=0;
	cout << NL;
	return 0;
}