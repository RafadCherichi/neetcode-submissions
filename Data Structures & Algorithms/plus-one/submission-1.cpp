class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Loop backward from the last digit to the first digit
        for (int i = n - 1; i >= 0; i--) {
            
            // Case 1: If the current digit is less than 9, just add 1 and we're done!
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // No more carries needed, exit immediately
            }
            
            // Case 2: If the digit is 9, it becomes 0 (and the loop continues left to carry the 1)
            digits[i] = 0;
        }

        // If the code reaches this point, it means EVERY digit was a 9 (e.g., [9, 9, 9] -> [0, 0, 0])
        // We need to add a 1 to the very front of the vector.
        digits.insert(digits.begin(), 1);

        return digits;
    }
};