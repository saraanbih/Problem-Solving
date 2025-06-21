class Solution {
public:
    int minimumDeletions(string word, int k) {
        int res = INT_MAX;
        unordered_map<char,int> freq;
        for(auto &ch : word)freq[ch]++;
        for(auto &[_,a] : freq){
            int del = 0;
            for(auto &[_,b] : freq){
                if(a > b)del+=b;
                else if(b > a + k)del+=(b-(a+k));
            }
            res = min(res,del);
        }
        return res;
    }
};