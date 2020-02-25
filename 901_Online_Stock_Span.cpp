/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

 

Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 

Note:

Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
There will be at most 10000 calls to StockSpanner.next per test case.
There will be at most 150000 calls to StockSpanner.next across all test cases.
The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/online-stock-span
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/* O(N) in time and O(N) in space */
#include <stack>
using namespace std;

class StockSpanner {
private:
    int i;
    stack<int> s, l;
public:
    StockSpanner() {
        i = -1;
    }

    int next(int price) {
        ++i;
        int res;

        while( (!s.empty())&&(s.top()<=price) ){
            s.pop();
            l.pop();
        }
        if(s.empty()) res = i + 1;
        else res = i - l.top();

        s.push(price);
        l.push(i);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
