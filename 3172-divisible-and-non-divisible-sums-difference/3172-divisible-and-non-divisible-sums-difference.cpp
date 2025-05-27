class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n*(n+1))/2;
        if(n<m)return sum;
        int divisible = 0;
        for(int i=m;i<=n;i+=m)divisible+=i;
        return (sum-divisible) - divisible;
    }
};