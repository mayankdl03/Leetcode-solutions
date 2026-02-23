class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    string result = "";
    int max_len = 0;
    for (int i = 0; i < s.size(); i++) {
        if (result.find(s[i]) != string::npos) {
            result = result.substr(result.find(s[i]) + 1);
        }
        result += s[i];
        if (result.size() > max_len) {
            max_len = result.size();
        }
    }
    return max_len;
}
};