/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can
you do it in linear time O(n) /possibly in a single pass? Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount
in c++ or in any other language.
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
		vector<int> output;
		int lead_one_bit = 0;

		for(int i=0; i<=num; ++i){
			if(0==i) output.push_back(0);
			else if(1==i) output.push_back(1);
			else{
				if( i==(1<<(lead_one_bit+1)) )
						lead_one_bit++;
				int temp = 1 + output[i-(1<<lead_one_bit)];
				output.push_back(temp);
			}
		}

		return output;
    }
};
