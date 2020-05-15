/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *	Title: PROGRAM TO FIND OCCURENCE OF EACH WORD IN A STRING*				    	     															 *
 *	Author: h2000vs223 (harshvs.official223@gmail.com)   		 *
 *	Time_stamp: 09 April 2020 23:31:41		    							 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string sample;
	map< string , int > mp;
	cout << "Enter string: ";
	getline(cin,sample);//To Input the string
	istringstream iss(sample);//To split string
	vector<string> results((istream_iterator<string>(iss)),
	istream_iterator<string>());// Each substring stored in vector
	for (string e: results) mp[e]++; //Iterating from vector
	for( auto each : mp ) cout<< '`' << each.first << '`' << " counts to: " << each.second << '\n';
}
