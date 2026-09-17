class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_length = 0;
        std::unordered_map<char, int> subscount;
        for(int right = 0;right<s.size();right++){
            subscount[s[right]]++;
            while(subscount[s[right]]>1){
                subscount[s[left]]--;
                left++;
            }
            max_length = max(max_length,right-left+1);
        }
        return max_length;
    }
};
