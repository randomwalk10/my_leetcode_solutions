/*
A move consists of taking a point (x, y) and transforming it to either (x, x+y) or (x+y, y).

Given a starting point (sx, sy) and a target point (tx, ty), return True if and only if a sequence of moves exists to transform the point (sx, sy) to (tx, ty). Otherwise, return False.

Examples:
Input: sx = 1, sy = 1, tx = 3, ty = 5
Output: True
Explanation:
One series of moves that transforms the starting point to the target is:
(1, 1) -> (1, 2)
(1, 2) -> (3, 2)
(3, 2) -> (3, 5)

Input: sx = 1, sy = 1, tx = 2, ty = 2
Output: False

Input: sx = 1, sy = 1, tx = 1, ty = 1
Output: True

Note:

sx, sy, tx, ty will all be integers in the range [1, 10^9].
*/

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
		while( (sx<tx) || (sy<ty) ){
			if(tx==ty) return false;
			else if(tx>ty){
				if(sx>=tx) return false;
				int temp = (tx - sx) / ty;
				int temp2 = ( (tx - ty)%ty ) ? (tx-ty)/ty+1 : (tx-ty)/ty;
				temp = (temp2<temp)?temp2:temp;
				if(temp<1) return false;
				tx -= temp*ty;
			}
			else{
				if(sy>=ty) return false;
				int temp = (ty - sy) / tx;
				int temp2 = ( (ty - tx)%tx ) ? (ty-tx)/tx+1 : (ty-tx)/tx;
				temp = (temp2<temp)?temp2:temp;
				if(temp<1) return false;
				ty -= temp*tx;
			}
		}

		return (sx==tx)&&(sy==ty);
    }
};
