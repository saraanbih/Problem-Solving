public class Solution {
    public bool IsPowerOfFour(int n) {
        double N = n;
        while(N > 1){
            N/=4.0;
        }
        return (N == 1.0);
    }
}