/*
	program to remove punctuations from a given string.
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 04:40 PM 18-06-2020
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
  	string s="%welcome' to @geeksforgeek<s";
  	for(int i=0; i<s.size(); i++) 
		if(ispunct(s.at(i))) 
			s.replace(i--,1,"");//s.erase(i--,1); can also be used.
  	cout << s << NL;
    return 0;
}