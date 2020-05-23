/*
 * Recursively finding the sum of all elements of a vector | using Class and OOPs Concepts
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 13:04 23-05-2020
 */
#include <bits/stdc++.h>
using namespace std;
class Rec{
	public:
		int s=0;
		int recSum(int n,vector<int> v)
		{
	
			if(n > 0) s+=v[n-1];
			else return 0;
			return recSum(n-1,v);
		}
};	

		
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v;
	int sz=0;
	for(int i=1 ; i<=11 ; i++)
	{
		v.push_back(i);
		sz++;
	}
	Rec obj;
	obj.recSum(sz , v);
	cout<<obj.s<<'\n';                                                         
	return 0;
}