/*
	Lintcode: Unique path.
	Author: Yinglei Zhang. 
	Email:yinglei.zh@gmail.com
	
	Determine the number of bits required to convert integer A to integer B 

	Example
	Given n = 31, m = 14,return 2
	(31)10=(11111)2
	(14)10=(01110)2
	
	solution: a xor b, then count the number of 1s;
*/
	
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int num = a^b,count=0;
        for(int i=0;i<32;++i){
            if(num&1) count++;
            num = num>>1;
        }
        return count;
    }
};	
	
	
	
	
*/