/*
	Lintcode: Unique path.
	Author: Yinglei Zhang. 
	Email:yinglei.zh@gmail.com

	Given a string and an offset, rotate string by offset. (rotate from left to right)

	Example
	Given "abcdefg"

	for offset=0, return "abcdefg"

	for offset=1, return "gabcdef"

	for offset=2, return "fgabcde"

	for offset=3, return "efgabcd"

	...
*/

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        int n=A.length();
        if(n==0) return "";
        if(offset>n) offset = offset%n;
        if(offset==0) return A;
        reverse(A, 0,n-offset-1);
        reverse(A, n-offset, n-1);
        reverse(A,0,n-1);
        return A;
    }
    void reverse(string &s, int start, int end){
        while(start<end){
            char c = s[start];
            s[start++] = s[end];
            s[end--]=c;
        }
    }
};