class Solution {
public:
    vector<long long> generatePalindromes(int n) {
        vector<long long> palindromes;
        int half = (n + 1) / 2;
        int start = pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; ++i) {
            string first_half = to_string(i);
            string second_half = first_half;

            if (n % 2 == 1) second_half.pop_back();
            reverse(second_half.begin(), second_half.end());
            string full = first_half + second_half;

            long long pal = stoll(full);  // Use stoll for large numbers
            palindromes.push_back(pal);
        }

        return palindromes;
    }

    long long factorial[11];

    void precomputeFactorials() {
        factorial[0] = 1;
        for (int i = 1; i <= 10; ++i)
            factorial[i] = factorial[i - 1] * i;
    }

    long long countPermutations(vector<int>& freq, int n) {
        long long total = factorial[n];
        for (int i = 0; i <= 9; ++i)
            total /= factorial[freq[i]];
        return total;
    }

    long long countValidPermutations(vector<int>& freq, int n) {
        long long total = countPermutations(freq, n);
        if (freq[0] == 0) return total;
        freq[0]--;
        long long invalid = countPermutations(freq, n - 1);
        freq[0]++;
        return total - invalid;
    }

    long long countGoodIntegers(int n, int k) {
        precomputeFactorials();

        vector<long long> pal = generatePalindromes(n);
        set<string> seen;
        long long cnt = 0;

        for (long long p : pal) {
            if (p % k != 0) continue;

            string s = to_string(p);
            vector<int> freq(10, 0);
            for (char c : s) freq[c - '0']++;

            string key = "";
            for (int f : freq) key += to_string(f) + "#";

            if (seen.count(key)) continue;
            seen.insert(key);

            cnt += countValidPermutations(freq, n);
        }

        return cnt;
    }
};
