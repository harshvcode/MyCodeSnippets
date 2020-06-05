/*
 * CodeChef Problem Name: laddus
 * link: https://www.codechef.com/LRNDSA01/problems/LADDU 
 * author: h2000vs223 | harshvs.official223@gmail.com
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int laddus,t,ac,severity,rank;
	cin>>t;
	string s,did;
	bool ind=false,contWon,topContri,bugF,conHost;;
	while(t--)
	{
		laddus=0;
		ind=false;
		cin>>ac>>s;
		if(s=="INDIAN") ind=true;
		while(ac--)
		{
			contWon=topContri=bugF=conHost=false;
			cin>>did;
			if(did=="CONTEST_WON")
			{
				contWon=true;cin>>rank;
			}
			else if(did=="TOP_CONTRIBUTOR")
			{
				topContri=true;
			}
			else if(did=="BUG_FOUND")
			{
				bugF=true;cin>>severity;
			}
			else if(did=="CONTEST_HOSTED") conHost=true;
			if(contWon)
			{
				laddus+=300;
				if(! (rank>20))
				{
					laddus+=20-rank;
				}
			}
			else if(topContri)
			{
				laddus+=300;
			}
			else if(bugF)
			{
				laddus+=severity;
			}
			else if(conHost)
			{
				laddus+=50;
			}	
		}
		if(ind) cout<<laddus/200<<'\n'; else cout<<laddus/400<<'\n';
	}			
	return 0;
}
