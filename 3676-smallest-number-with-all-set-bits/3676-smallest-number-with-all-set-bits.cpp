class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    int smallestNumber(int n) {
        for(int i = n+1;i<=100000;i++)
            if(isPowerOfTwo(i))
                return i - 1;
        return -1;
    }
};