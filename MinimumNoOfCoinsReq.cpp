/* COIN PROBLEM SOLUTION OF PROBLEM GIVEN IN BOOK, check problem statement below:
 *_____________________________________________________________________________
 * we consider a problem where we are given a set of coins 
 * and our task is to form a sum of money n using the coins. 
 * The values of the coins are coins={c1,c2,...,ck}, and 
 * each coin can be used as many times we want.
 * What is the minimum number of coins needed? For example, 
 * if the coins are the euro coins (in cents)
 * {1,2,5,10,20,50,100,200} and n=520, 
 * we need at least four coins.
 *  The optimal solution is to select coins 200+200+100+20 whose sum is 520.
 *______________________________________________________________________________
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 22.05.2020_at_21:32:48
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v {1,2,5,10,20,50,100,200} ;
	int n=520,tillind,noOfcoins=0,need;
	bool notbrek=true;
	int s=v.size();
	for(int i=s-1 ; i>=0 ; i--)
	{
		if(v[i] < n)
		{
			tillind=i;
			break;
		}
	}
	for(int i=tillind ; i>=0 && notbrek ; i--)
	{
		noOfcoins+=n/v[i];
		n=n-( n / v[i]) * v[i];
		need=n;
		if(need != 0)
		{
			for(int j=tillind-1 ; j>=0 ; j--)
			{
				if(v[j] == need)
				{
					noOfcoins++;
					notbrek=false;
					break;
				}
			}	
		}
		else break;	
	}
	cout << noOfcoins << '\n';
	return 0;
}