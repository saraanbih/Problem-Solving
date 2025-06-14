class Solution {
public:
    int minMaxDifference(int num) {
        string st = to_string(num);

        char toReplaceForMax = 0;
        for (char ch : st) {
            if (ch != '9') {
                toReplaceForMax = ch;
                break;
            }
        }

        string maxStr = st;
        if (toReplaceForMax) {
            for (char& ch : maxStr) {
                if (ch == toReplaceForMax) {
                    ch = '9';
                }
            }
        }

        char toReplaceForMin = st[0];

        string minStr = st;
        if (toReplaceForMin != '0') {
            for (char& ch : minStr) {
                if (ch == toReplaceForMin) {
                    ch = '0';
                }
            }
        }

        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};
