class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 20010;
    
    long long power(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        if (r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    unordered_map<int, int> primeFactors(int x) {
        unordered_map<int, int> factors;
        for (int i = 2; i * i <= x; ++i) {
            while (x % i == 0) {
                factors[i]++;
                x /= i;
            }
        }
        if (x > 1)
            factors[x]++;
        return factors;
    }

    int idealArrays(int n, int maxValue) {
        vector<long long> fact(MAX), invFact(MAX);
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < MAX; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
            invFact[i] = power(fact[i], MOD - 2);
        }

        long long total = 0;
        for (int num = 1; num <= maxValue; ++num) {
            auto factors = primeFactors(num);
            long long ways = 1;
            for (auto& [prime, exponent] : factors) {
                ways = ways * nCr(n - 1 + exponent, exponent, fact, invFact) % MOD;
            }
            total = (total + ways) % MOD;
        }
        return total;
    }
};
