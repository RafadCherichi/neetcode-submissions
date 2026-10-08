class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        // Result array initialized to 0s. 
        // If no warmer day ever comes, it stays 0.
        vector<int> result(n, 0);
        
        // Stack to store the INDICES of days we are still waiting to find a warmer temperature for.
        stack<int> st;

        for (int i = 0; i < n; i++) {
            
            // While the stack has pending days, and today's temperature is WARMER 
            // than the temperature on the day sitting at the top of our stack...
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                
                int past_index = st.top(); // Get the index of the past day
                st.pop();                  // Remove it from the stack since we resolved it
                
                // The number of days waited is the distance between today and that past day
                result[past_index] = i - past_index;
            }
            
            // Push today's index onto the stack so it can wait for a warmer day
            st.push(i);
        }

        return result;
    }
};