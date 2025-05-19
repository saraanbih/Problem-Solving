class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n1 = nums[0],n2=nums[1],n3=nums[2];
        cout << n1 << " " << n2 << " " << n3;
        if((n1+n2<=n3) || (n2+n3<=n1) || (n1+n3<=n2))return "none";
        int unique = 0;
        if((n1 != n2) && (n1!=n3))unique++;
        if((n2!=n1) && (n2!=n3))unique++;
        if((n3!=n1) && (n3!=n2))unique++;
        if(unique == 0)return "equilateral";
        if(unique == 1)return "isosceles";
        return "scalene";
    }
};