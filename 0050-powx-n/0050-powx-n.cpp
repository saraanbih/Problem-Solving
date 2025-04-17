class Solution {
public:
    double help(double x,long long n){
       if(n == 0) return 1;
       double res = myPow(x*x,n/2);
       if(n % 2)
            res*=x;
        return res;
    }
    double myPow(double x, int n) {
        long long l = n;
        if(l < 0){
            x = 1/x;
            l=-l;
        }
        return help(x,l);
    }
};