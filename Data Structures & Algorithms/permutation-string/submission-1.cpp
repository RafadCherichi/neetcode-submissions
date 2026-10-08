class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        // Edge case: If s1 is longer than s2, its permutation can never fit inside s2
        if (len1 > len2) {
            return false;
        }
        
        // Create frequency arrays for 26 lowercase English letters ('a' through 'z')
        // Index 0 represents 'a', Index 1 represents 'b', ..., Index 25 represents 'z'
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        // STEP 1: Populate frequencies for s1 and the very first window of s2
        for (int i = 0; i < len1; i++) {
            s1_count[s1[i] - 'a']++;       // Count character in s1
            window_count[s2[i] - 'a']++;   // Count character in the initial window of s2
        }
        
        // Check if the very first window happens to be a match
        if (s1_count == window_count) {
            return true;
        }
        
        // STEP 2: Slide the window one step to the right across the rest of s2
        for (int i = len1; i < len2; i++) {
            
            // 1. ADD the new character entering the window on the right side
            window_count[s2[i] - 'a']++;
            
            // 2. REMOVE the old character dropping off the left side of the window
            // (i - len1 points directly to the character leaving the window)
            window_count[s2[i - len1] - 'a']--;
            
            // 3. COMPARE: If the current window's frequencies match s1, we found our permutation!
            if (s1_count == window_count) {
                return true;
            }
        }
        
        // If we slide all the way to the end of s2 and find no match, return false
        return false;
    }
};