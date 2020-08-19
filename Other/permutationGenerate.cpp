/*
 * title: Program to generate Permutation arrangements of elements of 
 * 	  a sequence entered by the user.
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 22.05.2020_at_10:08:34
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> permu;//vector to store initial sequence
	int n;
	cin>>n; 
	for (int i = 1; i < n+1; i++) 
	{ 
		permu.push_back(i); //Building initial sequence
	} 
	//Below while loop args generates a new next permutation
	while (next_permutation(permu.begin(),permu.end()))
	{ 
		for(int x:permu) cout<<x<<',';//printing permutation
		cout<<"\n"; 
	}
	return 0;
}
