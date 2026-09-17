class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()){
                    return false;
                }

                char top_element = st.top();
                if (c==')' && top_element != '(') return false;
                if (c==']' && top_element != '[') return false;
                if (c=='}' && top_element != '{') return false;

                st.pop();
            }
        }
        return st.empty();
    }
};
