/* Problem from the book: Path in a grid | Problem Statement below:
 * ﬁnd a path from the upper-left corner to the lower-right corner of an n×n grid, 
 * such that we only move down and right. Each square contains a positive integer, 
 * and the path should be constructed so that the sum of the values along the path is as large 
 * as possible. The following picture shows an optimal path in a grid:
 * e.g: 3 7 9 2 7 
 *      9 8 3 5 5 
 * 	1 7 9 8 5 
 *	3 8 6 4 10 
 *	6 3 9 7 8
 * The path followed is: 3,9,8,7,9,8,5,10,8.
 * sum of the values on the path is 67, and 
 * this is the largest possible sum on a path from the upper-left corner to the lower-right corner.
 *_________________________________________________________________________________________________ 
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 10:09 24-05-2020
 */
#include <bits/stdc++.h>
#define modulo 1000000007
using namespace std;
int main()
{
	vector<vector<int>> v;
	int n;
	cout<<"Enter Size: ";
	cin >> n;
	for(int i=0 ; i<n ; i++) 
	{
		vector<int> t;
		v.push_back(t);
		for(int j=0 ; j<n ; j++) 
		{
			int val;
			cin >> val;
			v[i].push_back(val);
		}
	} 
    	int c=0,cval=v[0][0];
    	cout << "Path-> "<<cval <<' ';
    	for(int r=0 ; r<n ; )
    	{
    		if(r == n-1 && c == n-1) break;
    		else if(r == n-1 && c < n-1)
    		{
    			c++;
    		}
    		else if(r < n-1 && c == n-1)
    		{
    			r++;
    		}
    		else if(c != n-1 && r != n-1)
    		{
    			int e = v[r][c];
    			if(e+v[r+1][c] > e+v[r][c+1]) r++;
    			else if(e+v[r][c+1] > e+v[r+1][c]) c++;
    			else r++;
    		}
    		cout<<v[r][c]<<' ';
    	}
    	cout << '\n';	
	return 0;
}