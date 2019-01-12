/*
Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"
*/
#include <string>
using namespace std;

class Solution {
private:
	bool isMidPtValid(string&s, int l, int r, int n){
		while( (l>=0)&&(r<n) ){
			if(s[l]!=s[r]) return false;
			l--;
			r++;
		}
		return true;
	}
public:
    string shortestPalindrome(string s) {
		if(s.size()<2) return s;
		int n = s.size();
		int l, r;

		//find mid point
		if(n%2){//odd
			l = n/2;
			r = l;
		}
		else{
			l = n/2-1;
			r = n/2;
		}
		while( (l>0)||(r>0) ){
			if(isMidPtValid(s, l, r, n)){
				break;
			}
			else if(l==r){
				l--;
			}
			else{
				r--;
			}
		}

		//add char in front
		int diff = n-1-r-l;
		int r2 = n-1;
		string s2;
		while(diff>0){
			s2.push_back(s[r2]);
			r2--;
			diff--;
		}

		//return
		return s2+s;
    }
};
