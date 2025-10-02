class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        for(int empty = numBottles;empty >= numExchange;numExchange++){
            res++;
            empty -= numExchange - 1;
        }
        return res;
    }
};