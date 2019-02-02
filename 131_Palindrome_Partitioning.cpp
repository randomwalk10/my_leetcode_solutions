/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void partition(string& s, int pos, vector<string>& path, \
			vector<vector<bool>>& isPalindrome, \
			vector<vector<string>>& res){
		// check if end is reached
		if(pos==(int)s.size()){
			res.push_back(path);
			return;
		}

		// add new palindrome
		for(int i=pos; i<(int)s.size(); ++i){
			if( isPalindrome[i][pos] ){// is substring of s in [pos, i] palindrome or not
				path.push_back(s.substr(pos, i+1-pos)); // append substring to path
				partition(s, i+1, path, isPalindrome, res);
				path.pop_back(); // restore path after recursion
			}
		}
	}
public:
    vector<vector<string>> partition(string s) {
		vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
		vector<vector<string>> res;
		vector<string> path;

		// fill in isPalindrome(O(n^2))
		for(int i=0; i<(int)s.size(); ++i){
			for(int j=0; j<=i; ++j){
				if( (s[i]==s[j])&& \
						((i-j<2)||(isPalindrome[i-1][j+1])) ){
					isPalindrome[i][j] = true;// substring of s in [j, i] is palindrome
				}
			}
		}

		// partition recursively(O(n*2^n))
		partition(s, 0, path, isPalindrome, res);
		
		// return
		return res;
    }
};
