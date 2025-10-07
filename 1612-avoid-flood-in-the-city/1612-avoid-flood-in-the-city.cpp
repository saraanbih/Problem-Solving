class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // default to drying any lake when possible

        unordered_map<int, int> lastRain; // lake -> last day it was filled
        set<int> dryDays;                 // indices of days with 0 (dry days)

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake == 0) {
                dryDays.insert(i); // can use this day later to dry
            } else {
                ans[i] = -1; // raining day
                if (lastRain.count(lake)) {
                    // this lake is already full, we must dry it before now
                    int lastDay = lastRain[lake];

                    // find the earliest dry day AFTER lastDay
                    auto it = dryDays.upper_bound(lastDay);
                    if (it == dryDays.end())
                        return {}; // no dry day available => flood

                    int dryIndex = *it;
                    ans[dryIndex] = lake; // dry this lake on that day
                    dryDays.erase(it);
                }
                lastRain[lake] = i; // update last rain day
            }
        }
        return ans;
    }
};
