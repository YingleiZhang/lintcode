/*

	Lintcode: LargestRectangleInHistogram.
	Author: Yinglei Zhang. 
	Email:yinglei.zh@gmail.com
	
	Given n non-negative integers representing the histogram's bar height 
	where the width of each bar is 1, find the area of largest rectangle in the histogram.
	Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
	The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/


class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        if(height.size()==0) return 0;
        stack<int> stk;
        int area = 0;
        int n = height.size(), i=0;
        while(i<n){
            if(stk.empty()||height[i]>=height[stk.top()]){
                stk.push(i++);
            }
            else{
                //calculate the area for last increasing trend.
                int index = stk.top();stk.pop();
                int width = stk.empty()?i:(i-stk.top()-1);
                area = max(area, height[index]*width);
            }
        }
		//calculate the area for the remaining element in the stack;
        while(!stk.empty()){
            int index = stk.top();stk.pop();
            int width = stk.empty()?i:(i-stk.top()-1);
            area = max(area, height[index]*width);
        }
        return area;
    }
};
