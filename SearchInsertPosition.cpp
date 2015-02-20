/*
	Lintcode: Search insert position.
	Author: Yinglei Zhang.
	Email:yinglei.zh@gmail.com
	
	Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

	You may assume no duplicates in the array.

	Example
	[1,3,5,6], 5 → 2
	[1,3,5,6], 2 → 1
	[1,3,5,6], 7 → 4
	[1,3,5,6], 0 → 0

*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.size()==0) return 0;
        int start=0, end = A.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(A[mid]==target) return mid;
            else if(A[mid]>target)  end = mid-1;
            else    start = mid+1 ;
            //cout << start << end << endl;
        }
        return start;
    }
};