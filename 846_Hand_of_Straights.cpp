/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.
 

Note:

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
		int len = hand.size();
		if(1==W) return true;
		if(W>len) return false;
		if(len%W) return false;
		const int num_of_groups = len/W;
		// sort hand in ascending order
		std::sort(hand.begin(), hand.end());
		// find straight hand iteratively
		int cnt = 0;
		for(int l = 0; l < len; ++l){
			if(hand[l]>=0){
				int seed = hand[l];
				int tmp = 1;
				int r = l + 1;
				hand[l] = -hand[l] - 1;
				while(r<len){
					if( (hand[r]>=0)&&(hand[r]==seed+tmp) ){
						hand[r] = -hand[r] - 1;
						++tmp;
						if(tmp==W) break;
					}
					else if( (hand[r]>=0)&&(hand[r]>seed+tmp) )
						return false;
					++r;
				}
				if(tmp==W) ++cnt;
				else return false;
			}
		}
		// return
		return cnt==num_of_groups;
    }
};
