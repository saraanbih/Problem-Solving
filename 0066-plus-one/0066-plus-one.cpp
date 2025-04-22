class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
          
    int carry = 1; // Start with 1 to add
    for (int i = digits.size() - 1; i >= 0; --i) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10; // Update the current digit
        carry = sum / 10;      // Carry for the next digit
    }
    
    // If there's still carry after the loop, add it as a new digit
    if (carry)
        digits.insert(digits.begin(), carry);
    
    return digits;

   
}};