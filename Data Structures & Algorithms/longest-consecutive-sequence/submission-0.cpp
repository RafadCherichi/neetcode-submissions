class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> yard(nums.begin(),nums.end());
        int longest_streak = 0;
        for (int num:yard){
            if (yard.find(num-1)==yard.end()){
                int current_num = num;
                int current_streak = 1;

                while (yard.find(current_num + 1)!=yard.end()){
                    current_num += 1;
                    current_streak += 1;
                }
                longest_streak = std::max(longest_streak,current_streak);
            }
        }
        return longest_streak;
    }
};
