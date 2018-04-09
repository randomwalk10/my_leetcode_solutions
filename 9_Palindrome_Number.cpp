/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0) return false;
		else if(x==0) return true;
		else if(x%10==0) return false;
		int temp_out = 0;
		while(x > temp_out){
			temp_out = 10*temp_out + x%10;
			x /= 10;
		}
		return (x==temp_out) || (x==temp_out/10);
    }
};
