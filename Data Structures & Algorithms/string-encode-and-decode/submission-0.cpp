class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for (string s : strs){
            int num = s.size();
            encoded_str += to_string(num) + "#" + s;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        std::vector<string> decstr;
        int i = 0;

        while (i<s.size()){
            int j = i;

            while (s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));

            string word = s.substr(j+1,length);
            decstr.push_back(word);
            i = j + 1 + length;
        }
        return decstr;
    }
};
