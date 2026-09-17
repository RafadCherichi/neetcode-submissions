class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // 1. If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // 2. If it's a closing bracket, check if the stack is empty first
                if (st.empty()) {
                    return false;
                }

                // 3. Check if it matches the top of the stack
                char top_element = st.top();
                if (c == ')' && top_element != '(') return false;
                if (c == '}' && top_element != '{') return false;
                if (c == ']' && top_element != '[') return false;

                // 4. If it matches, pop the opening bracket off the stack
                st.pop();
            }
        }

        // 5. If the stack is empty, everything matched successfully!
        return st.empty();
    }
};