/*
	Lintcode: Sort letters by case.
	Author: Yinglei Zhang.
	Email:yinglei.zh@gmail.com
	
	Given a string which contains only letters. Sort it by lower case first and upper case second.
	Note
	It's not necessary to keep the original order of lower-case letters and upper case letters.
	Example
	For "abAcD", a reasonable answer is "acbAD"
	Challenge
	Do it in one-pass and in-place.
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int left = 0, right = letters.size()-1;
        while(left<right){
            while(left<right&&letters[left]<='z'&&letters[left]>='a') left++;
            while(left<right&&letters[right]<='Z'&&letters[right]>='A') right--;
            swap(letters, left, right);
        }
    }
    void swap(string &letters, int left, int right){
        char c = letters[left];
        letters[left] = letters[right];
        letters[right] = c;
    }
};