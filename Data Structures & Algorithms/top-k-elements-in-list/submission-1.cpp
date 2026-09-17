class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<int> op; // Declare your single output vector here
        
        // 1. Build the Tally Chart
        for (int num : nums) {
            freq[num]++;
        }
        
        // 2. Build the physical boxes (Buckets)
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto q : freq) {
            int number = q.first;
            int frequency = q.second;
            buckets[frequency].push_back(number);
        }
        
        // 3. Walk backwards and UNPACK the boxes
        for (int i = buckets.size() - 1; i >= 0; i--) {
            // Check every number sitting in this specific frequency box
            for (int num : buckets[i]) { 
                op.push_back(num); // Push the individual number, not the box!
                
                // If we've collected exactly 'k' elements, we are done
                if (op.size() == k) {
                    return op;
                }
            }
        }
        
        return op; // Fallback return statement to satisfy C++ requirements
    }
};