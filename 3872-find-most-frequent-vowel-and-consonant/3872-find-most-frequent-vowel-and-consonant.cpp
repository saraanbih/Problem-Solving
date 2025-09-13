class Solution {
public:
    int maxFreqSum(string s) {
        int cnt[26] = {0};
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int cnt_v = 0, cnt_c = 0;
        for(auto &ch : s){
            int idx = ch - 'a';
            cnt[idx]++;
            if(vowels.count(ch))
                cnt_v = max(cnt_v,cnt[idx]);
            else
                cnt_c = max(cnt_c,cnt[idx]);
        }
        return cnt_v + cnt_c;
    }
};