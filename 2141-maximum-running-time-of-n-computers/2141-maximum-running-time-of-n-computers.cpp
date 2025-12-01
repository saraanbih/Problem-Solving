class Solution {
public:
    #define ll long long
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        ll sum = accumulate(batteries.begin(),batteries.end(),0LL);
        for(int i=batteries.size() - 1;i>=0;i--){
            if(batteries[i] <= sum/n)break;
            sum -= batteries[i];
            n--;
        }
        return sum/n;
    }
};