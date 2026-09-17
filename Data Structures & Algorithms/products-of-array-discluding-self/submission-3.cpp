class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // The C++ Fast I/O Trick (Turns off synchronization for raw speed)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int> output(n,1);
        int left_product = 1;
        for(int i=0; i<n;i++){
            output[i]=left_product;
            left_product *= nums[i];
        }

        int right_product = 1;
        for (int i = n-1;i>=0;i--){
            output[i] *= right_product;
            right_product *= nums[i];
        }
        return output;
    }
};
