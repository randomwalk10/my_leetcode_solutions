/*
Given a chemical formula (given as a string), return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

 

 

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Example 4:

Input: formula = "Be32"
Output: "Be32"
 

Constraints:

1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-atoms
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <deque>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
		stack<map<string, int>> s_m;
		s_m.push(map<string, int>());
		string res;

		int i = 0;
		while (i<formula.size()) {
			if(formula[i]=='('){
				s_m.push(map<string, int>());
				++i;
			}
			else if(formula[i]==')'){
				map<string, int> tmp_m = s_m.top();
				s_m.pop();
				++i;
				int tmp = 0;
				while((formula[i]>='0')&&(formula[i]<='9')){
					tmp *= 10;
					tmp += formula[i]-'0';
					++i;
				}
				tmp = max(1, tmp);
				for(auto iter=tmp_m.begin(); iter!=tmp_m.end(); ++iter){
					s_m.top()[iter->first] += iter->second * tmp;
				}
			}
			else if((formula[i]>='A')&&(formula[i]<='Z')){
				//name
				string name;
				name.push_back(formula[i]);
				++i;
				while((formula[i]>='a')&&(formula[i]<='z')){
					name.push_back(formula[i]);
					++i;
				}
				//count
				int tmp = 0;
				while((formula[i]>='0')&&(formula[i]<='9')){
					tmp *= 10;
					tmp += formula[i]-'0';
					++i;
				}
				tmp = max(1, tmp);
				s_m.top()[name] += tmp;
			}
		}

		for(auto iter=s_m.top().begin(); iter!=s_m.top().end(); ++iter){
			res.append(iter->first);
			if(iter->second>1){
				int tmp = iter->second;
				deque<char> tmp_s;
				while(tmp>0){
					tmp_s.push_front((tmp%10)+'0');
					tmp /= 10;
				}
				while(tmp_s.empty()==false){
					res.push_back(tmp_s.front());
					tmp_s.pop_front();
				}
			}
		}
		return res;
    }
};
