class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> alphabet(26);
        for(int i=0;i<s.length();i++){
            alphabet[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            alphabet[t[i]-'a']--;
        }
        for(auto it:alphabet){
            if(it>0)return false;
        }
        return true;
    }
};