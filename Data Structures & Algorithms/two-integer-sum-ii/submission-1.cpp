class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while(left < right) {
            // Fix: Use numbers[left] and numbers[right] to get the values
            int sum = numbers[left] + numbers[right];
            
            if(sum < target) {
                left++;
            }
            else if(sum > target) {
                right--;
            }
            else {
                // Fix: 1-indexed means adding +1, and we return immediately to stop the loop
                return {left + 1, right + 1};
            }
        }
        
        // The problem guarantees exactly one solution, but good practice to return something
        return {}; 
    }
};