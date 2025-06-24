class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> mark(n,false);
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                int l = max(0,i-k);
                int r = min(i+k,n+1);
                for(int j = l;j<=r;j++)
                    mark[j] = true;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mark[i])ans.push_back(i);
        }
        return ans;
    }
};