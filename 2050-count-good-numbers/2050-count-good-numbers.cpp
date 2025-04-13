class Solution {
public:
     static constexpr int mod = 1000000007;
    long long fast_power(long long base, long long exp) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = result * base % mod;
            base = base * base % mod;
            exp /= 2;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        long long even_pos = fast_power(5, (n + 1) / 2); // even positions
        long long odd_pos = fast_power(4, n / 2);        // odd positions
        return even_pos * odd_pos % mod;    
    }
};