/*
	Lintcode: Merge two sorted list.
	Author: Yinglei Zhang.
	Email:yinglei.zh@gmail.com
	
	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

	Note
	Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

	Example
	For example, given the following triangle

	[
		 [2],
		[3,4],
	   [6,5,7],
	  [4,1,8,3]
	]
	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
	
	solution: calculate the sum path from bottom up;
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int n = triangle.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;++i){
            dp[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<triangle[i].size();++j){
                dp[j] = min(dp[j]+triangle[i][j],dp[j+1]+triangle[i][j]);        
            }
        }
        return dp[0];
    }
};