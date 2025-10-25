class Solution {
public:
    int totalMoney(int num) {
        int weeks = num/7;
        int rem = num % 7;

        int ans = (28 * weeks) + (7 * ((weeks-1)*weeks / 2));
        ans+=(rem * (2*(weeks+1)+(rem-1))/2);
      
        return ans;

       
    }
};