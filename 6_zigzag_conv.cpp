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
			string r = "";
			const int str_len = s.size();
			if(numRows<=1) return s;
			//get the total cycles and length of each cycle
			int cycle_len = 2 * numRows - 2;
			int cycle_num = (str_len%cycle_len) ? (str_len/cycle_len+1) : (str_len/cycle_len);
			//perform conversion
			for (int i = 0; i < numRows; ++i) {
				for (int j = 0; j < cycle_num; ++j) {
					if( (0==i)||((numRows-1)==i) ){
						int idx = j*cycle_len + i;
						if(idx<str_len) r+=s[idx];
					}
					else{//in the middle
						int idx = j*cycle_len + i;
						if(idx<str_len) r+=s[idx];
						idx = j*cycle_len + cycle_len - i;
						if(idx<str_len) r+=s[idx];
					}
				}
			}
			//return
			return r;
		}
};
