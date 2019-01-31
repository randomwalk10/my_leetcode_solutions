/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	void restoreIpAddresses(string& s, int s_idx, \
			int ip_idx, string& path, vector<string>& res){
		//exit condition
		if( (s_idx>=(int)s.size())&&(ip_idx>=4) ){
			res.push_back(path);
			return;
		}
		else if( (s_idx>=(int)s.size())||(ip_idx>=4) ){
			return;
		}
		//now s_idx<(int)s.size() and ip_idx<4
		//add more parts
		int val = 0;
		int cnt = 0;
		if(ip_idx>0){
			path.push_back('.');
			++cnt;
		}
		for(int i=0; i<3; ++i){
			if( (s_idx+i)<(int)s.size() ){
				//no leading zero
				if( (i>0)&&(val==0) ) break;
				//add trailing number
				val = 10*val + (s[s_idx+i] - '0');
				if( (val>=0)&&(val<256) ){
					path.push_back(s[s_idx+i]);
					++cnt;
					//recursion into next part
					restoreIpAddresses(s, s_idx+i+1, ip_idx+1, path, res);
				}
				else break;
			}
			else break;
		}
		//restore path
		while(cnt>0){
			path.pop_back();
			--cnt;
		}
	}
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string path;
		restoreIpAddresses(s, 0, 0, path, res);
		return res;
    }
};
