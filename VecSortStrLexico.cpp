/* Sort the vector of strings lexicographically.
 * author: thar|thar223|harshvs.223@gmail.com
 * timestamp: 22:47 28-05-2020
 */
#include <bits/stdc++.h>
#define mod 1000000007
#define nl '\n'
#define lol long long
#define lo long
#define pb push_back
using namespace std;
bool comp(string a,string b)
{
	int sa=a.size(),sb=b.size();
	char aa[sa],ba[sb];
	strcpy(aa,a.c_str());
	strcpy(ba,b.c_str());
	return lexicographical_compare(aa,aa+sa,ba,ba+sb);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector<string> v{"ninja","agarbatti","aman","jamalghta"};
	for(string x:v) cout<< x<<' ';
	cout << nl;
	sort(v.begin(),v.end(),comp);
	for(string x:v) cout << x << ' ';

	return 0;
}
