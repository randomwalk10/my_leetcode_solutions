/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
	public:
		string convert(string s, int numRows) {
			string r = s;
			const int str_len = r.size();
			if(numRows<=1) return r;
			//get the total cycles and length of each cycle
			int cycle_len = 2 * numRows - 2;
			int cycle_num = (str_len%cycle_len) ? (str_len/cycle_len+1) : (str_len/cycle_len);
			//perform conversion
			for (int i = 0; i < str_len; ++i) {
				//determine the cycle index and the index within the cycle
				int cycle_index = i/cycle_len;
				int index_within = i%cycle_len;
				int first_idx = (index_within<numRows) ? \
								index_within : (cycle_len-index_within);
				//determine the index of new string and replace old char with new char
				int cnt = 0;
				for (int j = 0; j < first_idx; ++j) {
					cnt += (0!=j) ? (2*cycle_num-2) : (cycle_num-1);	
					cnt += ((cycle_num-1)*cycle_len+j<str_len) ? 1 : 0;
					cnt += ((cycle_num-1)*cycle_len+cycle_len-j<str_len) ? 1 : 0;
				}
				if( (index_within==0) || \
						(index_within==(numRows-1)) ){
					cnt += cycle_index+1;
				}
				else{
					cnt += (first_idx==index_within) ? \
							   (2*cycle_index+1) : (2*cycle_index+2);
				}
				r[cnt-1] = s[i];
			}
			//return
			return r;
		}
};
