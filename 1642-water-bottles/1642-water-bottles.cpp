class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0,full = numBottles;
        int ans = 0;
        while(full){
            ans+=full;
            empty = full + (empty%numExchange);
            full = 0;
            full = empty / numExchange;
        }
        return ans;
    }
};