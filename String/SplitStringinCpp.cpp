/* C++ Method to split string by a delimeter.
 * author: thar|thar223|harshvs.223@gmail.com
 * timestamp: 18:20 28-05-2020
 */
#include <bits/stdc++.h>
#define mod 1000000007
#define nl '\n'
#define lol long long
#define lo long
#define pb push_back
using namespace std;
vector<string> split(string s,char delim)
{
	vector<string> result;
	int n=s.size(),len=0,b=0;
	for(int i=0 ; i<n ; i++)
	{
		len++;
		if(i==n-1)
		{
			result.push_back(s.substr(b,len));
		}
		else if(s.at(i)==delim)
		{
			result.push_back(s.substr(b,len-1));
			b=i+1;len=0;
		}
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	cin >> s;
	vector<string> ans;
	ans=split(s,',');
	
  return 0; 
}
