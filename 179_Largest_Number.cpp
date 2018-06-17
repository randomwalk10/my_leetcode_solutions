/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool sortByInitial(int a, int b){
		if( (a==0)||(b==0) ) return a<b;
		int digits_a = 0;
		int digits_b = 0;

		int temp = a;
		while(temp){
			digits_a++;
			temp /= 10;
		}
		temp = b;
		while(temp){
			digits_b++;
			temp /= 10;
		}

		if(digits_a!=digits_b){
			temp = a;
			while(digits_b){
				a *= 10;
				digits_b--;
			}
			a += b;
			while(digits_a){
				b *= 10;
				digits_a--;
			}
			b += temp;
		}

		return (a<b);
	}

	string convertInt2Str(int num){
		string out;
		if(num==0) out.push_back('0');
		else{
			while(num>0){
				out.insert(out.begin(), '0'+num%10);
				num /= 10;
			}
		}
		return out;
	}

    string largestNumber(vector<int>& nums) {
		string out;
		//sort nums by initials
		std::sort(nums.begin(), nums.end(), sortByInitial); 
		//create strings from nums
		for(int i= nums.size()-1; i>=0; --i){ 
			string add = this->convertInt2Str(nums[i]);
			if(out=="0") out = add;
			else out += add;
		}
		//return
		return out;
    }
};
