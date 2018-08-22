/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int findRightLimitForPartition(string& S, int left_index, int* right_array){
		int right_index = right_array[S[left_index]-'a'];
		left_index++;
		while(left_index<right_index){
			right_index = (right_array[S[left_index]-'a'] > right_index) ? \
						  right_array[S[left_index]-'a'] : right_index;
			left_index++;
		}
		return right_index;
	}

    vector<int> partitionLabels(string S) {
		int right_array[26] = {-1};
		int start = 0;
		int end = 0;
		vector<int> out;

		for(int i=0; i<(int)S.size(); ++i){
			right_array[S[i]-'a'] = (i>right_array[S[i]-'a']) ? \
				i : right_array[S[i]-'a'];
		}
		while(start<(int)S.size()){
			end = findRightLimitForPartition(S, start, right_array);
			out.push_back(end-start+1);
			start = end + 1;
		}

		return out;
    }
};
