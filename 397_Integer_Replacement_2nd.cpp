/* O(logN) in time and O(1) in space */

class Solution {
public:
    int integerReplacement(int n) {
		int cnt = 0;
		while(n>1){
			if((n&0b1)==0){
				n >>= 1;
				++cnt;
			}
			else{
				if((n&0b11)==0b01){
					n >>= 2;
					cnt += 3; // reduction, divide, divide
				}
				else if(n==0b11){
					n >>= 1;
					cnt += 2; // reduction, divide
				}
				else{
					n >>= 2;
					++n;
					cnt += 3; // addition, divide, divide
				}
			}
		}
		return cnt;
    }
};
