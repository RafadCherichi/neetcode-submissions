class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique_val = 0;

        // Traverse through every number in the array
        for (int i = 0; i < nums.size(); i++) {
            // XOR the current number into our running result.
            // Duplicate numbers will cancel each other out (become 0),
            // leaving only the single unique number at the end.
            unique_val ^= nums[i];
        }

        return unique_val;
    }
};