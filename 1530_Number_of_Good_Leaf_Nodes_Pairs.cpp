/*
Given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	int countPairs(TreeNode* root, int distance, std::map<int, int>& m_cnt){
		if(NULL==root) return 0;
		std::map<int, int> m_cnt_l, m_cnt_r;
		int res = 0;
		res += countPairs(root->left, distance, m_cnt_l);
		res += countPairs(root->right, distance, m_cnt_r);
		for(std::map<int, int>::iterator iter_l = m_cnt_l.begin();
				iter_l != m_cnt_l.end(); ++iter_l){
			for(std::map<int, int>::iterator iter_r = m_cnt_r.begin();
					iter_r != m_cnt_r.end(); ++iter_r){
				if(iter_l->first+iter_r->first<=distance){
					res += iter_l->second * iter_r->second;
				}
				else break;
			}
		}
		for(std::map<int, int>::iterator iter = m_cnt_l.begin();
				iter != m_cnt_l.end(); ++iter){
			m_cnt[iter->first+1] += iter->second;
		}
		for(std::map<int, int>::iterator iter = m_cnt_r.begin();
				iter != m_cnt_r.end(); ++iter){
			m_cnt[iter->first+1] += iter->second;
		}
		if((NULL==root->left)&&(NULL==root->right)) m_cnt[1] = 1;
		return res;
	}
public:
    int countPairs(TreeNode* root, int distance) {
		std::map<int, int> m_cnt;
		return countPairs(root, distance, m_cnt);
    }
};
