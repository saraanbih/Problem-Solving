public class Solution {
    public bool ReorderedPowerOf2(int n) {
        var target = GetDigitKey(n);
        for(int i = 0;i<31;i++){
            if(GetDigitKey(1 << i) == target)return true;
        } 
        return false;
    }

    private string GetDigitKey(int n){
        char[] ans = n.ToString().ToCharArray();
        Array.Sort(ans);
        return (new string(ans));
    }
   
}