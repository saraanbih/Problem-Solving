class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        // Traverse both strings from the end
        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? a[i] - '0' : 0; // Extract bit from 'a'
            int bit2 = (j >= 0) ? b[j] - '0' : 0; // Extract bit from 'b'

            int sum = bit1 + bit2 + carry;
            result = char((sum % 2) + '0') + result; // Append the current bit to the result
            carry = sum / 2; // Update the carry

            i--; j--; // Move to the previous bits
        }

        return result;
    }
};