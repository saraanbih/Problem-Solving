class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
        for(auto &ch : s)
            freq[ch]++;
        int ev = INT_MAX,od=INT_MIN;
        for(auto &pair : freq){
            if(pair.second%2==0)ev = min(ev,pair.second);
            else od = max(od,pair.second);
        }
        return od - ev;
    }
};