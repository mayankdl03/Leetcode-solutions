class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alpha(26,0);
        for(int i=0;i<t.size();i++){
            alpha[t[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            alpha[s[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(alpha[i]==1)return (char)('a'+i);
        }
        return ' ';
    }
};