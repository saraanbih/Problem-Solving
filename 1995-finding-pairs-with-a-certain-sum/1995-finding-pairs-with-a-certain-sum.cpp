class FindSumPairs {
public:
    unordered_map<int,int> freq1,freq2;
    vector<int> n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &num : nums1)freq1[num]++;
        for(auto &num : nums2)freq2[num]++;
        n2 = nums2;
    }
    
    void add(int index, int val) {
        int od = n2[index];
        freq2[od]--;
        if(freq2[od] == 0)freq2.erase(od);
        n2[index]+=val;
        freq2[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto& [num , f] : freq1){
            int target = tot - num;
            if(freq2.count(target)){
                cnt += (f * freq2[target]);
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */