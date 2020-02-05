/*
A quadtree is a tree data in which each internal node has exactly four children: topLeft, topRight, bottomLeft and bottomRight. Quad trees are often used to partition a two-dimensional space by recursively subdividing it into four quadrants or regions.

We want to store True/False information in our quad tree. The quad tree is used to represent a N * N boolean grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same. Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.

For example, below are two quad trees A and B:

A:
+-------+-------+   T: true
|       |       |   F: false
|   T   |   T   |
|       |       |
+-------+-------+
|       |       |
|   F   |   F   |
|       |       |
+-------+-------+
topLeft: T
topRight: T
bottomLeft: F
bottomRight: F

B:               
+-------+---+---+
|       | F | F |
|   T   +---+---+
|       | T | T |
+-------+---+---+
|       |       |
|   T   |   F   |
|       |       |
+-------+-------+
topLeft: T
topRight:
     topLeft: F
     topRight: F
     bottomLeft: T
     bottomRight: T
bottomLeft: T
bottomRight: F
 

Your task is to implement a function that will take two quadtrees and return a quadtree that represents the logical OR (or union) of the two trees.

A:                 B:                 C (A or B):
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       | F | F |  |       |       |
|   T   |   T   |  |   T   +---+---+  |   T   |   T   |
|       |       |  |       | T | T |  |       |       |
+-------+-------+  +-------+---+---+  +-------+-------+
|       |       |  |       |       |  |       |       |
|   F   |   F   |  |   T   |   F   |  |   T   |   F   |
|       |       |  |       |       |  |       |       |
+-------+-------+  +-------+-------+  +-------+-------+
Note:

Both A and B represent grids of size N * N.
N is guaranteed to be a power of 2.
If you want to know more about the quad tree, you can refer to its wiki.
The logic OR operation is defined as this: "A or B" is true if A is true, or if B is true, or if both A and B are true.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/quad-tree-intersection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
#define NULL 0

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
	Node* _copy(Node* root){
		if(root==NULL) return NULL;
		Node* res = new Node(root->val, root->isLeaf, _copy(root->topLeft), _copy(root->topRight), \
				_copy(root->bottomLeft), _copy(root->bottomRight));
		return res;
	}
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
		if((quadTree1==NULL)&&(quadTree2==NULL)) return NULL;
		else if(quadTree1==NULL){
			return _copy(quadTree2);
		}
		else if(quadTree2==NULL){
			return _copy(quadTree1);
		}

		Node* res = NULL;
		if(quadTree1->isLeaf){
			if(quadTree1->val){
				res = new Node(true, true, NULL, NULL, NULL, NULL);
			}
			else{
				res = _copy(quadTree2);
			}
		}
		else if(quadTree2->isLeaf){
			if(quadTree2->val){
				res = new Node(true, true, NULL, NULL, NULL, NULL);
			}
			else{
				res = _copy(quadTree1);
			}
		}
		else{
			res = new Node(false, false, \
					intersect(quadTree1->topLeft, quadTree2->topLeft), \
					intersect(quadTree1->topRight, quadTree2->topRight), \
					intersect(quadTree1->bottomLeft, quadTree2->bottomLeft), \
					intersect(quadTree1->bottomRight, quadTree2->bottomRight));
			if(res->topLeft->isLeaf&&res->topRight->isLeaf&&res->bottomLeft->isLeaf&& \
					res->bottomRight->isLeaf){
				if(res->topLeft->val&&res->topRight->val&&res->bottomLeft->val&& \
						res->bottomRight->val){
					delete res;
					res = new Node(true, true, NULL, NULL, NULL, NULL);
				}
				else if((!res->topLeft->val)&&(!res->topRight->val)&&(!res->bottomLeft->val)&& \
						(!res->bottomRight->val)){
					delete res;
					res = new Node(false, true, NULL, NULL, NULL, NULL);
				}
			}
		}
		//return
		return res;
    }
};
