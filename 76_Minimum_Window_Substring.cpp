/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:

public:
    string minWindow(string s, string t) {
		if(t.empty()) return std::string();
		else if(s.size()<t.size()) return std::string();
		unordered_map<char, int> freq_t; //freq in t
		unordered_map<char, int> freq_s; //freq in the sliding window of s
		int num_category=0; //number of unique characters
		int done_cnt=0; //cnt of finished categories in the sliding window
		vector<int> valid_idx; //a list of valid ids of char in s which is also contained in t
		int l=0, r=0; //left and right indice in valid_idx

		//iterate over t
		for(int i=0; i<(int)t.size(); ++i){
			if(freq_t.end()==freq_t.find(t[i])){
				//a new char
				++num_category;
				freq_t[t[i]] = 1;
			}
			else{
				//old char
				++freq_t[t[i]];
			}
		}

		//iterate over s 
		for(int i=0; i<(int)s.size(); ++i){
			if(freq_t.end()!=freq_t.find(s[i])){
				//contained in t
				valid_idx.push_back(i);
			}
		}

		//slide windows
		int min_len = -1;
		int s_l = 0;
		while(true){
			//expand on r
			while( (done_cnt<num_category)&& \
					(r<(int)valid_idx.size()) ){
				//update
				int s_idx = valid_idx[r];
				int temp_cnt = ++freq_s[s[s_idx]];
				if(temp_cnt==freq_t[s[s_idx]]){
					++done_cnt;
				}
				//expand r
				++r;
			}
			if(done_cnt<num_category) break;
			//shrink on l
			while( (done_cnt==num_category)&& \
					(l<(int)valid_idx.size()) ){
				//update
				int s_idx = valid_idx[l];
				int temp_len = valid_idx[r-1] + 1 - s_idx;
				if( (min_len<0)||(min_len>temp_len) ){
					min_len = temp_len;
					s_l = s_idx;
				}
				//shrink on l
				int temp_cnt = --freq_s[s[s_idx]];
				if(temp_cnt<freq_t[s[s_idx]]){
					--done_cnt;
				}
				++l;
			}
			if(done_cnt==num_category) break;
		}

		//return
		return (min_len<0) ? std::string() : s.substr(s_l, min_len);
    }
};
