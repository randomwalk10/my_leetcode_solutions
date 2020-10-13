#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
		if(1==N) return {new TreeNode(0)};
		vector<vector<TreeNode*>> results(N+1, vector<TreeNode*>());
		results[1] = {new TreeNode(0)};

		for (int i = 2; i <= N; ++i) {
			for (int j = 0; j < i; ++j) {
				for (size_t x = 0; x < results[j].size(); ++x) {
					for (size_t y = 0; y < results[i-j-1].size(); ++y) {
						TreeNode* head = new TreeNode(0);
						head->left = results[j][x];
						head->right = results[i-j-1][y];
						results[i].push_back(head);
					}
				}
			}
		}

		return results[N];
    }
};
