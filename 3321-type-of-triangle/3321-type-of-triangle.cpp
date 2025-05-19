class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n1 = nums[0],n2=nums[1],n3=nums[2];
        if((n1+n2>n3) && (n2+n3>n1) && (n1+n3>n2)){
            if((n1 == n2) && (n2 == n3))return "equilateral";
            if((n1 == n2) || (n1 == n3) || (n2 == n3))return "isosceles";
            return "scalene";
        }        
        return "none";
    }
};