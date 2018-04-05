/*
 * Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

O(n)
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> hash;
		unordered_map<int, int>::iterator iter;
		for(int i=0; i<(int)nums.size(); i++){
			iter = hash.find(nums[i]);
			if(iter != hash.end()){
				result.push_back(iter->second);
				result.push_back(i);
				return result;
			}
			else{
				hash[target-nums[i]] = i;
			}
		}
		return result;
    }
};
