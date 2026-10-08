class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(st.empty()==false && temperatures[i]>temperatures[st.top()]){
                int past_index = st.top();
                st.pop();
                result[past_index]= i - past_index;
                

            }
            st.push(i);
        }
        return result;
    }
};
