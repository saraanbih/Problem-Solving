class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxS = s;
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

        string minS = s;
        char toMin = 0;

        if (s[0] != '1') {
            toMin = s[0];
            for (char &c : minS) {
                if (c == toMin) c = '1';
            }
        } else {
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