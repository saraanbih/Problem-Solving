class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
       long sum =0,mn=0,mx=0;
       for(auto&d : differences){
          sum+=d;
          mn = min(mn,sum);
          mx = max(mx,sum);
       }
       long mn_st = lower - mn;
       long mx_st = upper - mx;
       return max(0L,mx_st-mn_st+1);
    }
};