class Solution {
public:
   
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int target = skill[0] + skill[n-1];
        int l = 1,r = n-2;
        long long res = skill[0] * skill[n-1];
        while(l < r)
        {
            if((skill[l] + skill[r]) != target) return -1;
            res += (skill[l] * skill[r]);
            l++,r--;
        }
        return res;
    }
};