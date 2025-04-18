class Solution {
public:
    double myPow(double x, int N) {
        long long n = N;
        if(N < 0){
            x = 1/x;
            n = -n;
        }
       if(n==0) return 1;
       double ans = myPow(x*x,n/2);
       if(n%2)ans*=x;
       return ans;
    }
};