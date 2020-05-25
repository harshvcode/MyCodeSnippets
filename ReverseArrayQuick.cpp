/* Program to reverse array, algorithm in 1 line.
 * author: h2000vs223 | harshvs.official223@gmail.com
 * timestamp: 22:26 25-05-2020
 */
#include <bits/stdc++.h>
#define modulo 1000000007
#define lol long long
#define lo long
#define pb push_back
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[]={1,2,3,4,5,6,7,8,9};
	int n=*(&arr+1)-arr; //THIS WAY TO FIND SIZE OF ARRAY
	for(int i=0 ; i<n/2 ; i++) swap(arr[i],arr[n-1-i]); //This line reverses quickly
	for(int x:arr) cout<<x<<' ';
	return 0;
}