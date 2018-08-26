/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isShorter(string a, string b){
	return a.size()<b.size();
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
		string out;
		bool isReplaced;
		//sort dict in the order of ascending string lengths
		sort(dict.begin(), dict.end(), isShorter);
		//replace successor with root
		size_t idx = 0;
		while(idx<sentence.size()){
			//replace current word
			isReplaced = false;
			for(int i=0; i<(int)dict.size(); ++i){
				if( (idx+dict[i].size())<=sentence.size() ){
					isReplaced = true;
					for(int j=0; j<(int)dict[i].size(); ++j){
						if(sentence[idx+j]!=dict[i][j]){
							isReplaced = false;
							break;
						}
					}
					if(isReplaced){
						for(int j=0; j<(int)dict[i].size(); ++j){
							out.push_back(dict[i][j]);
						}
						break;
					}
				}
			}
			while( (idx<sentence.size()) && \
					(' '!=sentence[idx]) ){
				if(!isReplaced) out.push_back(sentence[idx]);
				idx++;
			}
			//move to next word
			if(idx<sentence.size()) out.push_back(' ');
			idx++;
		}
		return out;
    }
};
