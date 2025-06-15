class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // === Create max number ===
        string maxS = s;
        // Find first digit that's not 9 to replace
        char toMax = 0;
        for (char c : s) {
            if (c != '9') {
                toMax = c;
                break;
            }
        }
        if (toMax) {
            for (char &c : maxS) {
                if (c == toMax) c = '9';
            }
        }

        // === Create min number ===
        string minS = s;
        char toMin = 0;

        if (s[0] != '1') {
            // Replace first digit with 1
            toMin = s[0];
            for (char &c : minS) {
                if (c == toMin) c = '1';
            }
        } else {
            // Replace first digit ≠ 0 or 1 with 0 (but not the first digit itself!)
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    toMin = s[i];
                    for (int j = 1; j < minS.size(); j++) {
                        if (minS[j] == toMin) minS[j] = '0';
                    }
                    break;
                }
            }
        }

        int maxNum = stoi(maxS);
        int minNum = stoi(minS);
        return maxNum - minNum;
    }
};
