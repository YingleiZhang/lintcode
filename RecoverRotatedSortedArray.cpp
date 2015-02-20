/*
	Lintcode: Recover rotated sorted array.
	Author: Yinglei Zhang. 
	Email:yinglei.zh@gmail.com
	
	Given a rotated sorted array, recover it to sorted array in-place.

	Example
	[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

	Challenge
	In-place, O(1) extra space and O(n) time.

	Clarification
	What is rotated array:
	- For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
*/

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int offset = 0, n=nums.size();
        for(int i=1;i<n;++i){
            if(nums[i]<nums[i-1]){
                offset=i;
            }
        }
        offset = n-offset;
        reverse(nums, 0, n-offset-1);
        reverse(nums, n-offset, n-1);
        reverse(nums, 0, n-1);
    }
    void reverse(vector<int> &nums, int start, int end){
        while(start<end){
            int a = nums[start];
            nums[start++]=nums[end];
            nums[end--]=a;
        }
    }
};