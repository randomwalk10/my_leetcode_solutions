/*
 * Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
int charToInt(const char input){
	switch (input) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
	return 0;
}

class Solution {
public:
    int romanToInt(string s) {
		if(s.empty()) return 0;
		int count = 0;
		for (int i = 0; i < s.size();  ++i) {
			int temp = charToInt(s[i]);
			if(i!=(s.size()-1)){
				int next = charToInt(s[i+1]);
				if(temp<next) temp = -temp;
			}
			count += temp;
		}
		return count;
    }
};
