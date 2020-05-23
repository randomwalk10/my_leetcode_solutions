/*
In a project, you have a list of required skills req_skills, and a list of people.  The i-th person people[i] contains a list of skills that person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill.  We can represent these teams by the index of each person: for example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return any sufficient team of the smallest possible size, represented by the index of each person.

You may return the answer in any order.  It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 

Constraints:

1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
Elements of req_skills and people[i] are (respectively) distinct.
req_skills[i][j], people[i][j][k] are lowercase English letters.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-sufficient-team
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(2^N) in time and O(N) in space where N is the length of people */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	void smallestSufficientTeam(unordered_map<string, int>& skill2code,
			int req_codes, vector<int>& people_coded, vector<int>& people_indice,
			int idx, long long& team_list, int& team_size){
		if(req_codes==0) return;
		if(idx>=(int)people_indice.size()){
			team_size = -1;
			return;
		}
		// skip idx
		long long temp_team_list = team_list;
		int temp_team_size = team_size;
		smallestSufficientTeam(skill2code, req_codes, \
				people_coded, people_indice, idx+1, \
				temp_team_list, temp_team_size);
		// use idx
		req_codes &= ~(people_coded[people_indice[idx]]);
		team_list |= ((long long)1<<idx);
		++team_size;
		smallestSufficientTeam(skill2code, req_codes, \
				people_coded, people_indice, idx+1, \
				team_list, team_size);
		if( (temp_team_size<0)&&(team_size<0) ) return;
		else if(temp_team_size<0) return;
		else if(team_size<0){
			team_size = temp_team_size;
			team_list = temp_team_list;
		}
		else if(temp_team_size<team_size){
			team_size = temp_team_size;
			team_list = temp_team_list;
		}
	}
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		// skill2code, req_codes
		unordered_map<string, int> skill2code;
		int i;
		for (i = 0; i < (int)req_skills.size(); ++i) {
			skill2code[req_skills[i]] = i;
		}
		int req_codes = (1<<i)-1;

		// compress people
		vector<int> people_coded;
		vector<int> people_indice;
		for (i = 0; i < (int)people.size(); ++i) {
			int j;
			int temp = 0;
			for (j = 0; j < (int)people[i].size(); ++j) {
				int code = skill2code[people[i][j]];
				temp |= (1<<code);
			}
			people_coded.push_back(temp);
		}
		for (i = 0; i < (int)people.size(); ++i) {
			int j;
			bool skip = false;
			for (j = i+1; j < (int)people.size(); ++j) {
				if((people_coded[i]|people_coded[j])==people_coded[j]){
					skip = true;
					break;
				}
			}
			if(skip) continue;

			skip = false;
			for (j = 0; j < (int)people_indice.size(); ++j) {
				int prev = people_indice[j];
				if((people_coded[i]|people_coded[prev])==people_coded[prev]){
					skip = true;
					break;
				}
			}
			if(skip) continue;

			people_indice.push_back(i);
		}

		// get res
		vector<int> res;
		long long team_list=0;
		int team_size=0;
		smallestSufficientTeam(skill2code, req_codes, people_coded, people_indice, \
				0, team_list, team_size);
		for (int i = 0; i < 60; ++i) {
			if(team_list&0x1)
				res.push_back(people_indice[i]);
			team_list>>=1;
		}
		return res;
    }
};
