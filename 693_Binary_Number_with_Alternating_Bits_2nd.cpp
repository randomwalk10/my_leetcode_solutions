class Solution {
public:
    bool hasAlternatingBits(int n) {
		unsigned int temp = n^(n>>1);
		return (temp&(temp+1))==0;
    }
};
