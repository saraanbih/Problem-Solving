public class Solution {
    public bool IsPowerOfThree(int n) {
        double N = n;
        while(N > 1){
            N/=3.0;
        }
        return (N==1.0);
    }
}