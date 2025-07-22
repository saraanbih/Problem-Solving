class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0,r=0;
        int s = 0,mx = 0;
        int n = nums.size();
        unordered_set<int> dup;

        while(r < n){
            while(dup.find(nums[r]) != dup.end()){
                s-=nums[l];
                dup.erase(nums[l]);
                l++;
            } 
            s+=nums[r];
            dup.insert(nums[r]);
            mx = max(mx,s);
            r++;
        }     
        return mx;
    }
};