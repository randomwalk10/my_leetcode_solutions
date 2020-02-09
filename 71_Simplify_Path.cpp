/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		stack<string> s;
		int i=0;
		string w;
		while(i<(int)path.size()){
			if(path[i]=='/'){
				if( (w.size()==2)&&(w=="..") ){
					if(!s.empty()) s.pop();
				}
				else if( (!w.empty())&&(w!=".") ){
					s.push(w);
				}
				w.clear();
			}
			else{
				w.push_back(path[i]);
			}
			++i;
		}
		if( (w.size()==2)&&(w=="..") ){
			if(!s.empty()) s.pop();
		}
		else if( (!w.empty())&&(w!=".") ){
			s.push(w);
		}

		string res;
		stack<string> s2;
		while(!s.empty()){
			s2.push(s.top());
			s.pop();
		}
		while(!s2.empty()){
			res.append("/"+s2.top());
			s2.pop();
		}

		return (res.empty())?"/":res;
    }
};
