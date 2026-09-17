class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::unordered_map<int,std::vector<int>> map;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (j!=i){
                    map[i].push_back(nums[j]);
                }
            }
        }
        std::vector<int> op;
        for (int i = 0; i < nums.size(); i++) {
            int pdt = 1;
            
            // Go into our map, grab the vector for index 'i', and multiply them
            for (int num : map[i]) {
                pdt *= num;
            }
            
            op.push_back(pdt);
        }
        return op;
    }
};
