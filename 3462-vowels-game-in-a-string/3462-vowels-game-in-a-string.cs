public class Solution {
    public bool DoesAliceWin(string s) {
        return s.Any( c => "aeiou".Contains(c));
    }
}