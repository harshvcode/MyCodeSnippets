/* Program to find longest increasing subsequence(may be or may not be continuous)
 * in below sequence specified in vector, elements considered are: 2,5,7,8,12,13,23
 * Therefore: Output: "7".
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 21:11 23-05-2020
 */

#include <bits/stdc++.h>
#define modulo 1000000007
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v {6,2,5,1,7,4,8,3,12,9,13,23};
	int n = v.size();
	int tillMax=v[0] , maxlen=0;
	for(int i=0 ; i<n ; i++)
	{
		if(i == 0 && v[0] >v[1])
		{
			tillMax=v[1];
			maxlen++;
		}
		else if(v[i] > tillMax)
		{
			tillMax=v[i];
			maxlen++;
		}
	}
	cout << "Total length of longest increasing subsequence: " << maxlen << '\n';
	return 0;
}