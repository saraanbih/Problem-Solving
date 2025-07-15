public class Solution {
    public bool isVowel(char ch){
        ch = char.ToLower(ch);
        return "aeiou".Contains(ch);
    }
    public bool IsValid(string word) {
        if(word.Length < 3)return false;
        bool v = false,c = false;
        foreach(char ch in word){
            if(!char.IsLetterOrDigit(ch))return false;
            if(char.IsLetter(ch)){
                if(isVowel(ch))v=true;
                else c = true;
            }
        }
        return (v&&c);
    }
}