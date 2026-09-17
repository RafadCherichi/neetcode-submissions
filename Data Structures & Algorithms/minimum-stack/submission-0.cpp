class MinStack {
private:
    stack<int> mainStack; // Holds all elements
    stack<int> minStack;  // Tracks the minimum at each level

public:
    MinStack() {
        // Constructor does not need anything special
    }
    
    void push(int val) {
        mainStack.push(val);
        
        // If minStack is empty, or val is smaller/equal to the current min, push it
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            // Otherwise, push the current minimum again so heights match
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop(); // Pop from both to keep them synchronized
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top(); // The top of minStack is always the global minimum!
    }
};