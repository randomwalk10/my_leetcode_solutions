/*
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].
*/
#include <vector>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
		if(N==0) return 0;
		vector<int> digi_input;
		int out = 0;
		//convert N to vector of int
		while(N){
			digi_input.insert(digi_input.begin(), N%10);
			N /= 10;
		}

		//get digi_output vector
		int* digi_output = new int[digi_input.size()];
		int base_digit = 0;
		for(size_t i=0; i<digi_input.size(); ++i){
			if(base_digit<=digi_input[i]){
				base_digit = digi_input[i];
				digi_output[i] = digi_input[i];
			}
			else{
				int retreat = i - 1;
				while(retreat>0){
					if( (digi_output[retreat]-1)>=digi_output[retreat-1] )
						break;
					retreat--;
				}
				digi_output[retreat]--;
				for(size_t j=retreat+1; j<digi_input.size(); ++j){
					digi_output[j] = 9;
				}
				break;
			}
		}

		//convert vector of int to integer
		for(size_t i=0; i<digi_input.size(); ++i){
			out *= 10;
			out += digi_output[i];
		}
		delete[] digi_output;

		return out;
    }
};
