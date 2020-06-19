/*
	SUBARRAY(continuous) WITH THE GIVEN SUM.
	link:- https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 10:23 AM 17-06-2020
*/
#include <bits/stdc++.h>
#define LL long long
#define M 1000000009
#define NL '\n';
#define PB push_back
#define Ai vector<int> arr
using namespace std;
pair<int,int> subArrayWithGivenSum(vector<int> arr,int n,int target){
	int left=0,right=0,cursum=0;
	while(true){
		if(cursum == target) return make_pair(left+1,right);
		else if(cursum < target){
			if(right < n){
				cursum+=arr[right];
				right++;
			}else break;
		}
		else{
			if(left < n){
				cursum-=arr[left];
				left++;
			}else break;
		}
	}
	return make_pair(-1,-1);//If Continuous Subarray not found
}
int main()
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	Ai {1,4,20,3,10,5};
	int target=250;
	int n=(int)arr.size();
	pair<int,int> ans=subArrayWithGivenSum(arr,n,target);
	cout << ans.first << ' ' << ans.second << NL; 
	return 0;
}