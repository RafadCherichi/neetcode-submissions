class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, int index) {

        if (index == nums.size()) {
            result.push_back(path);
            return;
        }

        // TAKE nums[index]
        path.push_back(nums[index]);
        backtrack(nums, index + 1);
        path.pop_back();

        // DON'T TAKE nums[index]
        backtrack(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(nums, 0);

        return result;
    }
};
