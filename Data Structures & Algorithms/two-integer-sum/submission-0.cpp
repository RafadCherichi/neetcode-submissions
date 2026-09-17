class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> dict;
        for (int i = 0;i<nums.size();i++){
            int p = nums[i];
            int q = target - p;
            if(dict.find(q)!=dict.end()){
                return {dict[q], i};
            }
            dict[p]=i;
        }
        return {};
    }
};
