class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end()),st;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            if(st.size() == s.size())cnt++;
            for(int j=i+1;j<nums.size();j++){
                st.insert(nums[j]);
                if(st.size() == s.size())cnt++;
            }
            st = {};
        }
        return cnt;
    }
};