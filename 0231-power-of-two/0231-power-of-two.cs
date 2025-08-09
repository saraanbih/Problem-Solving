public class Solution {
    public bool IsPowerOfTwo(int n) {
        double num = n;
        while(num > 1.0){
            num/=2.0;
        }
        return (num == 1.0);
    }
}