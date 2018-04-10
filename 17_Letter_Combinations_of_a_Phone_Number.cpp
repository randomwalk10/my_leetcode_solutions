/*
17. Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include <vector>
#include <string>
using namespace std;

string lookup_table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> result;
		if(digits.empty()) return result;
		else if( (digits[0] < '0') || (digits[0] > '9') ) return result;
		string letters = lookup_table[digits[0] - '0'];
		if(letters.empty()) return result;
		if(digits.size() == 1){
			for(size_t i=0; i<letters.size(); ++i){
				string char_s = "";
				char_s += letters[i];
				result.push_back(char_s);
			}
		}
		else{
			string new_input = digits.substr(1);
			vector<string> prev_result = letterCombinations(new_input);
			if(prev_result.empty()) return prev_result;
			for(size_t i=0; i<letters.size(); ++i){
				string char_s = "";
				char_s += letters[i];
				for(size_t j=0; j<prev_result.size(); ++j){
					result.push_back(char_s + prev_result[j]);
				}
			}
		}
		return result;
    }
};
