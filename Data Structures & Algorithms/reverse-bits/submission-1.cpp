class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        // Since it's a 32-bit unsigned integer, we must loop exactly 32 times 
        // to preserve trailing and leading zeros.
        for (int i = 0; i < 32; i++) {
            
            // 1. Shift our result to the left to make space for the incoming bit
            result <<= 1;
            
            // 2. Extract the rightmost bit of 'n' (using n & 1) 
            // and slap it onto our result using bitwise OR (|)
            result |= (n & 1);
            
            // 3. Shift 'n' to the right to move on to the next bit
            n >>= 1;
        }

        return result;
    }
};