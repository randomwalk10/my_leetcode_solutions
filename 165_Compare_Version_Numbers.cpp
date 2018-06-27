/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level
revision of the second first-level revision.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void string2vec(string& version, vector<int> &out){
		int temp = 0;
		for(size_t i=0; i<version.size(); ++i){
			if(version[i]=='.'){
				out.push_back(temp);
				temp = 0;
			}
			else{
				temp = temp*10 + version[i] - '0';
			}
		}
		out.push_back(temp);
	}

    int compareVersion(string version1, string version2) {
		vector<int> vec1;
		vector<int> vec2;
		string2vec(version1, vec1);
		string2vec(version2, vec2);
		
		while( (!vec1.empty()) || (!vec2.empty()) ){
			if(vec1.empty()){
				if(vec2[0]>0) return -1;
				vec2.erase(vec2.begin());
			}
			else if(vec2.empty()){
				if(vec1[0]>0) return 1;
				vec1.erase(vec1.begin());
			}
			else if(vec1[0]<vec2[0])
				return -1;
			else if(vec1[0]>vec2[0])
				return 1;
			else{
				vec1.erase(vec1.begin());
				vec2.erase(vec2.begin());
			}
		}

		return 0;
    }
};
