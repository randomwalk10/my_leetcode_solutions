/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:

Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: 9973
Output: 9973
Explanation: No swap.
Note:

The given number is in the range [0, 10^8]
*/

class Solution {
public:
    int maximumSwap(int num) {
		if(0==num) return 0;
		int temp[9];
		int smallest_idx[10];
		int i=0;
		int out=0;

		//fill temp[] and smallest_idx[]
		for(int i=0; i<10; ++i)
			smallest_idx[i] = -1;
		do{
			temp[i] = num % 10;
			if(smallest_idx[temp[i]]<0)
				smallest_idx[temp[i]] = i;

			num /= 10;
			if(num) i++;
		}while(num);

		//do swapping at most once
		bool isSwapped = false;
		while(i>=0){
			if(!isSwapped){
				//do swapping
				for(int j=9; j>temp[i]; j--){
					if( (smallest_idx[j]>=0)&&(i>smallest_idx[j]) ){
						temp[i] ^= temp[smallest_idx[j]];
						temp[smallest_idx[j]] ^= temp[i];
						temp[i] ^= temp[smallest_idx[j]];
						isSwapped = true;
						break;
					}
				}
			}

			out = out*10 + temp[i--];
		}

		return out;
    }
};
