/*
	LEETCODE 283. Move Zeroes [ https://leetcode.com/problems/move-zeroes/ ]
	coded by: harshvcode | harshvsingh.223@gmail.com
	at: 11:13 PM 16-06-2020
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i < n){
            if(nums[i] == 0){
                int j=i+1;
                while(j < n){
                    if(nums[j] != 0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
};