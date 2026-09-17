class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_len = 0;
        int max_freq = 0;
        int count[26] = {0};

        for (int right = 0;right<s.size(); right++){
            int char_index = s[right] - 'A';
            count[char_index]++;

            max_freq = max(count[char_index], max_freq);

            if (k<(right-left+1) - max_freq){
                count[s[left]-'A']--;
                left++;
            }
            max_len = max(right-left+1,max_len);
        }
        return max_len;
    }
};
