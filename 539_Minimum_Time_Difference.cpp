/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:

Input: ["23:59","00:00"]
Output: 1
Note:

The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int timeStr2Int(string& input){
	int hr = input[0]-'0';
	hr = hr*10+(input[1]-'0');
	int mi = input[3]-'0';
	mi = mi*10+(input[4]-'0');
	return hr*60+mi;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
		int len = timePoints.size();
		// fill in arrays of time points in integer
		vector<int> timePointsInt(len, 0);
		for(int i=0; i<len; ++i){
			timePointsInt[i] = timeStr2Int(timePoints[i]);
		}

		// sort timePoints in ascending order
		std::sort(timePointsInt.begin(), timePointsInt.end());

		// iterate through timePoints and find the minimal difference in time;
		int res = INT_MAX;
		for(int i=0; i<len; ++i){
			if(i>0){
				res = min(res, timePointsInt[i] - timePointsInt[i-1]);
			}
			else{
				res = min(res, 24*60 + timePointsInt[0] - timePointsInt[len-1]);
			}
		}

		// return
		return res;
    }
};
