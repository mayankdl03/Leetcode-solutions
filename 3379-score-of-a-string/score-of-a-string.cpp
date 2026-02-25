class Solution {
public:
    int scoreOfString(string s) {
        int addition=0;
        for(int i=0;i<s.size()-1;i++){
            addition+=abs(s[i]-s[i+1]);
        }
        return addition;
    }
};