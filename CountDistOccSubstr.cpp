/* "Counts of distinct consecutive sub-string of length two using C++ STL"
 * Link- https://www.geeksforgeeks.org/counts-distinct-consecutive-sub-string-length-two-using-c-stl/
 * Input: str = "abcab"
 * Output: ab-2
 *         bc-1
 *         ca-1
 * Input: str = "xyz"
 * Output: xy-1
 *        yz-1
 *
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 21:26 25-05-2020
 */
#include <bits/stdc++.h>
#define modulo 1000000007
#define lol long long
#define lo long
#define pb push_back
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int l=s.size();
	map<string , int> mp;
	for(int i=0 ; i<l-2+1 ; i++) mp[s.substr(i,2)]++;
	for(auto x:mp) cout<<x.first<<'-'<<x.second<<'\n';
	return 0;
}