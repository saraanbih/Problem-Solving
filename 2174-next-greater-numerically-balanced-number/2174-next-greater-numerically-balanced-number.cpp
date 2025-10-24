class Solution {
public:
    bool balance(int x){
        vector<int> cnt(10);
        while(x > 0){
            cnt[x%10]++;
            x/=10;
        }
        for(int i=0;i<cnt.size();i++)
            if((cnt[i] > 0) && (cnt[i] != i))
                return false;
        return true;
    }
    int nextBeautifulNumber(int n) {
        //10^6 => 6 digits => 1000000 => 1224444
        for(int i = n+1; i <= 1224444; i++){
            if(balance(i))
                return i;
        }
        return 0;
    }
};