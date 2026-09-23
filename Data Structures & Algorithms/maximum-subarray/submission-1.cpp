class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // Edge case safety check
        if (nums.empty()) return 0;

        // current_sum tracks the running total of our current subarray journey.
        // We initialize it to the first element.
        int current_sum = nums[0];
        
        // max_sum tracks the absolute highest score we have ever recorded.
        // We also initialize it to the first element.
        int max_sum = nums[0];

        // Loop through the rest of the array starting from index 1
        for (int i = 1; i < nums.size(); i++) {
            
            // THE GREEDY CHOICE:
            // "Should I keep dragging along my old running sum, or is it so negative 
            // that I'm better off throwing it away and starting a brand-new subarray right here?"
            current_sum = max(nums[i], current_sum + nums[i]);
            
            // Record-keeping: Is our current journey beating our all-time best score?
            max_sum = max(max_sum, current_sum);
        }

        // Return the highest sum found anywhere in the array
        return max_sum;
    }
};