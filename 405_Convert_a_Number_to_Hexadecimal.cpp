/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented
by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
		unsigned int unum = num;
		string output;
		if(unum==0) output.push_back('0');

		while(unum){
			if( (unum % 16)<10 ) output.insert( output.begin(), '0' + unum % 16 );
			else output.insert( output.begin(), 'a' + unum % 16 - 10 );
			unum /= 16;
		}

		return output;
    }
};
