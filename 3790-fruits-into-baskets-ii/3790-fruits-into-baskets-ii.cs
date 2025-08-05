public class Solution {
    public int NumOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.Length;
        int cnt = 0;
        foreach(int f in fruits){
            int var = 1;
            for(int i=0;i<n;i++){
                if(f <= baskets[i]){
                    baskets[i] = 0;
                    var = 0;
                    break;
                }
            }
            cnt+=var;
        }
        
        return cnt;
    }
}