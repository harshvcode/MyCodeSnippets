/*
 * CodeChef Coin Flip Soution | Problem Code: CONFLIP
 * link: https://www.codechef.com/LRNDSA01/problems/CONFLIP 
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 21.05.2020_at_17:34:46
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te,g,i,q;
	long n;
	cin>>te;
	while(te--)
	{
		int t,h;
		cin>>g;
		for(int z=0;z<g;z++)
		{
			t=h=0;
			cin>>i>>n>>q;
			if(i==1)
			{
				if(n%2==0)
				{
					t=n/2;h=t;
				}
				else
				{
					t=(n/2)+1;h=n/2;
				}
			}
			else
			{
				if(n%2==0)
				{
					h=n/2;t=h;
				}
				else
				{
					h=(n/2)+1;t=n/2;
				}
			}	
			if(q==1) cout<<h<<'\n'; else cout<<t<<'\n';
		}
	}
	return 0;
}
