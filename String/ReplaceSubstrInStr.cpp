/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *	Title: REPLACE SUBSTRING IN THE STRING									 *
 *	Author: h2000vs223 (harshvs.official223@gmail.com)   		 *
 *	Time_stamp: 08 April 2020 14:37:34		    							 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cout << "Enter the string: ";
	cin >> s1;
	cout << "Enter the substring: ";
	cin >> s2;
	int s1len = s1.size() , s2len = s2.size();
	if ( s1len < s2len )
	{
		cout<<"Substring length is invalid!\n";
		return 0;
	}
	cout<<"After replacing, result is:\t";
	for( int i = 0 ; i < s1len ; i++ )
	{
		if ( s1.substr(i,s2len) == s2 ) i+=s2len-1;
		else cout << s1.at(i);
	}
	cout<<'\n';
}
