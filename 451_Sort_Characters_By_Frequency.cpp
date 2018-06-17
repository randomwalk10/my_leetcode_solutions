/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
		int freq[256] = {0};
		string out;
		//build up frequency table
		for(size_t i=0; i<s.size(); ++i){
			freq[int(s[i])]++;
		}
		//sort letters based on frequencies
		for(size_t i = 0; i<s.size(); ++i){
			int max_count = 0;
			char max_char = 0;
			for(size_t j = 0; j<256; ++j){
				if(freq[j] > max_count){
					max_count = freq[j];
					max_char = (char) j;
				}
			}
			if(max_count>0) freq[(int)max_char]=0;
			else break;
			while(max_count>0){
				out.push_back(max_char);
				max_count--;
			}
		}
		//return
		return out;
    }
};
