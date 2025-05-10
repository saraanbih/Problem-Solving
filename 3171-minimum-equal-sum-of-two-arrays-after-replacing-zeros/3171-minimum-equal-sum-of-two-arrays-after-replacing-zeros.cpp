class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
       long long s1 = std::accumulate(nums1.begin(),nums1.end(),0LL);
       long long s2 = std::accumulate(nums2.begin(),nums2.end(),0LL);
       int z1 = count(nums1.begin(),nums1.end(),0);
       int z2 = count(nums2.begin(),nums2.end(),0);
       s1+=z1;
       s2+=z2;
       if(!z1 && s2>s1 || !z2 && s1>s2)return -1;
       return max(s1,s2);
    }
};