class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++){
            int num = i,s=0;
            while(num){
                s+=(num%10);
                num/=10;
            }
            mp[s]++;
        }
        int mx = INT_MIN,cnt=0;
        for(auto &pair : mp)mx = max(mx,pair.second);
        for(auto &pair : mp)if(pair.second == mx)cnt++;
        return cnt;
    }
};