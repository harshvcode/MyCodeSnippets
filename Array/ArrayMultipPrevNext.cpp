/* Program to update every element of array by multiplication of previous and next.
 * Sample input: 5
 *		 1 2 5 4 5 6
 * Sample output: 2 5 8 25 20 
 * author: thar|thar223|harshvs.223@gmail.com
 * timestamp: 19:57 27-05-2020
 */
#include <bits/stdc++.h>
#define mod 1000000007
#define nl '\n'
#define lol long long
#define lo long
#define pb push_back
using namespace std;
class gym
{
	public:
			int val;
			gym(int a)
			{
				val=a;
			}
};					
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int arr[n];
	for(int i=0 ; i< n ; i++) cin >>arr[i];
	vector<gym> v;
	for(int i=0 ; i<n ; i++)
	{
		if(i==0) v.push_back(gym((arr[i]*arr[i+1])));
		else if(i==n-1) v.push_back(gym((arr[i]*arr[i-1])));
		else v.pb(gym((arr[i-1]*arr[i+1])));
	}
	for(gym each:v) cout<<each.val<<' ';						
	return 0;
}
