class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0;
        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        // Try alternating starting with odd
        int alt1 = 0;
        int last = -1; // -1 means start
        for (int num : nums) {
            int p = num % 2;
            if (alt1 == 0 || p != last) {
                alt1++;
                last = p;
            }
        }

        // Try alternating starting with even
        int alt2 = 0;
        last = -1;
        for (int num : nums) {
            int p = num % 2;
            if (alt2 == 0 || p != last) {
                alt2++;
                last = p;
            }
        }

        return max({odd, even, alt1, alt2});
    }
};
