/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.
*/

#include <string>
using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
		if(start.size()!=end.size()) return false;
		bool res = true;
		int l1 = 0; int l2 = 0;
		int prev_loc = -1;
		do {
			// find the next L or R in start
			while((l1<(int)start.size())&&(start[l1]=='X'))
				++l1;
			char LR = 'X';
			if(l1<(int)start.size())
				LR = start[l1];
			// match in end
			if(LR!='X'){
				while((l2<(int)end.size())&&(end[l2]=='X'))
					++l2;
				if(l2<(int)start.size()){
					if(end[l2]==LR){
						int temp_loc;
						if(LR=='L'){
							if(l1<l2) return false;
							temp_loc = l2;
						}
						else{
							if(l1>l2) return false;
							temp_loc = l2;
						}
						if(prev_loc>=temp_loc) return false;
						prev_loc = temp_loc;
						++l1;
						++l2;
					}
					else
						return false;
				}
				else
					return false;
			}
			else{
				while(l2<(int)start.size()){
					if(LR!=end[l2]) return false;
					++l2;
				}
				return true;
			}
		} while (true);
		return res;
    }
};
