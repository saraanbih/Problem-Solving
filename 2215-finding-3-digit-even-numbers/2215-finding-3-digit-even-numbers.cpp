class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        bool used[10] = {false};
        for (int d : digits) used[d] = true;

        vector<int> result;

        // Try all 3-digit numbers from 100 to 998 (step by 2 to ensure even)
        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            // Count how many times each digit appears in num
            int freq[10] = {0};
            freq[a]++;
            freq[b]++;
            freq[c]++;

            bool canForm = true;
            int available[10] = {0};
            for (int d : digits) available[d]++;

            for (int d = 0; d <= 9; ++d) {
                if (freq[d] > available[d]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm)
                result.push_back(num);
        }

        return result;
    }
};
