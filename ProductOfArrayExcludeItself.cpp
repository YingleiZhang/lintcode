/*
	Lintcode: Product of an array exclude itself.
	Author: Yinglei Zhang.
	Email:yinglei.zh@gmail.com
	
	Given an integers array A.
	Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B without divide operation.
	Example
	For A=[1, 2, 3], B is [6, 3, 2]
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n=nums.size();
        vector<long long> res1;
        if(n<2) return res1;
        vector<long long> res(n,0);
        vector<long long> left(n,1);
        vector<long long> right(n,1);
        for(int i=1;i<n;++i){
            left[i] =left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;--i){
            right[i] =right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;++i){
            res[i]=left[i]*right[i];
        }
        return res;
    }
};