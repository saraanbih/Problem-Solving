class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        stack<char> t;
        string res = "";
        vector<char> mn(n);

        mn[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mn[i] = min(mn[i + 1], s[i]);
        }

        for (int i = 0; i < n; i++) {
            t.push(s[i]);
            while (!t.empty() && (i == n - 1 || t.top() <= mn[i + 1])) {
                res += t.top();
                t.pop();
            }
        }

        return res;
    }
};
