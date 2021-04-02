#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
		string res;
		long long cnt = 0;
		int i;
		for (i = 0; i < S.size(); ++i) {
			if((S[i]>='a')&&(S[i]<='z')){
				++cnt;
				if(cnt==(long long)K){
					res = S[i];
					return res;
				}
			}
			else{
				cnt *= (S[i]-'0');
				if(cnt>=(long long)K){
					break;
				}
			}
		}
		while(cnt>=(long long)K){
			if((S[i]>='a')&&(S[i]<='z')){
				if(cnt>(long long)K){
					--i;
					--cnt;
				}
				else break;
			}
			else{
				if(cnt>(long long)K){
					cnt /= S[i] - '0';
					K %= cnt;
					if(K==0) K = cnt;
					--i;
				}
				else{
					cnt /= S[i] - '0';
					K /= S[i] - '0';
					--i;
				}
			}
		}
		res = S[i];
		return res;
    }
};

