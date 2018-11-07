/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
 

Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]

Note:

1 <= deck.length <= 10000
0 <= deck[i] < 10000
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
	int findMaxCommonFactor(int big, int small){
		int res = big%small;
		while(res){
			small = res;
			res = big%small;
		}
		return small;
	}
public:
    bool hasGroupsSizeX(vector<int>& deck) {
		if(deck.size()<2) return false;
		unordered_map<int, int> cnt_dict;

		//fill in cnt_dict
		for(int i=0; i<(int)deck.size(); ++i){
			cnt_dict[deck[i]] += 1;
		}

		//find the minimal count
		int min_cnt = cnt_dict.begin()->second;
		for(unordered_map<int, int>::iterator \
				iter = cnt_dict.begin(); \
				iter != cnt_dict.end(); ++iter){
			min_cnt = min(min_cnt, iter->second);
		}
		if(min_cnt<2) return false;
		
		//iterate through cnt_dict,
		//check if every single count
		//is a multipy of min_cnt
		for(unordered_map<int, int>::iterator \
				iter = cnt_dict.begin(); \
				iter != cnt_dict.end(); ++iter){
			min_cnt = findMaxCommonFactor(iter->second, min_cnt);
			if(min_cnt<2) return false;
		}

		return true;
    }
};
