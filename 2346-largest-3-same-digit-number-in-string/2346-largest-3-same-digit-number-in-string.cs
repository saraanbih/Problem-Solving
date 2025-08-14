public class Solution {
    public string LargestGoodInteger(string num) {
       string mx = "";
       int n = num.Length;
       
       for(int i = 0;i<=n-3;i++){
            if((num[i] == num[i+1]) && (num[i] == num[i+2])){
                string str = num.Substring(i,3);
                if(string.Compare(str,mx) > 0)
                    mx = str;
            }
       }

       return mx;
    }
}
