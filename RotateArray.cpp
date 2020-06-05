/* Program to rotate array elements by d elements
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 21:21 26-05-2020
 */
#include <bits/stdc++.h>
#define mod 1000000007
#define nl '\n'
#define lol long long
#define lo long
#define pb push_back
using namespace std;	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ar[]={1,2,3,4,5,6,7};
	int n=*(&ar+1)-ar;
	int d;
	cin >> d;
	while(d--)
	{
		int a=ar[0];
		for(int i=0 ; i<n-1 ; i++)
		{
			ar[i]=ar[i+1];
		}
		ar[n-1]=a;
	}	
	for(int x:ar) cout << x << ' ';
	return 0;
}
