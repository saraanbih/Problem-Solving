class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)return 0;

        int k = 0;
        int cur = 1;
        while(2*cur <= n){
            cur*=2;
            k++;
        }

        return (1 << (k+1)) - 1 - minimumOneBitOperations(n ^ cur);
    }
};