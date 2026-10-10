class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        // Step 1: Pair position and speed together so they don't get mixed up when sorted
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        
        // Step 2: Sort cars by their starting position in ASCENDING order 
        // (so cars closer to 0 are first, and cars closest to the target are last)
        sort(cars.begin(), cars.end());
        
        // Stack to store the travel times of the car fleets
        stack<double> st;
        
        // Step 3: Iterate from RIGHT to LEFT (starting from the car closest to the target)
        for (int i = n - 1; i >= 0; i--) {
            
            // Calculate exact travel time to the target (using double to avoid integer truncation)
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            // If the stack is empty, or this car takes LONGER than the car ahead of it,
            // it cannot catch up. It forms a brand-new fleet!
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // Otherwise, this car takes LESS or EQUAL time, meaning it catches up 
            // and merges into the fleet ahead of it. (We do nothing!)
        }
        
        // The total number of fleets is simply how many items are left in our stack
        return st.size();
    }
};