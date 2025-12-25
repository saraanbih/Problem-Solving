class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(), h.end(), greater<int>());
        
        long long total = 0;
        int t = 0;
        
        for(int i = 0; i < k; i++) {
            total += max(h[i] - t, 0);  

            t++; 
        }
        
        return total;
    }
};