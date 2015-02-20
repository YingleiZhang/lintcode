/*
	Lintcode: Unique path.
	Author: Yinglei Zhang. 
	Email:yinglei.zh@gmail.com

	Given a string s, partition s such that every substring of the partition is a palindrome.
	Return all possible palindrome partitioning of s.
	Example
	given s = "aab",
	Return

	  [
		["aa","b"],
		["a","a","b"]
	  ]
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<string> path;
        vector<vector<string> > res;
        dfs(s, 0, path, res);
        return res;
    }
    void dfs(string s, int start, vector<string> &path, vector<vector<string> > &res){
        if(start == s.length()){
            res.push_back(path);
            return;
        }
        for(int i=start;i<s.length();++i){
            string t = s.substr(start, i-start+1);
            if(!isPalindrome(t)) continue;
            path.push_back(t);
            dfs(s, i+1, path, res);
            path.pop_back();
        }
    }
    bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else return false;
        }
        return true;
    }
};