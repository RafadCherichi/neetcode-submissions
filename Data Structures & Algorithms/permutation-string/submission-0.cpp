class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if(len1>len2){
            return false;
        }

        vector<int> s1_count(26,0);
        vector<int> window_count(26,0);

        for(int i=0;i<len1;i++){
            s1_count[s1[i]-'a']++;
            window_count[s2[i]-'a']++;
        }

        if (s1_count==window_count){
            return true;
        }

        //slide window

        for(int i = len1; i<len2;i++){
            window_count[s2[i]-'a']++;
            window_count[s2[i-len1]-'a']--;

            if(s1_count == window_count){
                return true;
            }
        }

        return false;


    }
};
