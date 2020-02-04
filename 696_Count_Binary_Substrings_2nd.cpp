class Solution {
public:
    int countBinarySubstrings(string s) {
      int l=0, r=0, cnt_l=1, cnt_r=0;
      int res = 0;
      int state = 0;
      while(true) {
          if(l>=(int)s.size()) break;
          if((++r)>=(int)s.size()){
              res += min(cnt_l, cnt_r);
              break;
          }
          if(state==0){
              if(s[l]==s[r]) ++cnt_l;
              else{
                  cnt_r = 1;
                  state = 1;
              }
          }
          else if(state==1){
              if(s[l]!=s[r]) ++cnt_r;
              else{
                  res += min(cnt_l, cnt_r);
                  l = r - cnt_r;
                  cnt_l = cnt_r; cnt_r = 1;
              }
          }
      }
      return res;
    }
};
