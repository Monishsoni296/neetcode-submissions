class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &i: strs) {
            encoded += "#";
            encoded += to_string(i.size());
            encoded += "/";
            encoded += i;
        }
        return encoded;
    }

// #0#5World
    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i < s.size()) {
            int len = 0, j = i+1;
            while(j < s.size() && s[j] != '/') len = len * 10 + (s[j++] - '0');
            ans.push_back(s.substr(j+1, len));
            i = j + len + 1;
        }
        return ans;
    }
};
