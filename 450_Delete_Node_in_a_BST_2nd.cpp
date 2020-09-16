struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode* res = root;

		TreeNode* parent = nullptr;
		TreeNode* head = root;
		while(head){
			if(head->val<key){
				parent = head;
				head = head->right;
			}
			else if(head->val>key){
				parent = head;
				head = head->left;
			}
			else{
				break;
			}
		}
		if(nullptr==head) return res;

		if(head->left){
			TreeNode* tmp_p = head;
			TreeNode* tmp = head->left;
			while(true){
				if(tmp->right){
					tmp_p = tmp;
					tmp = tmp->right;
				}
				else break;
			}
			head->val = tmp->val;
			if(tmp_p->left==tmp) tmp_p->left = tmp->left;
			else tmp_p->right = tmp->left;
		}
		else if(head->right){
			TreeNode* tmp_p = head;
			TreeNode* tmp = head->right;
			while(true){
				if(tmp->left){
					tmp_p = tmp;
					tmp = tmp->left;
				}
				else break;
			}
			head->val = tmp->val;
			if(tmp_p->left==tmp) tmp_p->left = tmp->right;
			else tmp_p->right = tmp->right;
		}
		else{
			if(head==root) res=nullptr;
			else if(parent->left==head) parent->left = nullptr;
			else parent->right = nullptr;
		}

		return res;
    }
};
