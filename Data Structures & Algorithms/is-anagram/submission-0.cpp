class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        std::unordered_map<char,int> s1;
        for (char str:s){
            s1[str]++;
        }
        std::unordered_map<char,int> s2;
        for (char str:t){
            s2[str]++;
        }
        return s1==s2;
    }
};
