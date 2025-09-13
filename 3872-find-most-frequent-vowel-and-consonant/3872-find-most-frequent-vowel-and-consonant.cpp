class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> cnt;
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int cnt_v = 0, cnt_c = 0;
        for(auto &ch : s){
            if(vowels.count(ch)){
                cnt[ch]++;
                cnt_v = max(cnt_v,cnt[ch]);
            }
            else{
                cnt[ch]++;
                cnt_c = max(cnt_c,cnt[ch]);
            }
        }
        return cnt_v + cnt_c;
    }
};