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
			int cycle_len = numRows + numRows - 2;
			int cycle_num = (str_len%cycle_len) ? (str_len/cycle_len+1) : (str_len/cycle_len);
			//perform conversion
			for (int i = 0; i < str_len; ++i) {
				//determine the cycle index and the index within the cycle
				int cycle_index = i/cycle_len;
				int index_within = i%cycle_len;
				//determine the index of new string and replace old char with new char
				int new_idx = 0;
				for (int j = 0; j < (index_within%cycle_len); ++j) {
					new_idx += ((j+numRows)<cycle_len) ? (2*cycle_num-2) : (cycle_num-1);	
					new_idx += ((cycle_num-1)*cycle_len+j<str_len) ? 1 : 0;
					new_idx += ((cycle_num-1)*cycle_len+j+numRows<str_len) ? 1 : 0;
				}
				if(index_within>=numRows){
					new_idx += 2*(cycle_index+1);
				}
				else if( (index_within+numRows)>=cycle_len ){
					new_idx += cycle_index+1;
				}
				else if( cycle_index<=0 ){
					new_idx += 1;
				}
				else{
					new_idx += 2*(cycle_index-1) + 1;
				}
				r[new_idx] = s[i];
			}
			//return
			return r;
		}
};
