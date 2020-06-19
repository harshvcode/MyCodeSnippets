/*
	Program to remove spaces in a string.
	https://www.geeksforgeeks.org/c-program-remove-spaces-string/
	By: harshvcode | harshvsingh.223@gmail.com
	Created at: 08:32:32_PM_18-JUNE-2020
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
	string s= " harsh   vardha n sin g h  !";
	for(int i=0; i<s.size(); i++) if(s.at(i) == ' ') s.erase(i--,1);
	cout << s << NL;
	return 0;
}