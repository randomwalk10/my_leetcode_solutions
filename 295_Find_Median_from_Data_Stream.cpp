/*
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/
#include <queue>
#include <functional>
using namespace std;

class MedianFinder {
private:
	std::priority_queue<int> lower_half;//its size is greater or equal to higher_half
	std::priority_queue<int, std::vector<int>, std::greater<int>> higher_half;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
		if(lower_half.size()>higher_half.size()){
			if(num<lower_half.top()){
				lower_half.push(num);
				higher_half.push(lower_half.top());
				lower_half.pop();
			}
			else{
				higher_half.push(num);
			}
		}
		else{
			if( (lower_half.empty())|| \
					(num<=lower_half.top()) ){
				lower_half.push(num);
			}
			else{
				higher_half.push(num);
				lower_half.push(higher_half.top());
				higher_half.pop();
			}
		}
    }

    double findMedian() {
		return (lower_half.size()==higher_half.size()) ? \
								  (lower_half.top()+higher_half.top()) / 2.0 : \
								  lower_half.top() ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
