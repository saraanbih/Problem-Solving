class Solution {
public:
    int countOdds(int l, int h) {
        int ans = 0;
        if(l%2 == 0)l++;
        for(int i =l;i<=h;i+=2)
            ans++;
        return ans;
    }
};