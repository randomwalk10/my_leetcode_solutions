/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-dna-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	int convert_to_int(char x){
		if(x=='A') return 0;
		else if(x=='C') return 1;
		else if(x=='G') return 2;
		return 3;
	}
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		unordered_map<int, int> m;
		int hashval = 0;
		int mask = (1<<20)-1;

		for (int i = 0; i < (int)s.size(); ++i) {
			hashval = ((hashval<<2) + convert_to_int(s[i])) & mask;
			if(i<9) continue;
			unordered_map<int, int>::iterator iter = m.find(hashval);
			if(iter!=m.end()){
				if(iter->second==1){
					// TODO append to res
					string temp;
					for (int j = i-9; j <= i; ++j) {
						temp.push_back(s[j]);
					}
					res.push_back(temp);
					++iter->second;
				}
			}
			else{
				m[hashval] = 1;
			}

		}

		return res;
    }
};
