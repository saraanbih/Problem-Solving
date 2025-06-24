class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> vec,v2;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == key)vec.insert(i);
        for(int i=0;i<nums.size();i++){
            for(auto idx : vec){
                if(abs(idx-i)<=k){
                    v2.insert(i);
                    break;
                }
            }
        }
        vector<int> ans(v2.begin(),v2.end());
        return ans;
    }
};