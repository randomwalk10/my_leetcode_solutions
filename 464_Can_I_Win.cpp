/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
*/
#include <unordered_map>
using namespace std;

class Solution {
private:
	bool canIWin(int maxChoosableInteger, int desiredTotal, \
			unordered_map<int, bool>& playbook, int state){
		// check if it is already in playbook
		if(playbook.end()!=playbook.find(state)){
			return playbook[state];
		}
		// use next integer
		for(int i=0; i<maxChoosableInteger; ++i){
			if(0==(state&(1<<i))){
				// check if I win with current move
				if(desiredTotal<=(i+1)){
					playbook[state] = true;
					return true;
				}
				// let other play
				bool canOtherWin;
				state |= (1<<i);
				canOtherWin = canIWin(maxChoosableInteger, desiredTotal-(i+1), \
						playbook, state);
				state &= ~(1<<i);
				if(!canOtherWin){
					playbook[state] = true;
					return true;
				}
			}
		}
		// return if all attempts failed
		playbook[state] = false;
		return false;
	}
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int max_sum = maxChoosableInteger*(1+maxChoosableInteger)/2;
		if(max_sum<desiredTotal) return false;
		else if(max_sum==desiredTotal) return 0!=maxChoosableInteger%2;
		unordered_map<int, bool> playbook;
		int state = 0; // any bit(maxChoosableInteger in total) in state: 0-available, 1-used

		return canIWin(maxChoosableInteger, desiredTotal, playbook, state);
    }
};
