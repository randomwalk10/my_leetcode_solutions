/*
You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:

Operation 1: If the number contains the substring "00", you can replace it with "10".
For example, "00010" -> "10010"
Operation 2: If the number contains the substring "10", you can replace it with "01".
For example, "00010" -> "00001"
Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.

 

Example 1:

Input: binary = "000110"
Output: "111011"
Explanation: A valid transformation sequence can be:
"000110" -> "000101" 
"000101" -> "100101" 
"100101" -> "110101" 
"110101" -> "110011" 
"110011" -> "111011"
Example 2:

Input: binary = "01"
Output: "01"
Explanation: "01" cannot be transformed any further.
 

Constraints:

1 <= binary.length <= 105
binary consist of '0' and '1'.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-string-after-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
		if(binary.size()==1) return binary;

		int cnt_zero = 0;
		int first_zero = -1;
		for (int i = 0; i < binary.size(); ++i) {
			if(binary[i]=='0'){
				++cnt_zero;
				if(first_zero<0) first_zero = i;
			}
		}
		if(cnt_zero<2) return binary;

		for (int i = first_zero; i < binary.size(); ++i) {
			if(i==first_zero+cnt_zero-1){
				binary[i] = '0';
			}
			else{
				binary[i] = '1';
			}
		}

		return binary;
    }
};
