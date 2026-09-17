class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int max_sum = 0;
        for(int right = 1;right<prices.size();right++){
            if(prices[left]>prices[right]){
                left=right;
            }
            else{
                int sum = prices[right]-prices[left];
                max_sum = max(sum,max_sum);

            }
            
        }
        return max_sum;
    }
};
