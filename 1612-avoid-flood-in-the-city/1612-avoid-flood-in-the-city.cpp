class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); 

        unordered_map<int, int> lastRain; 
        set<int> dryDays;                 

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake == 0) {
                dryDays.insert(i); 
            } else {
                ans[i] = -1; 
                if (lastRain.count(lake)) {
                    int lastDay = lastRain[lake];

                    auto it = dryDays.upper_bound(lastDay);
                    if (it == dryDays.end())
                        return {}; 

                    int dryIndex = *it;
                    ans[dryIndex] = lake; 
                    dryDays.erase(it);
                }
                lastRain[lake] = i; 
            }
        }
        return ans;
    }
};
