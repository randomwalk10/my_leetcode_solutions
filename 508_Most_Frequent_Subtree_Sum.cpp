/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int getSubtreeSums(TreeNode* root, unordered_map<int, int>& freqMap){
		if(NULL==root) return 0;
		int sum = getSubtreeSums(root->left, freqMap) + \
				  getSubtreeSums(root->right, freqMap) + root->val;
		if(freqMap.find(sum) == freqMap.end()) freqMap[sum] = 1;
		else freqMap[sum]++;

		return sum;
	}	

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> freqMap;

		getSubtreeSums(root, freqMap);

		int max_count = 0;
		for(unordered_map<int, int>::iterator iter = freqMap.begin();
				iter != freqMap.end(); ++iter){
			max_count = (iter->second > max_count) ? \
						iter->second : max_count;
		}

		vector<int> out;
		for(unordered_map<int, int>::iterator iter = freqMap.begin();
				iter != freqMap.end(); ++iter){
			if(iter->second==max_count) out.push_back(iter->first);
		}

		return out;
    }
};
