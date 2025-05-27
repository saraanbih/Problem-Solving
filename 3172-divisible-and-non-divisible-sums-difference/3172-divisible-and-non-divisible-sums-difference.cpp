class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n*(n+1))/2;
        int cnt = n/m;
        int divisible = m * cnt*(cnt+1) / 2;
        return (sum-divisible) - divisible;
    }
};