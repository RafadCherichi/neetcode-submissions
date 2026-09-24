class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int p=0;
        for(int i=0;i<n;i++){
            p ^= nums[i];
        }

        return p;
    }
};
