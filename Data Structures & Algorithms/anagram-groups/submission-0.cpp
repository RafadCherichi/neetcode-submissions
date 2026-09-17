class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. The Post Office Sorting Desk (Your architecture is perfect)
        std::unordered_map<string, vector<string>> bins;
        std::vector<vector<string>> op; // Output vector
        
        // 2. C++ For-Loop Syntax with { }
        for (string str : strs) {
            string s = str;
            std::sort(s.begin(), s.end()); // Create the sorted signature
            bins[s].push_back(str);        // Toss original word into the correct bin
        }
        
        // 3. Manually extract the lists from the map into our final output vector
        for (auto pair : bins) {
            op.push_back(pair.second); 
        }
        
        return op;
    }
};