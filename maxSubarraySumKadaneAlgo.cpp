/*
	Largest Sum Contiguous Subarray [ USING KADANE'S ALGORITHM ] .
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 04:32 PM 17-06-2020
*/
#include <bits/stdc++.h>
#define LL long long
#define M 1000000009
#define NL '\n';
#define PB push_back
#define Ai vector<int> arr
using namespace std;
int maxSubarraySumKadaneAlgo(Ai){
	int n= (int) arr.size();
	int max_so_far = INT_MIN, max_ending_here = 0; 
    for (int i = 0; i < n; i++) 
  	{
  		max_ending_here = max_ending_here + arr[i]; 
       	if (max_so_far < max_ending_here)
       		max_so_far = max_ending_here;
       	if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	Ai { 2,-10,11,3,4,-5,1};
	cout << maxSubarraySumKadaneAlgo(arr) << NL;
	return 0;
}