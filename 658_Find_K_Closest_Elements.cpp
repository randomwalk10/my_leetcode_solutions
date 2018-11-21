/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:

Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:

Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:

The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104

UPDATE (2017/9/19):
The arr parameter had been changed to an array of integers (instead of a list of integers). Please reload the code definition to get the latest changes.
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int l=0, r=(int)arr.size()-1;
		vector<int> out;
		//find the range of closed element
		if(arr[l]>=x) r=l;
		else if(arr[r]<x) l=r;
		else{
			while(l+1<r){
				//binary search
				int mid = (l+r)/2;
				if(arr[mid]>=x){
					r=mid;
				}
				else{
					l=mid;
				}
			}
			if(abs(arr[l]-x)<=abs(arr[r]-x))
				r=l;
			else
				l=r;
		}
		//expand to k elements
		int cnt=1;
		while(cnt<k){
			//update out
			if(l-1<0){
				r++;
			}
			else if(r+1>=(int)arr.size()){
				l--;
			}
			else if(abs(arr[l-1]-x)<=abs(arr[r+1]-x)){
				l--;
			}
			else{
				r++;
			}
			//update cnt
			cnt++;
		}
		//fill in out
		for(int i=l; i<=r; ++i)
			out.push_back(arr[i]);
		//return
		return out;
    }
};
